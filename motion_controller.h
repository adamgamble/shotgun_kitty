#ifndef motion_controller_h
#define motion_controller_h

#include "Wire.h"
#include "Adafruit_Sensor.h"
#include "Adafruit_LSM303_U.h"
#include "Adafruit_9DOF.h"

class MotionController {
  public:
    MotionController();
    void loop();

    //Public Variables
    int current_x_rotation;
    int current_y_rotation;
    int current_z_rotation;
    int current_roll;
    int current_pitch;
    int current_heading;
    void init_sensors();

  private:
    Adafruit_9DOF                 dof;
    Adafruit_LSM303_Accel_Unified accel;
    Adafruit_LSM303_Mag_Unified   mag;
};

#endif



