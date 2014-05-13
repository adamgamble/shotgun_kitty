#include "Arduino.h"
#include "motor_controller.h"
#include <Servo.h>

#define motor_1_pin 7
#define motor_2_pin 8
#define motor_3_pin 9
#define motor_4_pin 10

MotorController::MotorController() {
  //setup_motors();
}

void MotorController::setup_motors() {
  motor_1.attach(motor_1_pin);
  motor_2.attach(motor_2_pin);
  motor_3.attach(motor_3_pin);
  motor_4.attach(motor_4_pin);
}

void MotorController::loop() {

}
