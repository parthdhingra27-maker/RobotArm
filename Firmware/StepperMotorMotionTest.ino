// === Robot Arm Stepper Motor Test ===
// Parth Dhingra

#define EN_PIN   25
#define ESTOP_PIN 34

// Stepper 1
#define STEP1 26
#define DIR1  27

// Stepper 2
#define STEP2 14
#define DIR2  12

// Stepper 3
#define STEP3 18
#define DIR3  19

int stepDelay = 800; // microseconds (speed control)

void stepMotor(int stepPin, int dirPin, bool dir, int steps) {
  digitalWrite(dirPin, dir);
  for (int i = 0; i < steps; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepDelay);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(EN_PIN, OUTPUT);
  pinMode(ESTOP_PIN, INPUT_PULLUP);
  pinMode(STEP1, OUTPUT);
  pinMode(DIR1, OUTPUT);
  pinMode(STEP2, OUTPUT);
  pinMode(DIR2, OUTPUT);
  pinMode(STEP3, OUTPUT);
  pinMode(DIR3, OUTPUT);
  digitalWrite(EN_PIN, LOW); // enable all
  Serial.println("Stepper test started.");
}

void loop() {
  if (digitalRead(ESTOP_PIN) == LOW) {
    Serial.println("E-STOP pressed! Disabling motors.");
    digitalWrite(EN_PIN, HIGH);
    delay(500);
    return;
  }

  // Forward direction
  Serial.println("Moving forward...");
  stepMotor(STEP1, DIR1, HIGH, 200);
  stepMotor(STEP2, DIR2, HIGH, 200);
  stepMotor(STEP3, DIR3, HIGH, 200);
  delay(500);

  // Backward direction
  Serial.println("Moving backward...");
  stepMotor(STEP1, DIR1, LOW, 200);
  stepMotor(STEP2, DIR2, LOW, 200);
  stepMotor(STEP3, DIR3, LOW, 200);
  delay(500);
}
