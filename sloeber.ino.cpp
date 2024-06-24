#ifdef __IN_ECLIPSE__
//This is a automatic generated file
//Please do not modify this file
//If you touch this file your change will be overwritten during the next build
//This file has been generated on 2024-06-24 16:16:16

#include "Arduino.h"
#define LILYGO_T5_V22
#include <Adafruit_GFX.h>
#include <boards.h>
#include <GxEPD.h>
#include <SD.h>
#include <FS.h>
#include <AceButton.h>
#include <Fonts/FreeMono9pt7b.h>
#include <Fonts/Org_01.h>
#include <Fonts/FreeSansBold9pt7b.h>
#include "Font5x7Fixed.h"
#include <WiFiManager.h>
#include <hebrewcalendar.h>
#include <GxDEPG0290B/GxDEPG0290B.h>
#include GxEPD_BitmapExamples
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>
#include <WiFi.h>
#include "time.h"

bool setupSDCard(void) ;
void configModeCallback (WiFiManager *myWiFiManager) ;
void testSpeaker() ;
void resetTask(void *pvParameter) ;
void printLocalTime();
void setup() ;
void loop() ;
void EnterSleep() ;
void calendarTask(void *pvParameter) ;
void updateTime(struct tm *timeinfo) ;
bool isleap(int year) ;
int mthdays(int month, int year) ;
void ShowCalendar2(struct tm *timeinfo) ;


#include "RCal.ino"

#endif
