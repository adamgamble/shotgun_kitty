#ifndef flight_controller_h
#define flight_controller_h

#include "rc_inputs.h"

class FlightController {
  public:
    FlightController(RCInputs* _rc_inputs);
    void loop();
    int flight_mode;
    bool armed;

  private:
    RCInputs* rc_inputs;
};

#endif
