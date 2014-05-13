#include "rc_inputs.h"
#include "telemetry.h"

RCInputs rc_inputs;
Telemetry telemetry(&rc_inputs);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  rc_inputs.get_inputs();
  telemetry.telemetry_loop();
}
