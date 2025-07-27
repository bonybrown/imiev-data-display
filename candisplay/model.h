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
// File: 0x012.yaml - 
    uint16_t key_status;     //Key Status - Status
// File: 0x101.yaml - 
    uint16_t key_status_101;     //Key Status - Status
// File: 0x149.yaml - 
    float rotation_esc;     //Rotation ESC - N/A
// File: 0x200.yaml - 
    float wheel_rotation_1;     //Wheel Rotation One - N/A
    float wheel_rotation_2;     //Wheel Rotation Two - N/A
// File: 0x208.yaml - 
    float brake_pedal_position;     //Brake Pedal Position - N/A
    float wheel_rotation_1_208;     //Wheel Rotation One - N/A
    float wheel_rotation_2_208;     //Wheel Rotation Two - N/A
// File: 0x210.yaml - 
    float accelerator_pedal_percentage;     //Accelerator Pedal Percentage - Percentage
// File: 0x215.yaml - 
    float vehicle_speed;     //Vehicle Speed - km/h
// File: 0x231.yaml - 
    uint16_t brake_pedal_switch;     //Brake Pedal Switch Sensor - Status
// File: 0x285.yaml - 
    float acceleration;     //Acceleration - m/s^2
// File: 0x298.yaml - 
    uint16_t motor_temperature_1;     //Motor Temp 1 - C
    uint16_t motor_temperature_2;     //Motor Temp 2 - C
    uint16_t motor_temperature_3;     //Motor Temp 3 - C
    uint16_t motor_temperature_4;     //Motor Temp 4 - C
    int32_t motor_rpm;     //Motor RPM - rpm
// File: 0x346.yaml - 
    uint16_t range_remaining;     //Range - Kilometers
// File: 0x373.yaml - 
    float cell_max_voltage;     //Battery Cell Maximum Voltage - Volts
    float cell_min_voltage;     //Battery Cell Min Voltage - N/A
    float battery_amps;     //Battery Pack Amps - Amps
    float battery_voltage;     //Battery Pack Voltage - Volts
// File: 0x374.yaml - 
    float battery_soc_1;     //Battery SOC 1 - %
    float battery_soc_2;     //Battery SOC 2 - %
    uint16_t battery_max_cell_temperature;     //Battery Max Temp - C
    uint16_t battery_min_cell_temperature;     //Battery Min Temp - C
    float battery_full_capacity_ah;     //Battery 100% Capacity (Ah) - Ah
// File: 0x384.yaml - 
    float air_conditioner_amps;     //AC (A) - Amps
    float battery_12v_charge_amps;     //Charging 12v Battery (A) - Amps
    float heater_amps;     //Heating (A) - Amps
// File: 0x389.yaml - 
    float ac_charge_dc_volts;     //Charger DC Voltage(V) - Volts
    uint16_t ac_charge_input_volts;     //Charger Input Voltage(V) - Volts
    float ac_charge_input_amps;     //Charger Input Current(A) - Amps
    uint16_t ac_charge_temperature_d3;     //Charger Temp D3 - C
    uint16_t ac_charge_temperature_d4;     //Charger Temp D4 - C
    float ac_charge_input_amps_2;     //Charging Input Current(A) - Amps
// File: 0x3A4.yaml - 
    uint8_t hvac_heating_level;     //Heating Level - Status
    uint8_t hvac_max_button;     //MAX Button - Status
    uint8_t hvac_recircluation_button;     //Recirculation Button - Status
    uint8_t hvac_ac_button;     //AC Button - Status
    float hvac_fan_speed;     //Fan Speed - Fan Speed
    uint8_t hvac_vent_direction;     //Vent Direction - Vent Direction
// File: 0x412.yaml - 
    uint16_t key_status_412;     //Key Status - N/A
    std::string key_status_412_status; //Key Status status
    uint16_t vehicle_speed_412;     //Speed - Km/h
    uint32_t odometer;     //Odometer - km
// File: 0x418.yaml - 
    uint16_t gear_shift_selection;     //Gear Shift Selection - N/A
    std::string gear_shift_selection_status; //Gear Shift Selection status
// File: 0x424.yaml - 
    uint8_t lights_automatic;     //Automatic Light - N/A
    std::string lights_automatic_status; //Automatic Light status
    uint8_t lights_fog;     //Fog Lights - N/A
    std::string lights_fog_status; //Fog Lights status
    uint8_t lights_fog_rear;     //Rear Fog Light - N/A
    std::string lights_fog_rear_status; //Rear Fog Light status
    uint8_t lights_hazard;     //Hazard Lights - N/A
    std::string lights_hazard_status; //Hazard Lights status
    uint8_t lights_right_blinker;     //Right Blinker - N/A
    std::string lights_right_blinker_status; //Right Blinker status
    uint8_t lights_high_beam;     //High Beams - N/A
    std::string lights_high_beam_status; //High Beams status
    uint8_t wipers_rear;     //Rear Wiper - N/A
    std::string wipers_rear_status; //Rear Wiper status
    uint8_t lights_night_headlights;     //Night Headlights - N/A
    std::string lights_night_headlights_status; //Night Headlights status
    uint8_t lights_sidelights;     //Sidelights - N/A
    std::string lights_sidelights_status; //Sidelights status
    uint8_t doors_all_unlocked;     //All doors Unlocked - N/A
    std::string doors_all_unlocked_status; //All doors Unlocked status
    uint8_t doors_driver_unlocked;     //Driver Door Unlocked - N/A
    std::string doors_driver_unlocked_status; //Driver Door Unlocked status
    uint8_t doors_driver_unlocked_2;     //Driver Door Unlocked - N/A
    std::string doors_driver_unlocked_2_status; //Driver Door Unlocked status
// File: 0x696.yaml - 
    float motor_current_amps;     //Motor Current Amps - Amps
    float motor_regen_amps;     //Regen Amps - Amps
// File: 0x697.yaml - 
    uint16_t chademo_connected;     //Chademo Connected - N/A
    uint16_t chademo_charge_percent;     //Chademo Charge % - Percentage
    uint16_t chademo_charge_amps;     //Chademo Current - AMPs
// File: cell_volts.yaml - 
    float cell_voltages[96];     //Cell Voltages - Volts
    int16_t cell_temperatures[96];     //Cell Temperatures - C
};
#endif // MODEL_H
