#include <SoftwareSerial.h>

SoftwareSerial bt(3, 2); // RX, TX

const int LEFT_FORWARD = 11;
const int LEFT_BACKWARD = 10;
const int RIGHT_BACKWARD = 6;
const int RIGHT_FORWARD = 5;



void setup() {

  Serial.begin(19200);
  bt.begin(9600);
  
  pinMode(LEFT_FORWARD, OUTPUT);
  pinMode(LEFT_BACKWARD, OUTPUT);
  pinMode(RIGHT_FORWARD, OUTPUT);
  pinMode(RIGHT_BACKWARD, OUTPUT);

}

String data = "";

void loop() {
  
  while(bt.available()){
    char a = bt.read();
    Serial.println("Read: " + a);
    runCommand(a);
  }

}

void runCommand(char command) {
  Serial.println("Command: " + command);
  if (command == 'a') {
    moveForward();
  } else if (command == 'b') {
    moveBackwards();
  } else if (command == 'c') {
    turnLeft();
  } else if (command == 'd') {
    turnRight();
  }
}

void turnLeft() {
  delay(500);
  analogWrite(LEFT_FORWARD, 0);
  analogWrite(RIGHT_FORWARD, 255);
  delay(500);
  stopMovement();
  delay(500);
}

void turnRight() {
  delay(500);
  analogWrite(LEFT_FORWARD, 255);
  analogWrite(RIGHT_FORWARD, 0);
  delay(500);
  stopMovement();
  delay(500);
}

void moveForward() {
  delay(1000);
  Serial.println("Going forward !");
  stopMovement();
  delay(500);
  analogWrite(LEFT_FORWARD, 255);
  analogWrite(RIGHT_FORWARD, 255);
  delay(500);
  stopMovement();
  delay(500);
}

void moveBackwards() {
  delay(1000);
  Serial.println("Going backward !");
  stopMovement();
  delay(500);
  analogWrite(LEFT_BACKWARD, 255);
  analogWrite(RIGHT_BACKWARD, 255);
  delay(500);
  stopMovement();
  delay(500);
}

void stopMovement() {
  analogWrite(LEFT_FORWARD, 0);
  analogWrite(RIGHT_FORWARD, 0);
  analogWrite(LEFT_BACKWARD, 0);
  analogWrite(RIGHT_BACKWARD, 0);
}


