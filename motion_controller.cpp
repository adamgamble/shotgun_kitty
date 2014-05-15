#include "Arduino.h"
#include "motion_controller.h"
#include "Wire.h"
#include "Adafruit_Sensor.h"
#include "Adafruit_LSM303_U.h"
#include "Adafruit_9DOF.h"


MotionController::MotionController() : accel(30301), mag(30302) {
}

void MotionController::loop() {
  sensors_event_t accel_event;
  sensors_event_t mag_event;
  sensors_vec_t   orientation;

  accel.getEvent(&accel_event);
  if (dof.accelGetOrientation(&accel_event, &orientation))
  {
    current_roll = orientation.roll;
    current_pitch = orientation.pitch;
  }

  mag.getEvent(&mag_event);
  if (dof.magGetOrientation(SENSOR_AXIS_Z, &mag_event, &orientation))
  {
    current_heading = orientation.heading;
  }
}


void MotionController::init_sensors() {
  accel.begin();
  mag.begin();
}
