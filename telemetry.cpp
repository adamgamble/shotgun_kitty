#include "Arduino.h"
#include "telemetry.h"
#include "rc_inputs.h"

Telemetry::Telemetry(RCInputs* _rc_inputs) {
  rc_inputs = _rc_inputs;
  Serial.println("Telemetry Active");
}

void Telemetry::telemetry_loop() {
  Serial.print("Throttle Percentage: ");
  Serial.print(rc_inputs->throttle_percentage());
  Serial.print("\n");
}
