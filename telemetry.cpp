#include "Arduino.h"
#include "telemetry.h"
#include "rc_inputs.h"
#include "flight_controller.h"

Telemetry::Telemetry(RCInputs* _rc_inputs, FlightController* _flight_controller) {
  rc_inputs = _rc_inputs;
  flight_controller = _flight_controller;
  Serial.println("Telemetry Active");
}

void Telemetry::loop() {
  Serial.print("Throttle Percentage: ");
  Serial.print(rc_inputs->throttle_percentage());
  Serial.print("\r\n");
  Serial.print("Current Flightmode: ");
  Serial.print(flight_controller->flight_mode);
  Serial.print("\r\n");
}
