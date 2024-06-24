#include <Stepper.h>

// Define the number of steps per revolution for the 28BYJ-48
const int STEPS_PER_REV = 2048;

// Define the connection pins
const int IN1 = 8;
const int IN2 = 9;
const int IN3 = 10;
const int IN4 = 11;

// Initialize the stepper library
Stepper myStepper(STEPS_PER_REV, IN1, IN3, IN2, IN4);

void setup() {
  // Set the speed at 10 RPM
  myStepper.setSpeed(10);
  // Begin serial communication for debugging purposes
  Serial.begin(9600);
}

void loop() {
  // Rotate anticlockwise by 20 degrees
  int stepsFor20Degrees = (STEPS_PER_REV / 360) * 20;
  myStepper.step(-stepsFor20Degrees);
  
  delay(2000);  // Wait for 2 seconds
  
  // Rotate clockwise in 5-degree steps until 40 degrees
  int stepsFor5Degrees = (STEPS_PER_REV / 360) * 5;
  for (int i = 0; i < 8; i++) {  // 8 steps of 5 degrees each = 40 degrees
    myStepper.step(stepsFor5Degrees);
    delay(1000);  // Wait for 1 second between steps
  }
  
  delay(5000);  // Wait for 5 seconds before repeating
}