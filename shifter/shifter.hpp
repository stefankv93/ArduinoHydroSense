#ifndef SHIFTER_HPP
#define SHIFTER_HPP

#include "../pin/digital_pin_base.hpp"
#include "../pin/digital_pin_arduino.hpp"

class Shifter
{
  public:
  Shifter(DigitalPinArduino* latch_pin, DigitalPinArduino* clock_pin, DigitalPinArduino* data_pin, byte init_data)
  {
    this->latch_pin = latch_pin;
    this->clock_pin = clock_pin;
    this->data_pin = data_pin;
    this->latched_data = init_data;
    init();
  }

  void init()
  {
    this->latch_pin->deactivate();
    this->clock_pin->deactivate();
    this->data_pin->deactivate();
    shift_register_data(this->latched_data);
  }

  void shift_register_data(byte data)
  {
    this->latch_pin->deactivate();
    shiftOut(this->data_pin->get_index(), this->clock_pin->get_index(), MSBFIRST, data);
    this->latched_data = data;
    this->latch_pin->activate();
  }

  void set_shift_register_bit(byte position, boolean bit)
  {
    byte mask = (1 << position);
    if(bit == 0)
    {
      this->latched_data = this->latched_data & ~mask;
    }
    else
    {
      this->latched_data = this->latched_data | mask;
    }
    shift_register_data(this->latched_data);
  }

  byte get_shift_register_latched_data()
  {
    return this->latched_data;
  }

  boolean get_shift_register_latched_data_bit(byte position)
  {
    byte mask = (1 << position);
    return (this->latched_data & mask) >> (position);
  }

  private:
  DigitalPinArduino* latch_pin;
  DigitalPinArduino* clock_pin;
  DigitalPinArduino* data_pin;
  byte latched_data;
};

#endif