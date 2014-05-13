#ifndef telemetry_h
#define telemetry_h

#include "rc_inputs.h"

class Telemetry {
  public:
    Telemetry(RCInputs* rc_inputs);
    void telemetry_loop();

  private:
    RCInputs* rc_inputs;
};

#endif
