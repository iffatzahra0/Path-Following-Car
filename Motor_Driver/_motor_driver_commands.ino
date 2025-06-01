
// include library
#include <AFMotor.h>

// ARDUINO PATH FOLLOWING CAR //

// Defining pins and variables
#define LEFT_SENSOR A0
#define RIGHT_SENSOR A1

// Defining motors
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

void setup() {
  // Declaring pin types
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);
  
  // Begin serial communication
  Serial.begin(9600);
}

void loop() {
  // Reading sensor values
  int leftValue = analogRead(LEFT_SENSOR);
  int rightValue = analogRead(RIGHT_SENSOR);
  
  // Printing values of the sensors to the serial monitor
  Serial.print("Left Sensor: ");
  Serial.println(leftValue);
  Serial.print("Right Sensor: ");
  Serial.println(rightValue);

  // Defining threshold values for sensors
  int threshold = 500;

  // path detected by both sensors
  if (leftValue < threshold && rightValue < threshold) {
    // Move forward
    motor1.run(FORWARD);
    motor1.setSpeed(100);
    motor2.run(FORWARD);
    motor2.setSpeed(100);
    motor3.run(FORWARD);
    motor3.setSpeed(100);
    motor4.run(FORWARD);
    motor4.setSpeed(100);
  }
  // path detected by left sensor
  else if (leftValue < threshold && rightValue >= threshold) {
    // Turn left
    motor1.run(FORWARD);
    motor1.setSpeed(150);
    motor2.run(FORWARD);
    motor2.setSpeed(150);
    motor3.run(BACKWARD);
    motor3.setSpeed(150);
    motor4.run(BACKWARD);
    motor4.setSpeed(150);
  }
  // path detected by right sensor
  else if (leftValue >= threshold && rightValue < threshold) {
    // Turn right
    motor1.run(BACKWARD);
    motor1.setSpeed(150);
    motor2.run(BACKWARD);
    motor2.setSpeed(150);
    motor3.run(FORWARD);
    motor3.setSpeed(150);
    motor4.run(FORWARD);
    motor4.setSpeed(150);
  }
  // path not detected by either sensor
  else {
    // Stop
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
  }

  // Small delay for stability
  delay(100);
}
