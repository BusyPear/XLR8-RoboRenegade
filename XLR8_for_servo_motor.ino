// This code is to be uploaded in Arduino Nano, which will be used to power the servo motor for the electrical actuation of the cannon. 


#include <Servo.h>
Servo ourservo;
// Pin assignment for signal read from Rpi Pico W
int pin = 3;
void setup() {
pinMode(pin,INPUT);
// Assign pin for servo
ourservo.attach(2);
Serial.begin(115200);
Serial.println("Hellow");
ourservo.write(0);
}

void loop() {
// Variable to detect signal from Rpi Pico W
int x = digitalRead(pin);
Serial.println(x);
delay(100);
if(x==1){
  Serial.println("Servo activated");
  ourservo.write(90);
  delay(1000);
  ourservo.write(0);
}
}
