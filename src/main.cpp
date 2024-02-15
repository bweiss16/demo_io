#include <Arduino.h>

#define BLINK_DELAY 250
int led = 13;
int n = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  }

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(BLINK_DELAY);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(BLINK_DELAY);               // wait for a second
  Serial.println(sin(2*n*3.14/20));
  n++;
}