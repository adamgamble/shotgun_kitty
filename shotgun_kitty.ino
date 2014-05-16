#include "rc_inputs.h"
#include "telemetry.h"
#include "flight_controller.h"
#include "motor_controller.h"
#include "motion_controller.h"

RCInputs rc_inputs;
MotionController motion_controller;
MotorController motor_controller;
FlightController flight_controller(&rc_inputs, &motion_controller, &motor_controller);
Telemetry telemetry(&rc_inputs, &flight_controller, &motion_controller);

void setup()
{
  Serial.begin(115200);
  motion_controller.init_sensors();
}

void loop()
{
  rc_inputs.loop();
  motion_controller.loop();
  flight_controller.loop();
  motor_controller.loop();
  telemetry.loop();
}



