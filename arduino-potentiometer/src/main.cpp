/* ********************************************************************
 * Arduino Potentiometer
 * A Program to Adjust the brightness of an LED light using the values
 of a potentionmeter (Code modified from Michalis Vasilakis 24/10/2014)
 * Version A
 * *******************************************************************/
#include <Arduino.h>

//PINS:
#define LED 9  //pin 9 has PWM funtion
#define POT A0 //pin A0 to read analog input

//Variables:
int value; //save analog value


void setup()
{
  //Input or output?
  pinMode(LED, OUTPUT); 
  pinMode(POT, INPUT); //Optional 
}

void loop()
{
  value = analogRead(POT);          //Read and save analog value from potentiometer
  value = map(value, 0, 1023, 0, 255); //Map value 0-1023 to 0-255 (PWM)
  analogWrite(LED, value);          //Send PWM value to led
  delay(100);                          //Small delay
}