#ifndef MOISTURE_SENSOR_HPP
#define MOISTURE_SENSOR_HPP

class MoistureSensor
{
  public:
  MoistureSensor(AnalogPinMUX16To1* analogPinMUX16To1)
  {
    this->analogPinMUX16To1 = analogPinMUX16To1;
  }

  float get_moisture_level()
  {
    int sensor_value = 1023 - this->analogPinMUX16To1->read_analog_value();
    return 1.0*sensor_value/1023 * 100.0;
  }

  private:
  AnalogPinMUX16To1* analogPinMUX16To1;
};

#endif