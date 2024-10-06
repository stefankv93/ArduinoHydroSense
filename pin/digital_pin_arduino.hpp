#ifndef DIGITAL_PIN_ARDUINO_HPP
#define DIGITAL_PIN_ARDUINO_HPP

#include "digital_pin_base.hpp"

class DigitalPinArduino : public DigitalPinBase
{
  public:
  DigitalPinArduino(byte index, boolean state):DigitalPinBase(index, state)
  {
    if (index < 0 || index > 13)
    {
      Serial.println("Arduino pin index out of bounds [0, 13]");
    }

    // Configure output arduino digital pin
    pinMode(index, OUTPUT);
    write_state();
  }

  void activate()
  {
    DigitalPinBase::activate();
    write_state();
  }

  void deactivate()
  {
    DigitalPinBase::deactivate();
    write_state();
  }

  void set_pin_state(boolean state)
  {
    if(state == LOW)
    {
      deactivate();
    }
    else
    {
      activate();
    }
  }

  private:
  void write_state()
  {
    digitalWrite(index, state);
  }
};

#endif