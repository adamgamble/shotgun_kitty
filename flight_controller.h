#ifndef flight_controller_h
#define flight_controller_h

#include "rc_inputs.h"
#include "motor_controller.h"

class FlightController {
  public:
    FlightController(RCInputs* _rc_inputs, MotorController* _motor_controller);
    void loop();
    int flight_mode;
    bool armed;

  private:
    RCInputs* rc_inputs;
    MotorController* motor_controller;
};

#endif



