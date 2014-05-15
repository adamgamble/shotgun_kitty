#include "Arduino.h"
#include "flight_controller.h"
#include "rc_inputs.h"
#include "motor_controller.h"

FlightController::FlightController(RCInputs* _rc_inputs, MotorController* _motor_controller) {
  rc_inputs = _rc_inputs;
  motor_controller = _motor_controller;
  flight_mode = 0;
  armed = false;
}

void FlightController::loop() {
  motor_controller->motor_1_speed = rc_inputs->current_throttle;
  motor_controller->motor_2_speed = rc_inputs->current_throttle;
  motor_controller->motor_3_speed = rc_inputs->current_throttle;
  motor_controller->motor_4_speed = rc_inputs->current_throttle;
}



