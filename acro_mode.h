#ifndef acro_mode_h
#define acro_mode_h

#include "rc_inputs.h"
#include "motion_controller.h"
#include "motor_controller.h"

class AcroMode {
  public:
    AcroMode(RCInputs* _rc_inputs, MotionController* _motion_controller, MotorController* _motor_controller);
    void PIDController();
  private:
    RCInputs* rc_inputs;
    MotionController* motion_controller;
    MotorController* motor_controller;
};

#endif
