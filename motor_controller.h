#ifndef motor_controller_h
#define motor_controller_h

#include "Servo.h"

class MotorController {
  public:
    MotorController();
    void loop();
    void set_motor_speed(int speed);

  private:
    void setup_motors();
    Servo motor_1;
    Servo motor_2;
    Servo motor_3;
    Servo motor_4;
};

#endif
