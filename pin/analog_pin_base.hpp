#ifndef ANALOG_PIN_BASE_HPP
#define ANALOG_PIN_BASE_HPP

class AnalogPinBase
{
  public:
  AnalogPinBase(byte index)
  {
    this->index = index;
  }

  virtual int read_analog_value()
  {
    return 0;
  }

  protected:
  byte index;
};

#endif