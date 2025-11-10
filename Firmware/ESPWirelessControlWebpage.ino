// === Robot Arm Web UI Control ===
// ESP32 Access Point + Web Server | Multi-stepper demo

#include <WiFi.h>
#include <WebServer.h>

#define EN_PIN 25
#define STEP1 26
#define DIR1 27
#define STEP2 14
#define DIR2 12
#define STEP3 18
#define DIR3 19

WebServer server(80);

void stepMotor(int stepPin, int dirPin, bool dir, int steps) {
  digitalWrite(dirPin, dir);
  for (int i = 0; i < steps; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(800);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(800);
  }
}

void moveForward() {
  digitalWrite(EN_PIN, LOW);
  stepMotor(STEP1, DIR1, HIGH, 200);
  stepMotor(STEP2, DIR2, HIGH, 200);
  stepMotor(STEP3, DIR3, HIGH, 200);
}

void moveBackward() {
  digitalWrite(EN_PIN, LOW);
  stepMotor(STEP1, DIR1, LOW, 200);
  stepMotor(STEP2, DIR2, LOW, 200);
  stepMotor(STEP3, DIR3, LOW, 200);
}

void stopMotors() {
  digitalWrite(EN_PIN, HIGH);
}

String htmlPage = R"(
<!DOCTYPE html>
<html>
<head>
  <meta name='viewport' content='width=device-width, initial-scale=1.0'>
  <title>Robot Arm Control</title>
  <style>
    body {font-family: Arial; text-align:center; margin-top:40px; background:#111; color:white;}
    button {padding:15px 25px; margin:10px; font-size:18px; border:none; border-radius:8px; background:#008CBA; color:white;}
    button:hover {background:#005f7a;}
  </style>
</head>
<body>
  <h2>Robot Arm Web Control</h2>
  <button onclick="fetch('/forward')">Forward</button>
  <button onclick="fetch('/backward')">Backward</button>
  <button onclick="fetch('/stop')">Stop</button>
</body>
</html>
)";

void handleRoot() {
  server.send(200, "text/html", htmlPage);
}

void setup() {
  pinMode(EN_PIN, OUTPUT);
  pinMode(STEP1, OUTPUT); pinMode(DIR1, OUTPUT);
  pinMode(STEP2, OUTPUT); pinMode(DIR2, OUTPUT);
  pinMode(STEP3, OUTPUT); pinMode(DIR3, OUTPUT);
  digitalWrite(EN_PIN, HIGH); // disabled by default

  WiFi.softAP("RobotArm", "12345678");
  Serial.begin(115200);
  Serial.println("WiFi started! Connect to 'RobotArm' with password 12345678");
  Serial.println("Open http://192.168.4.1 in your browser.");

  server.on("/", handleRoot);
  server.on("/forward", [](){ moveForward(); server.send(200, "text/plain", "Forward"); });
  server.on("/backward", [](){ moveBackward(); server.send(200, "text/plain", "Backward"); });
  server.on("/stop", [](){ stopMotors(); server.send(200, "text/plain", "Stopped"); });

  server.begin();
}

void loop() {
  server.handleClient();
}
