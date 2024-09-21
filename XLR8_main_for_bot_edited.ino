/*
Bot programming code: Written on CPP modified to work on Arduino IDE
Written for and by Electronics & Robotics Club, IIT Bombay with assistance from internet resources.

For: Raspberry Pi Pico W to navigate a 4-wheeled bot based on differential drive(INCOMPLETE)
NOTE: ALL LIBRARIES COME PREINSTALLED IN YOUR ARDUINO IDE, YOU AREN'T EXPECTED TO INSTALL ANYTHING EXTRA OTHER THAN WHAT WAS TAUGHT IN GET CODIFIED.
©ERC // MIT License 2024 
*/

#include <WiFi.h>
#include <typeinfo>
#include <string.h>
#include <stdio.h>


// SSID and password for the access point
const char* ssid = "RoboRenegade"; //Enter your team name as the SSID here
const char* password = "#P24zm^c"; // Make a good password!

// Define a structure to hold IMU (Inertial Measurement Unit) data
typedef struct {
  float gx, gy, gz;
} IMUData;

IMUData myMessage; // Create a variable to store received IMU data
int cmd = 0;       // Initialize motor control command variable
int spd = 0;       // Initialize motor speed variable
int spd2 = 0;      // Analog colour signal
// Function to update motor control based on received IMU data
void updateMotorControl() {
  float gx = myMessage.gx;
  float gy = myMessage.gy;
  float gz = myMessage.gz;
  // Motor control logic based on IMU data
  if ((gz != 0) && (gx != 0) && (abs(gy) < 2)) {
    spd = constrain(abs(map((atan2(gx, gz) * 180 / PI), 0, 90, 0, 255)), 0, 255);
    cmd = (gx > 0) ? 1 : 2; // Forward or backward
  } else if ((gz != 0) && (gy != 0) && (abs(gx) < 2)) {
    spd = constrain(abs(map((atan2(gy, gz) * 180 / PI), 0, 90, 0, 255)), 0, 255);
    cmd = (gy > 0) ? 3 : 4; // Right or left
  } else {
    cmd = 0; // Stop
    spd = 0;
  }
  spd=spd*2;
  spd2=spd;
  // Adjust motor speed thresholds
  if (spd > 30 ) {
    spd=(spd-30)*255/225;
  }
  else {
    spd=0;
  }
  // Adjust colour variation
  spd2=spd;
  if (spd2>45) {
    spd2=(spd2-45)*255/210;
  }
  else {
    spd2=0;
  }
  // Display motor control information
  Serial.print("cmd: ");
  Serial.println(cmd);   // Display motor command
  Serial.print(", speed: ");
  Serial.println(spd); // Display motor speed

}

// Pin assignments for motor control
const int ENA = 8;
const int ENB = 9;

const int IN1 = 10;
const int IN2 = 11;
const int IN3 = 12;
const int IN4 = 13;

// Pin assignments for RGB LED
const int Red = 2;
const int Green = 3;
const int Blue = 4;

// Pin assignment for signal to Servo 
const int serv = 22;

// Create a WiFiServer object for the TCP server
WiFiServer server(80);

void setup() {
  // Start Serial for debugging
  Serial.begin(115200);

  // Configure motor control pins as outputs
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  // Configure RGB LED pins
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Blue, OUTPUT);
  // Configure pin for servo activation
  pinMode(serv,OUTPUT);
    

  // Set up the access point
  Serial.println("Setting up WiFi AP...");
  WiFi.softAP(ssid, password);
  
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
  
  // Start the server
  server.begin();

  WiFiClient client = server.available();
  if (client) {
    Serial.println("Client is connected");
  }
}

// Function to activate servo
void activateServo(){
  float gx = myMessage.gx;
  float gy = myMessage.gy;
  float gz = myMessage.gz;
  // Motor actuation implementation
  if (abs(gx==20) || abs(gy==20) || abs(gz==20)) {
    spd=0;
    analogWrite(ENA, spd);
    analogWrite(ENB, spd);
    digitalWrite(serv,HIGH);
    Serial.print("Servo should work now");
    setColour(255,0,0);
    delay(1000);
    digitalWrite(serv,LOW);
  }
  // Set up the access point
  Serial.println("Setting up WiFi AP...");
  WiFi.softAP(ssid, password);
  
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
  
  // Start the server
  server.begin();

  WiFiClient client = server.available();
  if (client) {
    Serial.println("Client is connected");
  }
}

void applyMotorControl() {
  switch (cmd) {
    case 4:  // Left
      digitalWrite(IN1,LOW ); 
      digitalWrite(IN2,HIGH ); 
      digitalWrite(IN3,HIGH ); 
      digitalWrite(IN4,LOW ); 
      setColour(spd2,spd2,spd2);
      break;
    case 3:  // Right
      digitalWrite(IN1,HIGH ); 
      digitalWrite(IN2,LOW ); 
      digitalWrite(IN3,LOW ); 
      digitalWrite(IN4,HIGH ); 
      setColour(0,spd2,spd2);
      break;
    case 2:  // Backward
      digitalWrite(IN1,HIGH ); 
      digitalWrite(IN2,LOW ); 
      digitalWrite(IN3,HIGH ); 
      digitalWrite(IN4,LOW ); 
      setColour(spd2,spd2,0);
      break;
    case 1:  // Forward
      digitalWrite(IN1,LOW ); 
      digitalWrite(IN2,HIGH ); 
      digitalWrite(IN3,LOW ); 
      digitalWrite(IN4,HIGH ); 
      setColour(spd2,0,spd2);
      break;
    default:  // Stop
      digitalWrite(IN1,LOW ); 
      digitalWrite(IN2,LOW ); 
      digitalWrite(IN3,LOW ); 
      digitalWrite(IN4,LOW ); 
      spd = 0;
      break;
  }

  // Apply the calculated motor speed to both motors
  analogWrite(ENA, spd);
  analogWrite(ENB, spd);
}

  // Colour code for RGB LED
void setColour(int r,int g,int b){
  r=255-r;
  g=255-g;
  b=255-b;

  analogWrite(Red,r);
  analogWrite(Green,g);
  analogWrite(Blue,b);

}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (client) {
    while (client.connected()) {
      if (client.available()) {
        digitalWrite(LED_BUILTIN, HIGH);
        String request = client.readStringUntil('\r');
        Serial.print("Received data: ");
        //Serial.println(request);
        char chararr[50];
        request.toCharArray(chararr, sizeof(chararr));

        Serial.println(chararr);
        char *res;
        float arr[3];
        int i = 0;

        res = strtok(chararr , " ");
        while(res != NULL){
          Serial.println(res);
          String strr = String(res);
          float val = strr.toFloat();
          Serial.println(val);
          res = strtok(NULL, " ");
          arr[i]= val;
          i++;
        }
        myMessage.gx = arr[0];
        myMessage.gy = arr[1];
        myMessage.gz = arr[2];
        activateServo();
        updateMotorControl();
        applyMotorControl();
        digitalWrite(LED_BUILTIN, LOW);
      }
      digitalWrite(LED_BUILTIN, LOW);
   // Continuously update and apply motor control
  delay(100); // Delay to control loop speed
    }
  }
}
