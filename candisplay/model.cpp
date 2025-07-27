// This file is auto-generated from YAML definitions.
#include "model.h"
#include <iostream>
#include <iomanip>
void Model::process(uint16_t pid, uint64_t data){
	// PID: ["0x12"] - 
	if (pid == 0x12){
		// key_status - Key Status, Status
		key_status = (((data >> ( 64 - 0 - 8 )) & (uint64_t)(( 1 << 8 ) - 1)));
	}
	// PID: ["0x101"] - 
	if (pid == 0x101){
		// key_status_101 - Key Status, Status
		key_status_101 = (((data >> ( 64 - 0 - 8 )) & (uint64_t)(( 1 << 8 ) - 1)));
	}
	// PID: ["0x149"] - 
	if (pid == 0x149){
		// rotation_esc - Rotation ESC, N/A
		rotation_esc = (((data >> ( 64 - 32 - 16 )) & (uint64_t)(( 1 << 16 ) - 1)) * 0.030363757818667642) + -1000;
	}
	// PID: ["0x200"] - 
	if (pid == 0x200){
		// wheel_rotation_1 - Wheel Rotation One, N/A
		wheel_rotation_1 = (((data >> ( 64 - 15 - 12 )) & (uint64_t)(( 1 << 12 ) - 1)) * 0.34) + -1209;
		// wheel_rotation_2 - Wheel Rotation Two, N/A
		wheel_rotation_2 = (((data >> ( 64 - 25 - 14 )) & (uint64_t)(( 1 << 14 ) - 1)) * 0.01) + -71;
	}
	// PID: ["0x208"] - 
	if (pid == 0x208){
		// brake_pedal_position - Brake Pedal Position, N/A
		brake_pedal_position = (((data >> ( 64 - 16 - 12 )) & (uint64_t)(( 1 << 12 ) - 1)) * 0.5) + -766;
		// wheel_rotation_1_208 - Wheel Rotation One, N/A
		wheel_rotation_1_208 = (((data >> ( 64 - 32 - 16 )) & (uint64_t)(( 1 << 16 ) - 1)) * 0.01) + -27;
		// wheel_rotation_2_208 - Wheel Rotation Two, N/A
		wheel_rotation_2_208 = (((data >> ( 64 - 48 - 16 )) & (uint64_t)(( 1 << 16 ) - 1)) * 0.01) + -27;
	}
	// PID: ["0x210"] - 
	if (pid == 0x210){
		// accelerator_pedal_percentage - Accelerator Pedal Percentage, Percentage
		accelerator_pedal_percentage = (((data >> ( 64 - 16 - 7 )) & (uint64_t)(( 1 << 7 ) - 1)) * 0.4);
	}
	// PID: ["0x215"] - 
	if (pid == 0x215){
		// vehicle_speed - Vehicle Speed, km/h
		vehicle_speed = (((data >> ( 64 - 0 - 16 )) & (uint64_t)(( 1 << 16 ) - 1)) * 0.0078125);
	}
	// PID: ["0x231"] - 
	if (pid == 0x231){
		// brake_pedal_switch - Brake Pedal Switch Sensor, Status
		brake_pedal_switch = (((data >> ( 64 - 32 - 8 )) & (uint64_t)(( 1 << 8 ) - 1)));
	}
	// PID: ["0x285"] - 
	if (pid == 0x285){
		// acceleration - Acceleration, m/s^2
		acceleration = (((data >> ( 64 - 0 - 16 )) & (uint64_t)(( 1 << 16 ) - 1)) * 0.0025) + -5;
	}
	// PID: ["0x298"] - 
	if (pid == 0x298){
		// motor_temperature_1 - Motor Temp 1, C
		motor_temperature_1 = (((data >> ( 64 - 0 - 8 )) & (uint64_t)(( 1 << 8 ) - 1))) + -50;
		// motor_temperature_2 - Motor Temp 2, C
		motor_temperature_2 = (((data >> ( 64 - 8 - 8 )) & (uint64_t)(( 1 << 8 ) - 1))) + -50;
		// motor_temperature_3 - Motor Temp 3, C
		motor_temperature_3 = (((data >> ( 64 - 16 - 8 )) & (uint64_t)(( 1 << 8 ) - 1))) + -50;
		// motor_temperature_4 - Motor Temp 4, C
		motor_temperature_4 = (((data >> ( 64 - 24 - 8 )) & (uint64_t)(( 1 << 8 ) - 1))) + -50;
		// motor_rpm - Motor RPM, rpm
		motor_rpm = (((data >> ( 64 - 48 - 16 )) & (uint64_t)(( 1 << 16 ) - 1))) + -10000;
	}
	// PID: ["0x346"] - 
	if (pid == 0x346){
		// range_remaining - Range, Kilometers
		range_remaining = (((data >> ( 64 - 56 - 8 )) & (uint64_t)(( 1 << 8 ) - 1)));
	}
	// PID: ["0x373"] - 
	if (pid == 0x373){
		// cell_max_voltage - Battery Cell Maximum Voltage, Volts
		cell_max_voltage = (((data >> ( 64 - 0 - 8 )) & (uint64_t)(( 1 << 8 ) - 1)) * 0.01) + 2.1;
		// cell_min_voltage - Battery Cell Min Voltage, N/A
		cell_min_voltage = (((data >> ( 64 - 8 - 8 )) & (uint64_t)(( 1 << 8 ) - 1)) * 0.01) + 2.1;
		// battery_amps - Battery Pack Amps, Amps
		battery_amps = (((data >> ( 64 - 16 - 16 )) & (uint64_t)(( 1 << 16 ) - 1)) * 0.01) + -327.68;
		// battery_voltage - Battery Pack Voltage, Volts
		battery_voltage = (((data >> ( 64 - 32 - 16 )) & (uint64_t)(( 1 << 16 ) - 1)) * 0.1);
	}
	// PID: ["0x374"] - 
	if (pid == 0x374){
		// battery_soc_1 - Battery SOC 1, %
		battery_soc_1 = (((data >> ( 64 - 0 - 8 )) & (uint64_t)(( 1 << 8 ) - 1)) * 0.5) + -10;
		// battery_soc_2 - Battery SOC 2, %
		battery_soc_2 = (((data >> ( 64 - 0 - 8 )) & (uint64_t)(( 1 << 8 ) - 1)) * 0.5) + -10;
		// battery_max_cell_temperature - Battery Max Temp, C
		battery_max_cell_temperature = (((data >> ( 64 - 32 - 8 )) & (uint64_t)(( 1 << 8 ) - 1))) + -50;
		// battery_min_cell_temperature - Battery Min Temp, C
		battery_min_cell_temperature = (((data >> ( 64 - 40 - 8 )) & (uint64_t)(( 1 << 8 ) - 1))) + -50;
		// battery_full_capacity_ah - Battery 100% Capacity (Ah), Ah
		battery_full_capacity_ah = (((data >> ( 64 - 48 - 8 )) & (uint64_t)(( 1 << 8 ) - 1)) * 0.5);
	}
	// PID: ["0x384"] - 
	if (pid == 0x384){
		// air_conditioner_amps - AC (A), Amps
		air_conditioner_amps = (((data >> ( 64 - 0 - 16 )) & (uint64_t)(( 1 << 16 ) - 1)) * 0.001);
		// battery_12v_charge_amps - Charging 12v Battery (A), Amps
		battery_12v_charge_amps = (((data >> ( 64 - 24 - 8 )) & (uint64_t)(( 1 << 8 ) - 1)) * 0.01);
		// heater_amps - Heating (A), Amps
		heater_amps = (((data >> ( 64 - 32 - 8 )) & (uint64_t)(( 1 << 8 ) - 1)) * 0.1);
	}
	// PID: ["0x389"] - 
	if (pid == 0x389){
		// ac_charge_dc_volts - Charger DC Voltage(V), Volts
		ac_charge_dc_volts = (((data >> ( 64 - 0 - 8 )) & (uint64_t)(( 1 << 8 ) - 1)) * 2.01);
		// ac_charge_input_volts - Charger Input Voltage(V), Volts
		ac_charge_input_volts = (((data >> ( 64 - 8 - 8 )) & (uint64_t)(( 1 << 8 ) - 1)));
		// ac_charge_input_amps - Charger Input Current(A), Amps
		ac_charge_input_amps = (((data >> ( 64 - 16 - 8 )) & (uint64_t)(( 1 << 8 ) - 1)) * 0.1);
		// ac_charge_temperature_d3 - Charger Temp D3, C
		ac_charge_temperature_d3 = (((data >> ( 64 - 24 - 8 )) & (uint64_t)(( 1 << 8 ) - 1))) + -50;
		// ac_charge_temperature_d4 - Charger Temp D4, C
		ac_charge_temperature_d4 = (((data >> ( 64 - 32 - 8 )) & (uint64_t)(( 1 << 8 ) - 1))) + -50;
		// ac_charge_input_amps_2 - Charging Input Current(A), Amps
		ac_charge_input_amps_2 = (((data >> ( 64 - 48 - 8 )) & (uint64_t)(( 1 << 8 ) - 1)) * 0.1);
	}
	// PID: ["0x3a4"] - 
	if (pid == 0x3a4){
		// hvac_heating_level - Heating Level, Status
		hvac_heating_level = (((data >> ( 64 - 0 - 3 )) & (uint64_t)(( 1 << 3 ) - 1)));
		// hvac_max_button - MAX Button, Status
		hvac_max_button = (((data >> ( 64 - 5 - 1 )) & (uint64_t)(( 1 << 1 ) - 1)));
		// hvac_recircluation_button - Recirculation Button, Status
		hvac_recircluation_button = (((data >> ( 64 - 6 - 1 )) & (uint64_t)(( 1 << 1 ) - 1)));
		// hvac_ac_button - AC Button, Status
		hvac_ac_button = (((data >> ( 64 - 7 - 1 )) & (uint64_t)(( 1 << 1 ) - 1)));
		// hvac_fan_speed - Fan Speed, Fan Speed
		hvac_fan_speed = (((data >> ( 64 - 8 - 3 )) & (uint64_t)(( 1 << 3 ) - 1)) * 12.5);
		// hvac_vent_direction - Vent Direction, Vent Direction
		hvac_vent_direction = (((data >> ( 64 - 12 - 4 )) & (uint64_t)(( 1 << 4 ) - 1)));
	}
	// PID: ["0x412"] - 
	if (pid == 0x412){
		// key_status_412 - Key Status, N/A
		key_status_412 = (((data >> ( 64 - 0 - 8 )) & (uint64_t)(( 1 << 8 ) - 1)));
		switch (key_status_412) {
			case 254: key_status_412_status = "On"; break;
			case 0: key_status_412_status = "Off"; break;
			default: key_status_412_status = "Unknown";
		}
		// vehicle_speed_412 - Speed, Km/h
		vehicle_speed_412 = (((data >> ( 64 - 8 - 8 )) & (uint64_t)(( 1 << 8 ) - 1)));
		// odometer - Odometer, km
		odometer = (((data >> ( 64 - 16 - 24 )) & (uint64_t)(( 1 << 24 ) - 1)));
	}
	// PID: ["0x418"] - 
	if (pid == 0x418){
		// gear_shift_selection - Gear Shift Selection, N/A
		gear_shift_selection = (((data >> ( 64 - 0 - 8 )) & (uint64_t)(( 1 << 8 ) - 1)));
		switch (gear_shift_selection) {
			case 255: gear_shift_selection_status = "Key Off"; break;
			case 131: gear_shift_selection_status = "B"; break;
			case 82: gear_shift_selection_status = "Reverse"; break;
			case 80: gear_shift_selection_status = "Park"; break;
			case 78: gear_shift_selection_status = "Neutral"; break;
			case 68: gear_shift_selection_status = "Drive"; break;
			case 50: gear_shift_selection_status = "C"; break;
			default: gear_shift_selection_status = "Unknown";
		}
	}
	// PID: ["0x424"] - 
	if (pid == 0x424){
		// lights_automatic - Automatic Light, N/A
		lights_automatic = (((data >> ( 64 - 2 - 1 )) & (uint64_t)(( 1 << 1 ) - 1)));
		switch (lights_automatic) {
			case 1: lights_automatic_status = "On"; break;
			case 0: lights_automatic_status = "Off"; break;
			default: lights_automatic_status = "Unknown";
		}
		// lights_fog - Fog Lights, N/A
		lights_fog = (((data >> ( 64 - 3 - 1 )) & (uint64_t)(( 1 << 1 ) - 1)));
		switch (lights_fog) {
			case 1: lights_fog_status = "On"; break;
			case 0: lights_fog_status = "Off"; break;
			default: lights_fog_status = "Unknown";
		}
		// lights_fog_rear - Rear Fog Light, N/A
		lights_fog_rear = (((data >> ( 64 - 4 - 1 )) & (uint64_t)(( 1 << 1 ) - 1)));
		switch (lights_fog_rear) {
			case 1: lights_fog_rear_status = "On"; break;
			case 0: lights_fog_rear_status = "Off"; break;
			default: lights_fog_rear_status = "Unknown";
		}
		// lights_hazard - Hazard Lights, N/A
		lights_hazard = (((data >> ( 64 - 8 - 1 )) & (uint64_t)(( 1 << 1 ) - 1)));
		switch (lights_hazard) {
			case 1: lights_hazard_status = "On"; break;
			case 0: lights_hazard_status = "Off"; break;
			default: lights_hazard_status = "Unknown";
		}
		// lights_right_blinker - Right Blinker, N/A
		lights_right_blinker = (((data >> ( 64 - 9 - 1 )) & (uint64_t)(( 1 << 1 ) - 1)));
		switch (lights_right_blinker) {
			case 1: lights_right_blinker_status = "On"; break;
			case 0: lights_right_blinker_status = "Off"; break;
			default: lights_right_blinker_status = "Unknown";
		}
		// lights_high_beam - High Beams, N/A
		lights_high_beam = (((data >> ( 64 - 10 - 1 )) & (uint64_t)(( 1 << 1 ) - 1)));
		switch (lights_high_beam) {
			case 1: lights_high_beam_status = "On"; break;
			case 0: lights_high_beam_status = "Off"; break;
			default: lights_high_beam_status = "Unknown";
		}
		// wipers_rear - Rear Wiper, N/A
		wipers_rear = (((data >> ( 64 - 11 - 1 )) & (uint64_t)(( 1 << 1 ) - 1)));
		switch (wipers_rear) {
			case 1: wipers_rear_status = "On"; break;
			case 0: wipers_rear_status = "Off"; break;
			default: wipers_rear_status = "Unknown";
		}
		// lights_night_headlights - Night Headlights, N/A
		lights_night_headlights = (((data >> ( 64 - 12 - 1 )) & (uint64_t)(( 1 << 1 ) - 1)));
		switch (lights_night_headlights) {
			case 1: lights_night_headlights_status = "On"; break;
			case 0: lights_night_headlights_status = "Off"; break;
			default: lights_night_headlights_status = "Unknown";
		}
		// lights_sidelights - Sidelights, N/A
		lights_sidelights = (((data >> ( 64 - 13 - 1 )) & (uint64_t)(( 1 << 1 ) - 1)));
		switch (lights_sidelights) {
			case 1: lights_sidelights_status = "On"; break;
			case 0: lights_sidelights_status = "Off"; break;
			default: lights_sidelights_status = "Unknown";
		}
		// doors_all_unlocked - All doors Unlocked, N/A
		doors_all_unlocked = (((data >> ( 64 - 16 - 1 )) & (uint64_t)(( 1 << 1 ) - 1)));
		switch (doors_all_unlocked) {
			case 1: doors_all_unlocked_status = "Unlocked"; break;
			case 0: doors_all_unlocked_status = "Locked"; break;
			default: doors_all_unlocked_status = "Unknown";
		}
		// doors_driver_unlocked - Driver Door Unlocked, N/A
		doors_driver_unlocked = (((data >> ( 64 - 17 - 1 )) & (uint64_t)(( 1 << 1 ) - 1)));
		switch (doors_driver_unlocked) {
			case 1: doors_driver_unlocked_status = "Unlocked"; break;
			case 0: doors_driver_unlocked_status = "Locked"; break;
			default: doors_driver_unlocked_status = "Unknown";
		}
		// doors_driver_unlocked_2 - Driver Door Unlocked, N/A
		doors_driver_unlocked_2 = (((data >> ( 64 - 51 - 1 )) & (uint64_t)(( 1 << 1 ) - 1)));
		switch (doors_driver_unlocked_2) {
			case 1: doors_driver_unlocked_2_status = "On"; break;
			case 0: doors_driver_unlocked_2_status = "Off"; break;
			default: doors_driver_unlocked_2_status = "Unknown";
		}
	}
	// PID: ["0x696"] - 
	if (pid == 0x696){
		// motor_current_amps - Motor Current Amps, Amps
		motor_current_amps = (((data >> ( 64 - 16 - 16 )) & (uint64_t)(( 1 << 16 ) - 1)) * 0.05) + -25;
		// motor_regen_amps - Regen Amps, Amps
		motor_regen_amps = (((data >> ( 64 - 48 - 15 )) & (uint64_t)(( 1 << 15 ) - 1)) * 0.11) + -553;
	}
	// PID: ["0x697"] - 
	if (pid == 0x697){
		// chademo_connected - Chademo Connected, N/A
		chademo_connected = (((data >> ( 64 - 0 - 8 )) & (uint64_t)(( 1 << 8 ) - 1)));
		// chademo_charge_percent - Chademo Charge %, Percentage
		chademo_charge_percent = (((data >> ( 64 - 8 - 8 )) & (uint64_t)(( 1 << 8 ) - 1)));
		// chademo_charge_amps - Chademo Current, AMPs
		chademo_charge_amps = (((data >> ( 64 - 16 - 8 )) & (uint64_t)(( 1 << 8 ) - 1)));
	}
	// PID: ["0x6e1", "0x6e2", "0x6e3", "0x6e4"] - 
	if (pid == 0x6e1 || pid == 0x6e2 || pid == 0x6e3 || pid == 0x6e4){
		// cell_voltages - Cell Voltages, Volts
		auto cell_voltages_index = (((data >> ( 64 - 0 - 8 )) & (uint64_t)(( 1 << 8 ) - 1)));
		// cell_temperatures - Cell Temperatures, C
		auto cell_temperatures_index = (((data >> ( 64 - 0 - 8 )) & (uint64_t)(( 1 << 8 ) - 1)));
		// cell_voltage_1 - Cell Voltage 1, Volts
		auto cell_voltage_1 = (((data >> ( 64 - 32 - 16 )) & (uint64_t)(( 1 << 16 ) - 1)) * 0.005) + 2.1;
		{
			auto i = (cell_voltages_index - 1) * 8 + (pid - 0x6e1) * 2;
			cell_voltages[i] = cell_voltage_1;
		}
		// cell_voltage_2 - Cell Voltage 2, Volts
		auto cell_voltage_2 = (((data >> ( 64 - 48 - 16 )) & (uint64_t)(( 1 << 16 ) - 1)) * 0.005) + 2.1;
		{
			auto i = (cell_voltages_index - 1) * 8 + (pid - 0x6e1) * 2 + 1;
			cell_voltages[i] = cell_voltage_2;
		}
		// cell_temp_1 - Cell Temperature 1, C
		auto cell_temp_1 = (((data >> ( 64 - 8 - 8 )) & (uint64_t)(( 1 << 8 ) - 1))) + -50;
		{
			auto i = (cell_temperatures_index - 1) * 8 + (pid - 0x6e1) * 2;
			cell_temperatures[i] = cell_temp_1;
		}
		// cell_temp_2 - Cell Temperature 2, C
		auto cell_temp_2 = (((data >> ( 64 - 16 - 8 )) & (uint64_t)(( 1 << 8 ) - 1))) + -50;
		{
			auto i = (cell_temperatures_index - 1) * 8 + (pid - 0x6e1) * 2 + 1;
			cell_temperatures[i] = cell_temp_2;
		}
	}
}
void Model::dump(){
	std::cout << std::left << std::setw(35) << "AC (A): " << std::right<< std::setw(10) << air_conditioner_amps << " Amps" << std::endl;
	std::cout << std::left << std::setw(35) << "AC Button: " << std::right<< std::setw(10) << hvac_ac_button << " Status" << std::endl;
	std::cout << std::left << std::setw(35) << "Acceleration: " << std::right<< std::setw(10) << acceleration << " m/s^2" << std::endl;
	std::cout << std::left << std::setw(35) << "Accelerator Pedal Percentage: " << std::right<< std::setw(10) << accelerator_pedal_percentage << " Percentage" << std::endl;
	std::cout << std::left << std::setw(35) << "All doors Unlocked: " << std::right<< std::setw(10) << doors_all_unlocked_status << " " << std::endl;
	std::cout << std::left << std::setw(35) << "Automatic Light: " << std::right<< std::setw(10) << lights_automatic_status << " " << std::endl;
	std::cout << std::left << std::setw(35) << "Battery 100% Capacity (Ah): " << std::right<< std::setw(10) << battery_full_capacity_ah << " Ah" << std::endl;
	std::cout << std::left << std::setw(35) << "Battery Cell Maximum Voltage: " << std::right<< std::setw(10) << cell_max_voltage << " Volts" << std::endl;
	std::cout << std::left << std::setw(35) << "Battery Cell Min Voltage: " << std::right<< std::setw(10) << cell_min_voltage << " " << std::endl;
	std::cout << std::left << std::setw(35) << "Battery Max Temp: " << std::right<< std::setw(10) << battery_max_cell_temperature << " C" << std::endl;
	std::cout << std::left << std::setw(35) << "Battery Min Temp: " << std::right<< std::setw(10) << battery_min_cell_temperature << " C" << std::endl;
	std::cout << std::left << std::setw(35) << "Battery Pack Amps: " << std::right<< std::setw(10) << battery_amps << " Amps" << std::endl;
	std::cout << std::left << std::setw(35) << "Battery Pack Voltage: " << std::right<< std::setw(10) << battery_voltage << " Volts" << std::endl;
	std::cout << std::left << std::setw(35) << "Battery SOC 1: " << std::right<< std::setw(10) << battery_soc_1 << " %" << std::endl;
	std::cout << std::left << std::setw(35) << "Battery SOC 2: " << std::right<< std::setw(10) << battery_soc_2 << " %" << std::endl;
	std::cout << std::left << std::setw(35) << "Brake Pedal Position: " << std::right<< std::setw(10) << brake_pedal_position << " " << std::endl;
	std::cout << std::left << std::setw(35) << "Brake Pedal Switch Sensor: " << std::right<< std::setw(10) << brake_pedal_switch << " Status" << std::endl;
	std::cout << std::left << std::setw(35) << "Cell Temperatures: " << std::right<< std::setw(10);
	for(auto i = 0; i < 96; i++){ std::cout << cell_temperatures[i] << " " ; }
	std::cout << std::endl;
	std::cout << std::left << std::setw(35) << "Cell Voltages: " << std::right<< std::setw(10);
	for(auto i = 0; i < 96; i++){ std::cout << cell_voltages[i] << " " ; }
	std::cout << std::endl;
	std::cout << std::left << std::setw(35) << "Chademo Charge %: " << std::right<< std::setw(10) << chademo_charge_percent << " Percentage" << std::endl;
	std::cout << std::left << std::setw(35) << "Chademo Connected: " << std::right<< std::setw(10) << chademo_connected << " " << std::endl;
	std::cout << std::left << std::setw(35) << "Chademo Current: " << std::right<< std::setw(10) << chademo_charge_amps << " AMPs" << std::endl;
	std::cout << std::left << std::setw(35) << "Charger DC Voltage(V): " << std::right<< std::setw(10) << ac_charge_dc_volts << " Volts" << std::endl;
	std::cout << std::left << std::setw(35) << "Charger Input Current(A): " << std::right<< std::setw(10) << ac_charge_input_amps << " Amps" << std::endl;
	std::cout << std::left << std::setw(35) << "Charger Input Voltage(V): " << std::right<< std::setw(10) << ac_charge_input_volts << " Volts" << std::endl;
	std::cout << std::left << std::setw(35) << "Charger Temp D3: " << std::right<< std::setw(10) << ac_charge_temperature_d3 << " C" << std::endl;
	std::cout << std::left << std::setw(35) << "Charger Temp D4: " << std::right<< std::setw(10) << ac_charge_temperature_d4 << " C" << std::endl;
	std::cout << std::left << std::setw(35) << "Charging 12v Battery (A): " << std::right<< std::setw(10) << battery_12v_charge_amps << " Amps" << std::endl;
	std::cout << std::left << std::setw(35) << "Charging Input Current(A): " << std::right<< std::setw(10) << ac_charge_input_amps_2 << " Amps" << std::endl;
	std::cout << std::left << std::setw(35) << "Driver Door Unlocked: " << std::right<< std::setw(10) << doors_driver_unlocked_status << " " << std::endl;
	std::cout << std::left << std::setw(35) << "Driver Door Unlocked: " << std::right<< std::setw(10) << doors_driver_unlocked_2_status << " " << std::endl;
	std::cout << std::left << std::setw(35) << "Fan Speed: " << std::right<< std::setw(10) << hvac_fan_speed << " Fan Speed" << std::endl;
	std::cout << std::left << std::setw(35) << "Fog Lights: " << std::right<< std::setw(10) << lights_fog_status << " " << std::endl;
	std::cout << std::left << std::setw(35) << "Gear Shift Selection: " << std::right<< std::setw(10) << gear_shift_selection_status << " " << std::endl;
	std::cout << std::left << std::setw(35) << "Hazard Lights: " << std::right<< std::setw(10) << lights_hazard_status << " " << std::endl;
	std::cout << std::left << std::setw(35) << "Heating (A): " << std::right<< std::setw(10) << heater_amps << " Amps" << std::endl;
	std::cout << std::left << std::setw(35) << "Heating Level: " << std::right<< std::setw(10) << hvac_heating_level << " Status" << std::endl;
	std::cout << std::left << std::setw(35) << "High Beams: " << std::right<< std::setw(10) << lights_high_beam_status << " " << std::endl;
	std::cout << std::left << std::setw(35) << "Key Status: " << std::right<< std::setw(10) << key_status << " Status" << std::endl;
	std::cout << std::left << std::setw(35) << "Key Status: " << std::right<< std::setw(10) << key_status_101 << " Status" << std::endl;
	std::cout << std::left << std::setw(35) << "Key Status: " << std::right<< std::setw(10) << key_status_412_status << " " << std::endl;
	std::cout << std::left << std::setw(35) << "MAX Button: " << std::right<< std::setw(10) << hvac_max_button << " Status" << std::endl;
	std::cout << std::left << std::setw(35) << "Motor Current Amps: " << std::right<< std::setw(10) << motor_current_amps << " Amps" << std::endl;
	std::cout << std::left << std::setw(35) << "Motor RPM: " << std::right<< std::setw(10) << motor_rpm << " rpm" << std::endl;
	std::cout << std::left << std::setw(35) << "Motor Temp 1: " << std::right<< std::setw(10) << motor_temperature_1 << " C" << std::endl;
	std::cout << std::left << std::setw(35) << "Motor Temp 2: " << std::right<< std::setw(10) << motor_temperature_2 << " C" << std::endl;
	std::cout << std::left << std::setw(35) << "Motor Temp 3: " << std::right<< std::setw(10) << motor_temperature_3 << " C" << std::endl;
	std::cout << std::left << std::setw(35) << "Motor Temp 4: " << std::right<< std::setw(10) << motor_temperature_4 << " C" << std::endl;
	std::cout << std::left << std::setw(35) << "Night Headlights: " << std::right<< std::setw(10) << lights_night_headlights_status << " " << std::endl;
	std::cout << std::left << std::setw(35) << "Odometer: " << std::right<< std::setw(10) << odometer << " km" << std::endl;
	std::cout << std::left << std::setw(35) << "Range: " << std::right<< std::setw(10) << range_remaining << " Kilometers" << std::endl;
	std::cout << std::left << std::setw(35) << "Rear Fog Light: " << std::right<< std::setw(10) << lights_fog_rear_status << " " << std::endl;
	std::cout << std::left << std::setw(35) << "Rear Wiper: " << std::right<< std::setw(10) << wipers_rear_status << " " << std::endl;
	std::cout << std::left << std::setw(35) << "Recirculation Button: " << std::right<< std::setw(10) << hvac_recircluation_button << " Status" << std::endl;
	std::cout << std::left << std::setw(35) << "Regen Amps: " << std::right<< std::setw(10) << motor_regen_amps << " Amps" << std::endl;
	std::cout << std::left << std::setw(35) << "Right Blinker: " << std::right<< std::setw(10) << lights_right_blinker_status << " " << std::endl;
	std::cout << std::left << std::setw(35) << "Rotation ESC: " << std::right<< std::setw(10) << rotation_esc << " " << std::endl;
	std::cout << std::left << std::setw(35) << "Sidelights: " << std::right<< std::setw(10) << lights_sidelights_status << " " << std::endl;
	std::cout << std::left << std::setw(35) << "Speed: " << std::right<< std::setw(10) << vehicle_speed_412 << " Km/h" << std::endl;
	std::cout << std::left << std::setw(35) << "Vehicle Speed: " << std::right<< std::setw(10) << vehicle_speed << " km/h" << std::endl;
	std::cout << std::left << std::setw(35) << "Vent Direction: " << std::right<< std::setw(10) << hvac_vent_direction << " Vent Direction" << std::endl;
	std::cout << std::left << std::setw(35) << "Wheel Rotation One: " << std::right<< std::setw(10) << wheel_rotation_1 << " " << std::endl;
	std::cout << std::left << std::setw(35) << "Wheel Rotation One: " << std::right<< std::setw(10) << wheel_rotation_1_208 << " " << std::endl;
	std::cout << std::left << std::setw(35) << "Wheel Rotation Two: " << std::right<< std::setw(10) << wheel_rotation_2 << " " << std::endl;
	std::cout << std::left << std::setw(35) << "Wheel Rotation Two: " << std::right<< std::setw(10) << wheel_rotation_2_208 << " " << std::endl;
}
