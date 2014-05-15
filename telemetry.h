#ifndef telemetry_h
#define telemetry_h

#include "rc_inputs.h"
#include "flight_controller.h"

class Telemetry {
  public:
    Telemetry(RCInputs* _rc_inputs, FlightController* _flight_controller);
    void loop();

  private:
    RCInputs* rc_inputs;
    FlightController* flight_controller;
};

#endif



