/*
 * create custom function for generating play file names
 */

#include <Arduino.h>
using namespace std;
#include <string>

//Pound defines linking alarm number with hour prefix
#define ALARM_1 (18)

// Declare sampel number;
int sampleNumber = 0;

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

// construct playback file name from an hour + sample number (e.g. 18TKP1.WAV)
const char * makeFileName(int hr, int samp){
    std::string concat = std::to_string(hr) + "TKP" + std::to_string(samp) + ".WAV";
    const char * result = concat.c_str(); //convert string to pointer
    return result;  
}

//Fake playFile function
void playFile(const char string[]){
  Serial.print("Now playing ");
  Serial.println(string);
}

// ALARM FUNCTIONS
// Audio file 1
void startPlayingAlarm1() {
  printAndLog("Alarm1");
  playFile(makeFileName(18, sampleNumber));

  /*
  if (sampleNumber == 1){
    playFile("18TKP1.WAV");  // filenames are always uppercase 8.3 format
    }
  else if (sampleNumber == 2){
    playFile("18TKP2.WAV");
    } 
  else if (sampleNumber == 3){
    playFile("18TKP3.WAV");
    }
  else if (sampleNumber == 4){
    playFile("18TKP4.WAV");
    }
  else {
    printAndLog("sampleNumber did not register. Default = 1");
    playFile("18TKP1.WAV");
  }
  */

  delay(250);
}

void setup()  {
  Serial.begin(9600);
  delay(500);
  Serial.println("Setup Loop complete");
  delay(500);
}

void loop() {
  for ( int i = 1; i < 5; i++)
  {
    sampleNumber = i;
    Serial.println(customAdd("sampleNumber is = ", sampleNumber));
    startPlayingAlarm1();
    delay(500);
  }
  delay(1000);
}
