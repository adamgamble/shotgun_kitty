#include "Arduino.h"
#include "telemetry.h"
#include "rc_inputs.h"
#include "flight_controller.h"

Telemetry::Telemetry(RCInputs* _rc_inputs, FlightController* _flight_controller, MotionController* _motion_controller) {
  rc_inputs = _rc_inputs;
  motion_controller = _motion_controller;
  flight_controller = _flight_controller;
  Serial.println("Telemetry Active");
}

void Telemetry::loop() {
  Serial.print("Throttle\t Current Flightmode\t Roll\t Pitch\t Heading\t X Rotation\t Y Rotation\t Z Movement");
  Serial.print("\r\n");
  Serial.print(rc_inputs->current_throttle);
  Serial.print("\t");
  Serial.print("\t");
  Serial.print("\t");
  Serial.print("\t");
  Serial.print(flight_controller->flight_mode);
  Serial.print("\t");
  Serial.print("\t");
  Serial.print(motion_controller->current_roll);
  Serial.print("\t");
  Serial.print(motion_controller->current_pitch);
  Serial.print("\t");
  Serial.print(motion_controller->current_heading);
  Serial.print("\t");
  Serial.print(motion_controller->current_x_rotation);
  Serial.print("\t");
  Serial.print(motion_controller->current_y_rotation);
  Serial.print("\t");
  Serial.print(motion_controller->current_z_rotation);
  Serial.print("\r\n");
}



