/*
 * create a function that allows you to break down time strings
 * and access the hr min and sec as integers.
 */

#include <Arduino.h>
using namespace std;
#include <string>
#include <array>

//Pound defines linking alarm number with hour prefix
#define ALARM_1 "12:00:56"
#define ALARM_2 (19)
#define ALARM_3 (20)
#define ALARM_4 (21)
#define ALARM_5 (22)
#define ALARM_6 (23)
#define ALARM_7 (0)
#define ALARM_8 (1)
#define ALARM_9 (2)
#define ALARM_10 (3)
#define ALARM_11 (4)
#define ALARM_12 (5)

#define ALARM_1_FILENAME "18TKP1.WAV"

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
    std::string hour = "00";
    if (hr < 10){
      hour = "0" + std::to_string(hr);
    }
    else {
      hour = std::to_string(hr);
    }
    
    std::string concat = hour + "TKP" + std::to_string(samp) + ".WAV";
    const char * result = concat.c_str(); //convert string to pointer
    return result;  
}

//Fake playFile function
void playFile(const char string[]){
  Serial.print("Now playing ");
  Serial.println(string);
}

std::array<int,3> timeConstruct(std::string timeString){
  std::array<int,3> timeInts;
  std::string hrString = timeString.substr(0,2);
  std::string minString = timeString.substr(3,4);
  std::string secString = timeString.substr(6,7);
  timeInts[0] = stoi(hrString);
  timeInts[1] = stoi(minString);
  timeInts[2] = stoi(secString);

  return timeInts;
}

// ALARM FUNCTIONS
// Audio file 1
void startPlayingAlarm1() {

  std::array<int,3> timeIntegers = timeConstruct(ALARM_1);
  Serial.println("Alarm Time hour: ");
  Serial.println(timeIntegers[0]);
  Serial.println("Alarm Time min: ");
  Serial.println(timeIntegers[1]);
  Serial.println("Alarm Time sec: ");
  Serial.println(timeIntegers[2]);

  printAndLog("Alarm1");
  to_string(timeIntegers[0]);
  playFile(ALARM_1_FILENAME);

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
  startPlayingAlarm1();
  delay(5000);
}
