#include <SoftPWM.h>
#include <SoftPWM_timer.h>

// INPUT: Potentiometer should be connected to 5V and GND
int potPin = A5; // Potentiometer output connected to analog pin 6
int potVal = 0; // Variable to store the input from the potentiometer
int percentage = 0; // Variable to store the PWM percentage

int Redpin = 2;
int Orangepin = 4; 
int Yellowpin = 5;
int Greenpin = 6;
int Bluepin= 9;  
int Purplepin = 10;
int Greypin = 12;
int Whitepin = 13;

void setup()
{
  pinMode(Yellowpin, OUTPUT);
  pinMode(Greenpin, OUTPUT);
  pinMode(Bluepin, OUTPUT);
  pinMode(Purplepin, OUTPUT);

  // Initialize
  SoftPWMBegin();

  // Create and set pin 12 and 13 to 0 (off)
  SoftPWMSet(2, 0);
  SoftPWMSet(4, 0);
  SoftPWMSet(12, 0);
  SoftPWMSet(13, 0);

  SoftPWMSetFadeTime(2, 0, 0); // red
  SoftPWMSetFadeTime(4, 0, 0); // orange
  SoftPWMSetFadeTime(12, 0, 0); // grey
  SoftPWMSetFadeTime(13, 0, 0); // white
  
  Serial.begin(9600);
}

// Main program
void loop()
{
  potVal = analogRead(potPin);   // read the potentiometer value at the input pin

  if (potVal <= 113)
  {
    potVal = map(potVal, 0, 113, 0, 255);
    percentage = map(potVal, 0, 255, 0, 100);
    SoftPWMSetPercent(2, percentage);
  }
  else if (potVal <= 227)
  {
    potVal = map(potVal, 114, 227, 0, 255);
    percentage = map(potVal, 0, 255, 0, 100);
    SoftPWMSetPercent(2, 100 - percentage);
    SoftPWMSetPercent(4, percentage);
  }
  else if (potVal <= 340)
  {
    potVal = map(potVal, 228, 340, 0, 255);
    percentage = map(potVal, 0, 255, 0, 100);
    SoftPWMSetPercent(4, 100 - percentage);
    analogWrite(Yellowpin, potVal);
  }
  else if (potVal <= 453)
  {
    potVal = map(potVal, 341, 453, 0, 255); 
    analogWrite(Yellowpin, 255 - potVal);
    analogWrite(Greenpin, potVal);
  }
  else if (potVal <= 566)
  {
    potVal = map(potVal, 453, 566, 0, 255); 
    analogWrite(Greenpin, 255 - potVal);
    analogWrite(Bluepin, potVal);
  }
  else if (potVal <= 679)
  {
    potVal = map(potVal, 567, 679, 0, 255); 
    analogWrite(Bluepin, 255);
    analogWrite(Purplepin, potVal);
  }
  else if (potVal <= 792)
  {
    potVal = map(potVal, 680, 792, 0, 255); 
    analogWrite(Bluepin, 255);
    analogWrite(Purplepin, 255 - potVal);
  }
  else if (potVal <= 905)
  {
    potVal = map(potVal, 793, 905, 0, 255); 
    percentage = map(potVal, 0, 255, 0, 100);
    analogWrite(Bluepin, 255 - potVal);
    SoftPWMSetPercent(12, percentage);
  }
  else if (potVal <= 1018)
  {
    potVal = map(potVal, 906, 1018, 0, 255); 
    percentage = map(potVal, 0, 255, 0, 100);
    SoftPWMSetPercent(12, 100-percentage);
    SoftPWMSetPercent(13, percentage);
  }
}
