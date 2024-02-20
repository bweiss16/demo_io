/*
 * create function to read in all configuratoins from seperate file
 * note that variables here, at top of file are instantiated but not declared
 */

#include <Arduino.h>
#include <SD.h>
#include <SDConfig.h>

// STATIC CONFIGS FOR SD
// SDCARD_SS_PIN is defined for the built-in SD on some boards.
#ifndef SDCARD_SS_PIN
const uint8_t SDCARD_CS_PIN = SS; //SS Teensy 4.1
#else  // SDCARD_SS_PIN
const uint8_t SDCARD_CS_PIN = 10; //CS pin should be 10 w our config of audio shield
#endif  // SDCARD_SS_PIN
// Other
#define SDCARD_MOSI_PIN  7
#define SDCARD_SCK_PIN   14

//SDConfig Settings
const char * fileName = "config.cfg";
int maxLineLength = 30;
SDConfig cfg;

//instantiate vars that will be filled in by config file
//Alarm times
char *ALARM_1;
char *ALARM_2;
char *ALARM_3;
char *ALARM_4;
char *ALARM_5;
char *ALARM_6;
char *ALARM_7;
char *ALARM_8;
char *ALARM_9;
char *ALARM_10;
char *ALARM_11;
char *ALARM_12;
// Wake Time
int startH;
int startM;
int startS;
// Play Time (first alarm) [18:0:0 for real]
int playH;
int playM;
int playS;
// Sleep Time
int stopH;
int stopM;
int stopS;
//other
char *SAMPLE_LOCATION; 
int BAUDE_RATE;

//config function
void getSettings(){
  if(cfg.begin(fileName, maxLineLength)){
    Serial.println("Config file opened."); 
    while (cfg.readNextSetting()) {
      if(cfg.nameIs("ALARM_1")){
        ALARM_1 = cfg.copyValue();
      }
      else if (cfg.nameIs("ALARM_2")) {
        ALARM_2 = cfg.copyValue();
      }
      else if(cfg.nameIs("ALARM_3")){
        ALARM_3 = cfg.copyValue();
      }
      else if (cfg.nameIs("ALARM_4")) {
        ALARM_4 = cfg.copyValue();
      }
      else if(cfg.nameIs("ALARM_5")){
        ALARM_5 = cfg.copyValue();
      }
      else if (cfg.nameIs("ALARM_6")) {
        ALARM_6 = cfg.copyValue();
      }
      else if(cfg.nameIs("ALARM_7")){
        ALARM_7 = cfg.copyValue();
      }
      else if(cfg.nameIs("ALARM_8")){
        ALARM_8 = cfg.copyValue();
      }
      else if (cfg.nameIs("ALARM_9")) {
        ALARM_9 = cfg.copyValue();
      }
      else if(cfg.nameIs("ALARM_10")){
        ALARM_10 = cfg.copyValue();
      }
      else if (cfg.nameIs("ALARM_11")) {
        ALARM_11 = cfg.copyValue();
      }
      else if (cfg.nameIs("ALARM_12")) {
        ALARM_12 = cfg.copyValue();
      }
      else if(cfg.nameIs("SAMPLE_LOCATION")){
        SAMPLE_LOCATION = cfg.copyValue();
      }      
      else if(cfg.nameIs("BAUDE_RATE")){
        BAUDE_RATE = cfg.getIntValue();
      }
      else if(cfg.nameIs("startH")){
        startH = cfg.getIntValue();
      }
      else if(cfg.nameIs("startM")){
        startM = cfg.getIntValue();
      }
      else if(cfg.nameIs("startS")){
        startS = cfg.getIntValue();
      }                   
      else if(cfg.nameIs("playH")){
        playH = cfg.getIntValue();
      }
      else if(cfg.nameIs("playM")){
        playM = cfg.getIntValue();
      }
      else if(cfg.nameIs("playS")){
        playS = cfg.getIntValue();
      }
      else if(cfg.nameIs("stopH")){
        stopH = cfg.getIntValue();
      }
      else if(cfg.nameIs("stopM")){
        stopM = cfg.getIntValue();
      }
      else if(cfg.nameIs("stopS")){
        stopS = cfg.getIntValue();
      }            
      else{
      }
    }
    cfg.end();
  }
  Serial.println("Could not open config file.");
}

void setup()  {
  Serial.begin(9600);
  delay(500);
  
  // Config file Read setup
  Serial.print("Initializing SD card...");
  if (!SD.begin(SDCARD_CS_PIN)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("SD initialization succeeded.");
   
  // get settings from file
  getSettings();
  
  // Print results
  Serial.println("Loaded configuration values:");
  Serial.println((String)"ALARM_1 is = " + ALARM_1);
  Serial.println((String)"ALARM_9 is = " + ALARM_9);
  Serial.println((String)"SAMPLE_LOCATION is = " + SAMPLE_LOCATION);
  Serial.println((String)"startH is = " + startH);

  Serial.println("Setup Loop complete");
  delay(500);
}

void loop() {
  //Do nothing
}
