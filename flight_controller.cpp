#include "Arduino.h"
#include "flight_controller.h"
#include "acro_mode.h"

FlightController::FlightController(RCInputs* _rc_inputs, MotionController* _motion_controller, MotorController* _motor_controller) {
  rc_inputs = _rc_inputs;
  motor_controller = _motor_controller;
  motion_controller = _motion_controller;
  flight_mode = 0;
  armed = false;
}

void FlightController::loop() {
  if (armed == true) {
    motor_controller->idle_motors();
    switch (flight_mode) {
      case 0:
        AcroMode acro_mode(rc_inputs, motion_controller, motor_controller);
        acro_mode.PIDController();
        break;
    }
  } else {
    motor_controller->turn_motors_off();
  }
}



