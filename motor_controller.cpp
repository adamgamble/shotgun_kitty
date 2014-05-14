#include "Arduino.h"
#include "motor_controller.h"

#define motor_1_pin 7
#define motor_2_pin 8
#define motor_3_pin 9
#define motor_4_pin 10

MotorController::MotorController() {
  setup_motors();
}

void MotorController::setup_motors() {
  pinMode(motor_1_pin, OUTPUT);
  pinMode(motor_2_pin, OUTPUT);
  pinMode(motor_3_pin, OUTPUT);
  pinMode(motor_4_pin, OUTPUT);
}

void MotorController::set_motor_speed(int speed) {
  digitalWrite(motor_1_pin, HIGH);
  digitalWrite(motor_2_pin, HIGH);
  digitalWrite(motor_3_pin, HIGH);
  digitalWrite(motor_4_pin, HIGH);
  delayMicroseconds(speed);
  digitalWrite(motor_1_pin, LOW);
  digitalWrite(motor_2_pin, LOW);
  digitalWrite(motor_3_pin, LOW);
  digitalWrite(motor_4_pin, LOW);
}

void MotorController::loop() {

}
