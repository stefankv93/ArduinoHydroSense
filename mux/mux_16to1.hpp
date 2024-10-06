#ifndef MUX_16to1_HPP
#define MUX_16to1_HPP

#include "mux_base.hpp"
#include "../pin/digital_pin_arduino.hpp"
#include "../pin/analog_pin_arduino.hpp"

class Mux16to1: MuxBase
{
    public:
    // Constructor
    Mux16to1(
      DigitalPinArduino* s0_pin,
      DigitalPinArduino* s1_pin,
      DigitalPinArduino* s2_pin,
      DigitalPinArduino* s3_pin,
      AnalogPinArduino* analog_output_value)
    {
        this->s0_pin = s0_pin;
        this->s1_pin = s1_pin;
        this->s2_pin = s2_pin;
        this->s3_pin = s3_pin;
        this->analog_output_value = analog_output_value;
    }

    void select_mux_input_line(int line)
    {
        this->s0_pin->set_pin_state(bitRead(line, 0));
        this->s1_pin->set_pin_state(bitRead(line, 1));
        this->s2_pin->set_pin_state(bitRead(line, 2));
        this->s3_pin->set_pin_state(bitRead(line, 3));
    }

    AnalogPinArduino* get_analog_output_value()
    {
      return analog_output_value;
    }

    private:
    DigitalPinArduino* s0_pin;
    DigitalPinArduino* s1_pin;
    DigitalPinArduino* s2_pin;
    DigitalPinArduino* s3_pin;
    AnalogPinArduino* analog_output_value;
};

#endif