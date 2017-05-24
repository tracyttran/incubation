
/*
 * Servo brown to common ground
 * Servo orange/red to 5v
 * Servo yellow to arduino i/o pin 10
 * Led resistor to arduino i/o pin 3
 * Led black to common ground with servo, common ground to arduino ground
 * 
 * plug in all wires except servo to arduino i/o, upload code, then plug in i/o
 */

#include <Servo.h>

Servo myservo;  

int pos = 0;    // variable to store the servo position

int ledPin = 3; //uses PWM
int servoPin = 10;


void setup() {
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object
  pinMode(ledPin, OUTPUT);
  analogWrite(ledPin, 0);
}

void loop() {
  
  // low to high, get brighter
  for (int pos = 150; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    analogWrite(ledPin, map((pos * -1) + 150, 0, 150, 0, 255)); 

    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    
    delay(50);                       // waits 50ms for the servo to reach the position
  }
  
  analogWrite(ledPin, 255);
  delay(15);
  analogWrite(ledPin, 180);
  delay(25);
  analogWrite(ledPin, 255);

  for (int i = 0; i < 14; i++) {
    int brightness = random(100, 255);
    analogWrite(ledPin, brightness);
    int del = random(65, 100);
    delay(del);
  }
  analogWrite(ledPin, 255);
  delay(1000);
  
    for (int pos = 0; pos <= 150; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    analogWrite(ledPin, map((pos * -1) + 150, 0, 150, 0, 255)); 
    delay(15);                       // waits 50ms for the servo to reach the position
  }
  delay(2000);
}

