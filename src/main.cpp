/*
 * Trying to develop a function that combines an integr anda string in C++
 * I've also chagned printAndLog to expect char string[] as opposed to const char string[]
 * since this input IS changing
 */

#include <Arduino.h>
using namespace std;
#include <string>

// Initialize counter
int i = 0;

// Wrap logging and serial print into a single function
void printAndLog(const char string[]){
  Serial.println(string);
  //logSD(string); //commented out for now because no SD connected
  }

// Add an integer to a string
const char * customAdd(std::string string, int b){
    std::string concat = string + std::to_string(b);
    const char * result = concat.c_str(); //convert string to pointer
    return result;  
}

void setup()  {
  Serial.begin(9600);
  Serial.println("Setup Loop ran");
  delay(500);
}

void loop() {
  printAndLog(customAdd("Integer is ", i));
  i++;
  delay(200);
}
