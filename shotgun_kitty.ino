#include "rc_inputs.h"
#include "telemetry.h"
#include "flight_controller.h"
#include "motor_controller.h"

RCInputs rc_inputs;
MotorController motor_controller;
FlightController flight_controller(&rc_inputs, &motor_controller);
Telemetry telemetry(&rc_inputs, &flight_controller);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  rc_inputs.loop();
  flight_controller.loop();
  telemetry.loop();
}
