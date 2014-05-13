#include "Arduino.h"
#include "flight_controller.h"
#include "rc_inputs.h"

FlightController::FlightController(RCInputs* _rc_inputs) {
  rc_inputs = _rc_inputs;
  flight_mode = 0;
  armed = false;
}

void FlightController::loop() {

}
