#include "config/config.hpp"
#include "mux/mux_16to1.hpp"
#include "shifter/shifter.hpp"
#include "pin/digital_pin_arduino.hpp"
#include "pin/digital_pin_shifter.hpp"
#include "pin/analog_pin_arduino.hpp"
#include "pin/analog_pin_mux16to1.hpp"
#include "sensors/moisture_sensor.hpp"
#include "relay/relay.hpp"

// Create MUX controling pins
DigitalPinArduino mux_s0(MUX_S0, LOW);
DigitalPinArduino mux_s1(MUX_S1, LOW);
DigitalPinArduino mux_s2(MUX_S2, LOW);
DigitalPinArduino mux_s3(MUX_S3, LOW);

// Create MUX output analog pin
AnalogPinArduino a0_in(0);

// Create MUX
Mux16to1 mux16to1(&mux_s0, &mux_s1, &mux_s2, &mux_s3, &a0_in);

// Create MUX analog pin for moisture sensor 0
AnalogPinMUX16To1 moisture_0_pin(&mux16to1, 0);

// Create Moisture sensor
MoistureSensor moisture_sensor_0(&moisture_0_pin);

DigitalPinArduino shift_latch_pin(SHIFT_LATCH, LOW);
DigitalPinArduino shift_clock(SHIFT_CLOCK, LOW);
DigitalPinArduino shift_data(SHIFT_DATA, LOW);

Shifter shifter(&shift_latch_pin, &shift_clock, &shift_data, SHIFT_DEFAULT_DATA);

DigitalPinShifter relay_0_pin(&shifter, 0, HIGH);
DigitalPinShifter relay_1_pin(&shifter, 1, HIGH);

Relay relay_0(&relay_0_pin);
Relay relay_1(&relay_1_pin);

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  
  //setup serial for debug
  Serial.begin(9600);
  //shifter.shift_register_data(SHIFT_DEFAULT);
  Serial.println("Setup doneS");
}

void loop() {
  delay(5000);
  float mositure_level = moisture_sensor_0.get_moisture_level();
  Serial.println("Moisture data for plant 0:" + String(mositure_level) + "%");

  if(mositure_level < 30.0)
  {
    relay_0.on();
  }
  else
  {
    relay_0.off();
  }
  
}