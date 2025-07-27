#!/usr/bin/env ruby
# frozen_string_literal: true

require 'yaml'
require 'optparse'
require 'stringio'


# -----------------------------------------------------------
def datatype(data, variable_name)
    factor = data['factor'] 
    is_float = data['is_float'].to_s.downcase == 'true'
    size = data['size'] || 0
    sign = data['is_signed'].to_s.downcase == 'true' ? '' : 'u'
    array_size = data['array_size']
    type =
        if factor.to_f != factor.to_i || is_float
          "float"
        elsif size > 31
          "#{sign}int64_t"
        elsif size > 15
          "#{sign}int32_t"
        elsif size > 7
          "#{sign}int16_t"
        else
          "#{sign}int8_t"
        end
    type += ' ' + variable_name
    type += "[#{array_size}]" if array_size
    type
end


# yaml_data is a hash where keys are file names and values are hashes
# The hash data has keys of the item name, the values are a has of the item properties
def generate_header(yaml_data)
    header = StringIO.new
    header.puts <<~STDCHEADER
    // This file is auto-generated from YAML definitions.
    #ifndef MODEL_H
    #define MODEL_H

    #include <stdint.h>
    #include <string>
    class Model{
      public:
        bool operator==(const Model&) const = default;
        void process(uint16_t pid, uint64_t data);
        void dump();
        size_t pids_processed_this_update = 0;
        void start_update(){pids_processed_this_update = 0;};
    STDCHEADER
    yaml_data.each do |file, data|
        header.puts "// File: #{file} - #{data['Frame']['description']}"
        data.each do |variable_name, item_data|
            next if variable_name == 'Frame' # skip "Frame" item
            next if item_data['member_of'] # skip values that are elements of arrays
            declaration = datatype(item_data, variable_name)
            name = item_data['name']
            unit = item_data['unit'] || 'N/A'
            header.puts "    #{declaration};     //#{name} - #{unit}"
            if item_data['status']
                header.puts "    std::string #{variable_name}_status; //#{name} status"
            end
        end
    end
    
    header.puts <<~STDCHEADER
    };
    #endif // MODEL_H
    STDCHEADER
    header.string
end

def generate_implementation(yaml_data)
    implementation = StringIO.new
    implementation.puts <<~CIMPLEMENTATION
    // This file is auto-generated from YAML definitions.
    #include "model.h"
    #include <iostream>
    #include <iomanip>
    CIMPLEMENTATION
    generate_implementation_process(yaml_data, implementation)
    generate_implementation_dump(yaml_data, implementation)
    implementation.string
end

def value_expression(item)
    factor = item['factor'] || 1.0
    offset = item['offset'] || 0.0
    start_bit = item['start_bit'] || 0
    size = item['size'] || 0
    expr = "(((data >> ( 64 - #{start_bit} - #{size} )) & (uint64_t)(( 1 << #{size} ) - 1))"
    expr += " * #{factor}" if factor != 1
    expr += ")"
    expr += " + #{offset}" if offset != 0
    expr
end

def generate_implementation_process (yaml_data, implementation)
    implementation.puts "void Model::process(uint16_t pid, uint64_t data){"
    yaml_data.each do |filename, data|
        data.each do |item_name, item_data|
            if item_name == 'Frame'
                pids = Array(item_data['arbitration_id']).map{|x| '0x' + x.to_s(16)}
                condition = pids.join(' || pid == ')
                implementation.puts <<~PIDHEADER
                \t// PID: #{pids} - #{data['description']}
                \tif (pid == #{condition}){
                \t\tpids_processed_this_update++;
                PIDHEADER
            else
                name = item_data['name']
                unit = item_data['unit'] || 'N/A'
                value = value_expression(item_data)
                type = item_data['member_of'] ? 'auto ' : ''
                implementation.puts "\t\t// #{item_name} - #{name}, #{unit}"
                if item_data['array_size']
                    index_expr = value_expression(item_data['array_index'])
                    implementation.puts "\t\tauto #{item_name}_index = #{index_expr};"

                else
                    implementation.puts "\t\t#{type}#{item_name} = #{value};"
                    member_of = item_data['member_of']
                    if member_of
                        implementation.puts "\t\t{"
                        implementation.puts "\t\t\tauto i = #{item_data['index']};"
                        implementation.puts "\t\t\t#{member_of}[i] = #{item_name};"
                        implementation.puts "\t\t}"
                    end
                end
                if item_data['status']
                    implementation.puts "\t\tswitch (#{item_name}) {"
                    item_data['status'].each do |value, status|
                        implementation.puts "\t\t\tcase #{value}: #{item_name}_status = \"#{status}\"; break;"
                    end
                    implementation.puts "\t\t\tdefault: #{item_name}_status = \"Unknown\";"
                    implementation.puts "\t\t}"
                end
        
            end
        end
        implementation.puts "\t}"
    end
    implementation.puts "}"
end

def generate_implementation_dump (yaml_data, implementation)
    implementation.puts "void Model::dump(){"
    all_items_by_variable = {}
    yaml_data.each do |pid, data|
        data.each do |item_name, item_data|
            next if item_name == 'Frame'
            next if item_data['member_of']
            all_items_by_variable[item_name] = item_data
        end
    end
    # generate map of item names to their data
    sorted_names = all_items_by_variable.map{|k,v| [v['name'],k]}.sort

    sorted_names.each do |name, variable|
        item_data = all_items_by_variable[variable]
        #name = item_data['name']
        unit = item_data['unit'] || ''
        if item_data['status']
            variable = "#{variable}_status"
        end
        array_size = item_data['array_size']
        if array_size
            implementation.puts "\tstd::cout << std::left << std::setw(35) << \"#{name}: \" << std::right<< std::setw(10);"
            implementation.puts("\tfor(auto i = 0; i < #{array_size}; i++){ std::cout << #{variable}[i] << \" \" ; }")
            implementation.puts("\tstd::cout << std::endl;")
        else
            implementation.puts "\tstd::cout << std::left << std::setw(35) << \"#{name}: \" << std::right<< std::setw(10) << #{variable} << \" #{unit}\" << std::endl;"
        end
    end
    implementation.puts "}"
end


# -----------------------------------------------------------

options = {}

OptionParser.new do |opts|
  opts.banner = "Usage: generate-model.rb --input INPUT_DIR --output OUTPUT_DIR"

  opts.on("-i", "--input INPUT_DIR", "Input directory to process") do |input|
    options[:input] = input
  end

  opts.on("-o", "--output OUTPUT_DIR", "Output directory to write to") do |output|
    options[:output] = output
  end
end.parse!

if options[:input].nil? || options[:output].nil?
  puts "Both --input and --output parameters are required."
  exit 1
end

input_dir =  options[:input]
output_dir = options[:output]

puts "Input directory: #{input_dir}"
puts "Output directory: #{output_dir}"

yaml_data = {}
Dir.glob(File.join(input_dir, 'pid-defs', '*.yaml')).each do |filename|
    key = File.basename(filename)
    yaml_data[key] = YAML.load_file(filename)
end

header = generate_header(yaml_data)
File.open(File.join(output_dir, 'model.h'), 'w') do |file|
    file.write(header)
end

implementation = generate_implementation(yaml_data)
File.open(File.join(output_dir, 'model.cpp'), 'w') do |file|
    file.write(implementation)
end

exit 0
