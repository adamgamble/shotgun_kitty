#ifndef motor_controller_h
#define motor_controller_h

class MotorController {
  public:
    MotorController();
    void loop();
    void set_motor_speed(int speed);
    int motor_1_speed;
    int motor_2_speed;
    int motor_3_speed;
    int motor_4_speed;

  private:
    void setup_motors();
};

#endif
