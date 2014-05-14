#ifndef motor_controller_h
#define motor_controller_h

class MotorController {
  public:
    MotorController();
    void loop();
    void set_motor_speed(int speed);

  private:
    void setup_motors();
};

#endif
