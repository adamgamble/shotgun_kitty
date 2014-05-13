#include "Arduino.h"
#include "rc_inputs.h"

#define throttle_pin 2

#define min_throttle 1085
#define max_throttle 1872

RCInputs::RCInputs() {
  setup_pins();
}

void RCInputs::get_inputs() {
  current_throttle = read_input(throttle_pin);
}

void RCInputs::setup_pins() {
  pinMode(throttle_pin, INPUT);
}

int RCInputs::read_input(int pin) {
  return pulseIn(pin, HIGH, 25000);
}

float RCInputs::throttle_percentage() {
  int total_throttle = max_throttle - min_throttle;
  int throttle = current_throttle - min_throttle;
  return (float)throttle / (float)total_throttle;
}
