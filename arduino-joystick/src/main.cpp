/* ********************************************************************
 * Arduino - Joystick
 * A program to read the values of a joystick
 * Based on Rachel De Barros Tutorial
 https://youtu.be/9z5FsTzYWE4?feature=shared
 * Version A
 * *******************************************************************/


#include <Arduino.h>

#define XPIN A0
#define YPIN A1
#define BPIN 2

int x_val;
int y_val;
int button_state;


void setup() {
  Serial.begin(9600);
  pinMode(XPIN, INPUT);
  pinMode(YPIN, INPUT);
  pinMode(BPIN, INPUT_PULLUP);
}

void loop() 
{
  x_val = analogRead(XPIN);
  y_val = analogRead(YPIN);
  button_state = digitalRead(BPIN);
  
  // X: XXXX | Y: YYYY | Button: 0/1
  Serial.print("X: ");
  Serial.print(x_val);
  Serial.print(" | Y: ");
  Serial.print(y_val);
  Serial.print(" | Button: ");
  Serial.println(button_state);
  //Serial.print('\n')
  delay(100);
}
