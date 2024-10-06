#ifndef RELAY_HPP
#define RELAY_HPP

#include "../pin/digital_pin_shifter.hpp"

class Relay
{
  public:
  Relay(DigitalPinShifter* relay_pin)
  {
    this->relay_pin = relay_pin;
    init();
  }

  void init()
  {
    this->relay_pin->activate();
  }

  void on()
  {
    this->relay_pin->deactivate();
  }

  void off()
  {
    this->relay_pin->activate();
  }

  void togle()
  {
    this->relay_pin->set_pin_state(!this->relay_pin->get_state());
  }

  private:
  DigitalPinShifter* relay_pin;
};

#endif