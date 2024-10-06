#ifndef ANALOG_PIN_MUX16TO1_HPP
#define ANALOG_PIN_MUX16TO1_HPP

#include "analog_pin_base.hpp"
#include "../mux/mux_16to1.hpp"

class AnalogPinMUX16To1 : public AnalogPinBase
{
  public:
  AnalogPinMUX16To1(Mux16to1* mux16to1, byte index) : AnalogPinBase(index)
  {
    if (index < 0 || index > 15)
    {
      Serial.println("Mux16To1 analog pin index out of bounds [0, 15]");
    }

    this->mux16to1 = mux16to1;
  }

  int read_analog_value()
  {
    mux16to1->select_mux_input_line(index);
    return mux16to1->get_analog_output_value()->read_analog_value();
  }

  private:
  Mux16to1* mux16to1;
};

#endif