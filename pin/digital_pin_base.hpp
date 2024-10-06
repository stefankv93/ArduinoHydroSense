#ifndef DIGITAL_PIN_BASE_HPP
#define DIGITAL_PIN_BASE_HPP

class DigitalPinBase
{
  public:
  DigitalPinBase(byte index, boolean state)
  {
    this->index = index;
    this->state = state;
  }

  virtual void activate()
  {
    this->state = HIGH;
  }

  virtual void deactivate()
  {
    this->state = LOW;
  }

  virtual void set_pin_state(boolean state)
  {
    this->state = state;
  }

  byte get_index()
  {
    return index;
  }

  boolean get_state()
  {
    return state;
  }

  protected:
  byte index;
  boolean state;
};

#endif