// Define the Arduino pins connected to the ULN2003 driver
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

// Steps per revolution for full-step mode
#define STEPS_PER_REV 2038

// Define the sequence for full-step mode
const int fullStepSequence[4][4] = {
  {1, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 1},
  {1, 0, 0, 1}
};

int currentStep = 0;

void setup() {
  // Set pins as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Initialize the stepper motor to the first step
  setStep(currentStep);
}

void loop() {
  // Rotate the motor one step clockwise
  stepMotor(1);
  delay(10); // Adjust delay for speed control

  // Rotate the motor one step counterclockwise
  // stepMotor(-1);
  // delay(10); // Adjust delay for speed control
}

void setStep(int step) {
  digitalWrite(IN1, fullStepSequence[step][0]);
  digitalWrite(IN2, fullStepSequence[step][1]);
  digitalWrite(IN3, fullStepSequence[step][2]);
  digitalWrite(IN4, fullStepSequence[step][3]);
}

void stepMotor(int step) {
  currentStep += step;
  if (currentStep > 3) {
    currentStep = 0;
  } else if (currentStep < 0) {
    currentStep = 3;
  }
  setStep(currentStep);
}

