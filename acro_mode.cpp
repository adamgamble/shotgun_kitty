#include "Arduino.h"
#include "acro_mode.h"
#include "rc_inputs.h"
#include "motion_controller.h"

#define MIN_THROTTLE 1085
#define MAX_THROTTLE 1875
#define MIN_ELEVATOR 1085
#define MAX_ELEVATOR 1875
#define MIN_AILERON 1085
#define MAX_AILERON 1875
#define MIN_RUDDER 1085
#define MAX_RUDDER 1875

#define MIN_PITCH -50
#define MAX_PITCH 50
#define PITCH_KP 0.7

#define MIN_ROLL -50
#define MAX_ROLL 50
#define ROLL_KP 0.7

#define MIN_YAW -50
#define MAX_YAW 50
#define YAW_KP 2.5

AcroMode::AcroMode(RCInputs* _rc_inputs, MotionController* _motion_controller, MotorController* _motor_controller) {
  rc_inputs = _rc_inputs;
  motion_controller = _motion_controller;
  motor_controller = _motor_controller;
}

void AcroMode::PIDController() {
  long rc_throttle  = rc_inputs->current_throttle;

  if (rc_throttle >= MIN_THROTTLE + 20) {
    long rc_pitch     = map(rc_inputs->current_elevator, MIN_ELEVATOR, MAX_ELEVATOR, -45, 45);
    long rc_yaw       = map(rc_inputs->current_rudder, MIN_RUDDER, MAX_RUDDER, -150, 150);
    long rc_roll      = map(rc_inputs->current_aileron, MIN_AILERON, MAX_AILERON, -45, 45);

    long roll_output  = constrain((rc_roll - motion_controller->current_roll) * ROLL_KP, -250, 250);
    long pitch_output = constrain((rc_pitch - motion_controller->current_pitch) * PITCH_KP, -250, 250);
    long yaw_output   = constrain((rc_yaw - motion_controller->current_heading) * YAW_KP, -360, 360);

    motor_controller->motor_1_speed = rc_throttle + roll_output - pitch_output;
    motor_controller->motor_2_speed = rc_throttle - roll_output + pitch_output;
    motor_controller->motor_3_speed = rc_throttle - roll_output - pitch_output;
    motor_controller->motor_4_speed = rc_throttle + roll_output + pitch_output;
  }
}
