
#include <Servo.h>. 


const int trigPin = 10;
const int echoPin = 11;

// Variabile pentru timp si distanta
long duration;
int distance;

Servo myServo; 

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
  myServo.attach(12); 
}
void loop() {
  // roteste servo motorul intre 15 si 165 de grade
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();// Apeleaza o functie care calculeaza distanta
  //Vom trimite niste date catre serial port care ne vor folosii mai tarziu pentru interfata grafica
if (distance <40)
{tone(13,5000-i*100);} else {noTone(13);}
  Serial.print(i); // Sends the current degree into the Serial Port
  Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  Serial.print(distance); // Sends the distance value into the Serial Port
  Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  }
  // Repeats the previous lines from 165 to 15 degrees
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  if (distance <40)
{tone(13,5000-i*100);} else {noTone(13);}
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}
// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}