#include "Arduino.h"
#include "rc_inputs.h"

#define throttle_pin    2
#define aileron_pin     3
#define elevator_pin    4
#define rudder_pin      5
#define flight_mode_pin 6

#define min_throttle 1085
#define max_throttle 1872

RCInputs::RCInputs() {
  setup_pins();
}

void RCInputs::get_inputs() {
  current_throttle    = read_input(throttle_pin);
  current_aileron     = read_input(aileron_pin);
  current_elevator    = read_input(elevator_pin);
  current_rudder      = read_input(rudder_pin);
  current_flight_mode = read_input(flight_mode_pin);
}

void RCInputs::setup_pins() {
  pinMode(throttle_pin, INPUT);
  pinMode(aileron_pin, INPUT);
  pinMode(elevator_pin, INPUT);
  pinMode(rudder_pin, INPUT);
  pinMode(flight_mode_pin, INPUT);
}

int RCInputs::read_input(int pin) {
  return pulseIn(pin, HIGH, 25000);
}

float RCInputs::throttle_percentage() {
  int total_throttle = max_throttle - min_throttle;
  int throttle = current_throttle - min_throttle;
  return (float)throttle / (float)total_throttle;
}
