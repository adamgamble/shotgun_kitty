#include "rc_inputs.h"
#include "telemetry.h"
#include "flight_controller.h"

RCInputs rc_inputs;
FlightController flight_controller(&rc_inputs);
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
