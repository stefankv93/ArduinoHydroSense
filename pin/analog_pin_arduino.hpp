#ifndef ANALOG_PIN_ARDUINO_HPP
#define ANALOG_PIN_ARDUINO_HPP

#include "analog_pin_base.hpp"

class AnalogPinArduino : public AnalogPinBase
{
  public:
  AnalogPinArduino(byte index) : AnalogPinBase(index)
  {
    if (index < 0 || index > 5)
    {
      Serial.println("Arduino analog pin index out of bounds [0, 5]");
    }

    // Configure input arduino analog pin
    pinMode(A0, INPUT);
  }

  int read_analog_value()
  {
    return analogRead(this->index);
  }
};

#endif