#ifndef DIGITAL_PIN_SHIFTER_HPP
#define DIGITAL_PIN_SHIFTER_HPP

#include "digital_pin_base.hpp"

class DigitalPinShifter : public DigitalPinBase
{
  public:
  DigitalPinShifter(Shifter* shifter, byte index, boolean state):DigitalPinBase(index, state)
  {
    if (index < 0 || index > 7)
    {
      Serial.println("Shifter pin index out of bounds [0, 7]");
    }

    this->shifter = shifter;
  }

  void activate()
  {
    DigitalPinBase::activate();
    this->shifter->set_shift_register_bit(index, !state);
  }

  void deactivate()
  {
    DigitalPinBase::deactivate();
    this->shifter->set_shift_register_bit(index, !state);
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
  Shifter* shifter;
};

#endif