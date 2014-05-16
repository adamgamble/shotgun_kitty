#include "Arduino.h"
#include "motor_controller.h"

#define motor_1_pin 7
#define motor_2_pin 8
#define motor_3_pin 9
#define motor_4_pin 10

#define IDLE_SPEED 1050
#define OFF_SPEED 1000

MotorController::MotorController() {
  setup_motors();
}

void MotorController::setup_motors() {
  pinMode(motor_1_pin, OUTPUT);
  pinMode(motor_2_pin, OUTPUT);
  pinMode(motor_3_pin, OUTPUT);
  pinMode(motor_4_pin, OUTPUT);
}

void MotorController::loop() {
  digitalWrite(motor_1_pin, HIGH);
  delayMicroseconds(motor_1_speed);
  digitalWrite(motor_1_pin, LOW);

  digitalWrite(motor_2_pin, HIGH);
  delayMicroseconds(motor_2_speed);
  digitalWrite(motor_2_pin, LOW);

  digitalWrite(motor_3_pin, HIGH);
  delayMicroseconds(motor_3_speed);
  digitalWrite(motor_3_pin, LOW);

  digitalWrite(motor_4_pin, HIGH);
  delayMicroseconds(motor_4_speed);
  digitalWrite(motor_4_pin, LOW);
}

void MotorController::idle_motors() {
  motor_1_speed = IDLE_SPEED;
  motor_2_speed = IDLE_SPEED;
  motor_3_speed = IDLE_SPEED;
  motor_4_speed = IDLE_SPEED;
}

void MotorController::turn_motors_off() {
  motor_1_speed = OFF_SPEED;
  motor_2_speed = OFF_SPEED;
  motor_3_speed = OFF_SPEED;
  motor_4_speed = OFF_SPEED;
}



