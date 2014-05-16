#include "Arduino.h"
#include "motion_controller.h"
#include "Wire.h"
#include "Adafruit_Sensor.h"
#include "Adafruit_LSM303_U.h"
#include "Adafruit_9DOF.h"
#include <Adafruit_L3GD20_U.h>


MotionController::MotionController() : accel(30301), mag(30302), gyro(30303) {
}

void MotionController::loop() {
  sensors_event_t accel_event;
  sensors_event_t mag_event;
  sensors_event_t gyro_event;
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
  gyro.getEvent(&gyro_event);
  current_x_rotation = gyro_event.gyro.x;
  current_y_rotation = gyro_event.gyro.y;
  current_z_rotation = gyro_event.gyro.z;
}


void MotionController::init_sensors() {
  accel.begin();
  mag.begin();
  gyro.enableAutoRange(true);
  gyro.begin();
}
