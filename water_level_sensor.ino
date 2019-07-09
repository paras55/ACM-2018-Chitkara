#include <Servo.h>
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
 // Analog output pin that the LED is attached to
int buzz = 7;
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)


Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;   

void setup() {
  myservo.attach(9);
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(buzz,OUTPUT);
  digitalWrite(buzz,LOW);
  if (sensorValue>180 && outputValue>42){
     Serial.println("water level is above required");}
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:
  

  // print the results to the serial monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  if (sensorValue>220 && outputValue>50){
     digitalWrite(buzz,HIGH);     // Buzzer will be in ON state  
     delay(20);
     myservo.write(0);
  }
  else if(sensorValue<220 && outputValue<50){
   digitalWrite(buzz,LOW);
   myservo.write(90);
  }
 }
 
