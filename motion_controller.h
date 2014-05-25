#ifndef motion_controller_h
#define motion_controller_h

#include "Wire.h"
#include "Adafruit_Sensor.h"
#include "Adafruit_LSM303_U.h"
#include "Adafruit_9DOF.h"
#include "Adafruit_L3GD20_U.h"

class MotionController {
  public:
    MotionController();
    void loop();

    //Public Variables
    float current_x_rotation;
    float current_y_rotation;
    float current_z_rotation;
    float current_roll;
    float current_pitch;
    float current_heading;
    void init_sensors();

  private:
    Adafruit_9DOF                 dof;
    Adafruit_LSM303_Accel_Unified accel;
    Adafruit_LSM303_Mag_Unified   mag;
    Adafruit_L3GD20_Unified       gyro;
};

#endif



