/*
    LilyGo Ink Base Calendar with the hebrew holidays
        - Created by Ronen K
*/

// According to the board, cancel the corresponding macro definition
// #define LILYGO_T5_V213
 #define LILYGO_T5_V22
// #define LILYGO_T5_V24
// #define LILYGO_T5_V28
// #define LILYGO_T5_V102
// #define LILYGO_T5_V266
// #define LILYGO_EPD_DISPLAY_102
// #define LILYGO_EPD_DISPLAY_154

#include <Adafruit_GFX.h>
#include <boards.h>
#include <GxEPD.h>
#include <SD.h>
#include <FS.h>
#include <AceButton.h>    //https://github.com/bxparks/AceButton
#include <Fonts/FreeMono9pt7b.h>

#include <Fonts/Org_01.h>
#include <Fonts/FreeSansBold9pt7b.h>
#include "Font5x7Fixed.h"
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager WiFi Configuration Magic

#include <hebrewcalendar.h>

using namespace         ace_button;

#if defined(LILYGO_T5_V102) || defined(LILYGO_EPD_DISPLAY_102)
#include <GxGDGDEW0102T4/GxGDGDEW0102T4.h> //1.02" b/w
#elif defined(LILYGO_T5_V266)
#include <GxDEPG0266BN/GxDEPG0266BN.h>    // 2.66" b/w   form DKE GROUP
#elif defined(LILYGO_T5_V213)
#include <GxDEPG0213BN/GxDEPG0213BN.h>    // 2.13" b/w  form DKE GROUP
#else
// #include <GxGDGDEW0102T4/GxGDGDEW0102T4.h> //1.02" b/w
// #include <GxGDEW0154Z04/GxGDEW0154Z04.h>  // 1.54" b/w/r 200x200
// #include <GxGDEW0154Z17/GxGDEW0154Z17.h>  // 1.54" b/w/r 152x152
// #include <GxGDEH0154D67/GxGDEH0154D67.h>  // 1.54" b/w
// #include <GxDEPG0150BN/GxDEPG0150BN.h>    // 1.51" b/w   form DKE GROUP
// #include <GxDEPG0266BN/GxDEPG0266BN.h>    // 2.66" b/w   form DKE GROUP
// #include <GxDEPG0290R/GxDEPG0290R.h>      // 2.9" b/w/r  form DKE GROUP
 #include <GxDEPG0290B/GxDEPG0290B.h>      // 2.9" b/w    form DKE GROUP
// #include <GxGDEW029Z10/GxGDEW029Z10.h>    // 2.9" b/w/r  form GoodDisplay
// #include <GxGDEW0213Z16/GxGDEW0213Z16.h>  // 2.13" b/w/r form GoodDisplay
// #include <GxGDE0213B1/GxGDE0213B1.h>      // 2.13" b/w  old panel , form GoodDisplay
// #include <GxGDEH0213B72/GxGDEH0213B72.h>  // 2.13" b/w  old panel , form GoodDisplay
// #include <GxGDEH0213B73/GxGDEH0213B73.h>  // 2.13" b/w  old panel , form GoodDisplay
// #include <GxGDEM0213B74/GxGDEM0213B74.h>  // 2.13" b/w  form GoodDisplay 4-color
// #include <GxGDEW0213M21/GxGDEW0213M21.h>  // 2.13"  b/w Ultra wide temperature , form GoodDisplay
// #include <GxDEPG0213BN/GxDEPG0213BN.h>    // 2.13" b/w  form DKE GROUP
// #include <GxGDEW027W3/GxGDEW027W3.h>      // 2.7" b/w   form GoodDisplay
// #include <GxGDEW027C44/GxGDEW027C44.h>    // 2.7" b/w/r form GoodDisplay
// #include <GxGDEH029A1/GxGDEH029A1.h>      // 2.9" b/w   form GoodDisplay
// #include <GxDEPG0750BN/GxDEPG0750BN.h>    // 7.5" b/w   form DKE GROUP
#endif

#include GxEPD_BitmapExamples

// FreeFonts from Adafruit_GFX
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>
#include <WiFi.h>

#include "time.h"

GxIO_Class io(SPI,  EPD_CS, EPD_DC,  EPD_RSET);
GxEPD_Class display(io, EPD_RSET, EPD_BUSY);

WiFiManager wifiManager;

AceButton btn1(BUTTON_1, HIGH);
#ifdef BUTTON_2
AceButton btn2(BUTTON_2, HIGH);
#endif
#ifdef BUTTON_3
AceButton btn3(BUTTON_3, HIGH);
#endif
bool rlst = false;

const char DaysOfTheMonth[7][10]={"Sunday","Monday","Tuesday","Wednsday","Thursday","Friday","Saturday"};

const char hebrewHolidaysNames[58][22]={"CHOL","Pesach Day 1","Pesach Day 2","Shvei shel pesach","Achron shel pesah","Shavuot Day 1","Shavuot Day 2",
		"Rosh hashanah 1","Rosh hashanah 2","Yom Kippur","Sukot day 1","Sukot day 2","Shmeni Atzeret","Simchat Tora","pesach hol 1","pesach hol 2",
		"Pesach hol 3","Pesach hol 4","Pesach hol 5","Sukot hol 1","Sukot hol 2","Sukot hol 3","Sukot hol 4","Sukot hol 5","Hoshana Rabah","Pesach 2","Lag Ba Omer","Tu Be Av",
		"Chanukah 1","Chanukah 2","Chanukah 3","Chanukah 4","Chanukah 5","Chanukah 6","Chanukah 7","Chanukah 8","Tu Bi Shvat","Purim Katan","Sushan Purim Katan",
		"Purim","Shushan Purim","Shiva Asar Be Tamuz","Tisha Be Av","Tzom Gdalia","Asarah be tevet","Taanit Ester","Pesach Erev","Shavuot Erev","Rosh Hashanah Erev",
		"Yom Kippur Erev","Sukot Erev","","","","","","",""};

#define RCAL_HEADER 30
#define RCAL_DAY	38

const GFXfont *regularFont = &FreeMono9pt7b;
//const GFXfont *font2 = &prazo_Regular_218pt7b;
const GFXfont *tinyFont = &Org_01;

const GFXfont *boldFont = &FreeSansBold9pt7b;
const GFXfont *regularSmallFont = &Font5x7Fixed;

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 2L*60L*60L; //Israel time
const int   daylightOffset_sec = 3600;

int32_t iCalendarOffset = 0;
volatile bool bUpdating=false;

TaskHandle_t resetTaskHandle = NULL;

void EnterSleep();

bool setupSDCard(void)
{
   return SD.begin(SDCARD_CS);
}

void configModeCallback (WiFiManager *myWiFiManager) {
  Serial.println("Entered config mode");
  Serial.println(WiFi.softAPIP());

  Serial.println(myWiFiManager->getConfigPortalSSID());

  display.setRotation(0);
  display.fillScreen(GxEPD_WHITE);

  display.setTextColor(GxEPD_BLACK);

  display.setFont(boldFont);
  display.setCursor(0, 20);
  display.print("Configure\nusing the\nWIFI portal:\n");
  display.print(myWiFiManager->getConfigPortalSSID());

  display.update();
  display.setFont();

}


void testSpeaker()
{
#if defined(_HAS_SPEAKER_)
#ifdef _HAS_PWR_CTRL_
    pinMode(SPK_POWER_EN, OUTPUT);
    digitalWrite(SPK_POWER_EN, HIGH);
#endif
    ledcSetup(LEDC_CHANNEL_0, 1000, 8);
    ledcAttachPin(SPERKER_PIN, LEDC_CHANNEL_0);
    int i = 3;
    while (i--) {
        ledcWriteTone(LEDC_CHANNEL_0, 1000);
        delay(200);
        ledcWriteTone(LEDC_CHANNEL_0, 0);
    }
#ifdef _HAS_PWR_CTRL_
    pinMode(SPK_POWER_EN, INPUT);
#endif
    ledcDetachPin(SPERKER_PIN);
#endif
}

void resetTask(void *pvParameter)
{
	const TickType_t xDelay = (20*1000) / portTICK_PERIOD_MS; //20 Seconds

	struct tm localtimeinfo;

    while (1)
    {
    	vTaskDelay( xDelay );
    	if(!bUpdating){
    		getLocalTime(&localtimeinfo);
    		iCalendarOffset = 0;
    		ShowCalendar2(&localtimeinfo);
    		vTaskDelete(resetTaskHandle);
    		resetTaskHandle=NULL;
    		return;
    	}
    }
}

static void aceButtonHandleEventCb(ace_button::AceButton *b, uint8_t event, uint8_t state)
{
	struct tm *timeinfo;
	time_t rawtime;

	time(&rawtime);

    Serial.printf("Pin:%d event:%u state:%u\n", b->getPin(), event, state);

    if (event != AceButton::kEventClicked && event != AceButton::kEventLongPressed) {
        return;
    }

    switch (b->getPin()) {
    case BUTTON_1:

    	iCalendarOffset+=7 * 24 * 60 * 60; // 7 days in seconds;
        rawtime -= iCalendarOffset;

    	timeinfo = localtime(&rawtime);

    	ShowCalendar2(timeinfo);

    	if(resetTaskHandle!=NULL){
    		vTaskDelete(resetTaskHandle);
    		resetTaskHandle = NULL;
    	}

    	xTaskCreatePinnedToCore(resetTask, "resetTask", 2048, NULL, 1, &resetTaskHandle, 0);
        break;
    case BUTTON_2:
    	timeinfo = localtime(&rawtime);
    	iCalendarOffset = 0;
    	ShowCalendar2(timeinfo);
        break;

    case BUTTON_3:
        // Add 7 days to the current time
    	iCalendarOffset+=7 * 24 * 60 * 60; // 7 days in seconds;
        rawtime += iCalendarOffset;
        timeinfo = localtime(&rawtime);

   		ShowCalendar2(timeinfo);

   		if(resetTaskHandle!=NULL){
   			vTaskDelete(resetTaskHandle);
   			resetTaskHandle = NULL;
   		}

   		xTaskCreatePinnedToCore(resetTask, "resetTask", 2048, NULL, 1, &resetTaskHandle, 0);

        break;

    default:
        break;
    }
}

void printLocalTime(){
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  Serial.print("Day of week: ");
  Serial.println(&timeinfo, "%A");
  Serial.print("Month: ");
  Serial.println(&timeinfo, "%B");
  Serial.print("Day of Month: ");
  Serial.println(&timeinfo, "%d");
  Serial.print("Year: ");
  Serial.println(&timeinfo, "%Y");
  Serial.print("Hour: ");
  Serial.println(&timeinfo, "%H");
  Serial.print("Hour (12 hour format): ");
  Serial.println(&timeinfo, "%I");
  Serial.print("Minute: ");
  Serial.println(&timeinfo, "%M");
  Serial.print("Second: ");
  Serial.println(&timeinfo, "%S");

  Serial.println("Time variables");
  char timeHour[3];
  strftime(timeHour,3, "%H", &timeinfo);
  Serial.println(timeHour);
  char timeWeekDay[10];
  strftime(timeWeekDay,10, "%A", &timeinfo);
  Serial.println(timeWeekDay);
  Serial.println();
}

void setup() {
	WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP

	Serial.begin(115200);
	Serial.setDebugOutput(true);
	Serial.println("setup");

	SPI.begin(EPD_SCLK, EPD_MISO, EPD_MOSI);
	display.init();
	display.setRotation(0);

	display.setFont(boldFont);
	display.setTextColor(GxEPD_BLACK);
	display.setCursor(0, 20);
	display.print("Connecting\nto wifi...");

	display.update();
	display.setFont();

	pinMode(BUTTON_1, INPUT);
	btn1.init(BUTTON_1);
	ButtonConfig *buttonConfig = btn1.getButtonConfig();
	buttonConfig->setEventHandler(aceButtonHandleEventCb);

	buttonConfig->setFeature(ButtonConfig::kFeatureClick);

	buttonConfig->setFeature(ButtonConfig::kFeatureLongPress);

#ifdef BUTTON_2
	pinMode(BUTTON_2, INPUT);
	btn2.init(BUTTON_2);
	buttonConfig = btn2.getButtonConfig();
	buttonConfig->setEventHandler(aceButtonHandleEventCb);

	buttonConfig->setFeature(ButtonConfig::kFeatureClick);
#endif

#ifdef BUTTON_3
	pinMode(BUTTON_3, INPUT_PULLUP);
	btn3.init(BUTTON_3);
	buttonConfig = btn3.getButtonConfig();
	buttonConfig->setEventHandler(aceButtonHandleEventCb);
	buttonConfig->setFeature(ButtonConfig::kFeatureClick);

#endif

	wifiManager.setAPCallback(configModeCallback);

	bool res = wifiManager.autoConnect("RCalendar");

	if (!res) {
		Serial.println("Failed to connect or hit timeout");
		// ESP.restart();
	} else {
		//WiFi.localIP().toString();
		//if you get here you have connected to the WiFi
		Serial.println("connected...yeey :)");

		// Init and get the time
		configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
		printLocalTime();
	}

	//testSpeaker();

	rlst = setupSDCard();

    xTaskCreatePinnedToCore(calendarTask, "calTask", 2048, NULL, 1, NULL, 0);
}

void loop()
{
    btn1.check();
#ifdef BUTTON_2
    btn2.check();
#endif
#ifdef BUTTON_3
    btn3.check();
#endif
}

void EnterSleep()
{
    Serial.println("EnterSleep");
    delay(2000);
    esp_sleep_enable_ext1_wakeup(((uint64_t)(((uint64_t)1) << BUTTON_1)), ESP_EXT1_WAKEUP_ALL_LOW);
    esp_deep_sleep_start();
}


int iPrevMinute=0;
int iPrevHour = 0;
void calendarTask(void *pvParameter)
{
	const TickType_t xDelay = 500 / portTICK_PERIOD_MS;
	struct tm timeinfo;

    while (1)
    {
    	getLocalTime(&timeinfo);
    	if(iPrevMinute!=timeinfo.tm_min && !bUpdating){

    		iPrevMinute = timeinfo.tm_min;
    		updateTime(&timeinfo); //update just the time

    	}

    	if(iPrevHour!=timeinfo.tm_hour && !bUpdating){ //update the whole day every hour to prevent fading of the text
    		iPrevHour =timeinfo.tm_hour;
    		ShowCalendar2(&timeinfo);
    	}

    	vTaskDelay( xDelay );
    }
}

void updateTime(struct tm *timeinfo) {
	char szBuffer[10];
	bUpdating = true;
	display.setRotation(0);

	display.fillRect(0, 13, display.width(), 16, GxEPD_WHITE);
	display.updateWindow(0, 13, display.width(), 16, true);
	display.setCursor(84, 22);
	display.setFont(boldFont);
	display.setTextColor(GxEPD_BLACK);
	strftime(szBuffer, sizeof(szBuffer), "%R", timeinfo); //Time
	display.print(szBuffer);
	//display.print("22:28");

	display.updateWindow(0, 13, display.width(), 16, true);
	display.setFont();
	bUpdating = false;
}

const unsigned char epd_bitmap_holidays_back [] PROGMEM = {
	0xaa, 0xbf, 0xff, 0xf0, 0x55, 0x7f, 0xff, 0xf0, 0xaa, 0xff, 0xff, 0xf0, 0x55, 0xff, 0xff, 0xf0,
	0xab, 0xff, 0xff, 0xf0, 0x57, 0xff, 0xff, 0xf0, 0xaf, 0xff, 0xff, 0xf0, 0x5f, 0xff, 0xff, 0xf0,
	0xbf, 0xff, 0xff, 0xf0, 0x7f, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xf0,
	0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xf0,
	0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xd0,
	0xff, 0xff, 0xff, 0xa0, 0xff, 0xff, 0xff, 0x50, 0xff, 0xff, 0xfe, 0xa0, 0xff, 0xff, 0xfd, 0x50,
	0xff, 0xff, 0xfa, 0xa0, 0xff, 0xff, 0xf5, 0x50, 0xff, 0xff, 0xea, 0xa0, 0xff, 0xff, 0xd5, 0x50
};

bool isleap(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int mthdays(int month, int year)
{
    static const int days[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };
    int leap = isleap(year);

    return days[leap][month];
}

void ShowCalendar2(struct tm *timeinfo) {
	int16_t x1, y1;
	uint16_t w, h;
	uint16_t box_w = display.width() - 20, box_h = display.height() / 2 + 20;
	uint16_t box_x = 10, box_y = 10;
	String str = "Calendar";
	char szBuffer[20];
	struct tm localtimeinfo;

	bUpdating=true;

	getLocalTime(&localtimeinfo);

	display.setRotation(0);
	display.fillScreen(GxEPD_WHITE);

	display.setTextColor(GxEPD_BLACK);
	uint16_t offset_y1 = 0, offset_y2 = 0, offset_y3 = 0, offset_y4 = 0;


	//timeinfo.tm_mday day of the month
	//tm_wday

	//int firstDay = (timeinfo->tm_mday)-(timeinfo->tm_wday+1); //+1 for sunday to be the first day

	//int daysInMonth = mthdays(timeinfo->tm_mon, timeinfo->tm_year+1900);
	int textY;
	bool bMonthAdjusted = false;
	char szNumbers[5];

	//
	time_t tTime = mktime(timeinfo); // get the time that was passed to us
	tTime-=((timeinfo->tm_wday)*24 * 60 * 60); //Subtract till we get sunday
	struct tm *timeinfoDay;
	timeinfoDay = localtime(&tTime);
	//Header
	display.setFont(boldFont);
	display.setCursor(0, 12);
	strftime(szBuffer, sizeof(szBuffer), "%B", timeinfoDay); //month
	display.print(szBuffer);
	//display.print(timeinfo.tm_year);
	display.setCursor(87, 12);
	strftime(szBuffer, sizeof(szBuffer), "%Y", timeinfoDay); //year
	display.print(szBuffer);
	display.setCursor(83, RCAL_HEADER - 3);
	strftime(szBuffer, sizeof(szBuffer), "%R", timeinfo); //Time
	display.print(szBuffer);


	for (int i = 0; i < 7; i++) { //Days of the week
		timeinfoDay = localtime(&tTime);


		textY = i * (RCAL_DAY) + RCAL_HEADER;
		if (i < 7) { //horizontal lines
			display.drawFastHLine(0, textY, display.width(), GxEPD_BLACK);
		}

		//Day accents
		if(i==5 || i==6){ //satruday -firday
			display.drawBitmap(epd_bitmap_holidays_back, 0, textY + 10, 28, 28, GxEPD_WHITE, 0);
		}

		if (timeinfoDay->tm_mday == localtimeinfo.tm_mday && timeinfoDay->tm_mon == localtimeinfo.tm_mon) { //current day, Warning not included year
				display.fillRect(0, textY + 10, RCAL_DAY - 10, RCAL_DAY - 9,
						GxEPD_BLACK);
				display.setTextColor(GxEPD_WHITE);

		}


		//Day number

		if(timeinfoDay->tm_mon!=localtimeinfo.tm_mon ){
			if(!bMonthAdjusted){
				bMonthAdjusted = true;
				//timeinfo->tm_mon+=1;
				display.setFont(boldFont);
				display.setCursor(0, RCAL_HEADER - 3); //another month, this is dual month week
				strftime(szBuffer, sizeof(szBuffer), "/%B", timeinfoDay); //month
				display.print(szBuffer);
			}

		}

		hdate hebrewDate = convertDate(*timeinfoDay);
		int yomtov = getyomtov(hebrewDate);
		bool bRoshHodesh = getroshchodesh(hebrewDate)==ROSH_CHODESH;

		display.setFont(boldFont);
		display.setCursor(3, textY + 29);
		sprintf(szNumbers, "%2d", timeinfoDay->tm_mday);
		display.print(szNumbers);

		if (timeinfoDay->tm_mday == localtimeinfo.tm_mday && timeinfoDay->tm_mon == localtimeinfo.tm_mon) { //current day
			display.setTextColor(GxEPD_BLACK);
		}


		//Day name
		display.setFont(tinyFont);
		display.setCursor(0, textY + 6);
		display.print(DaysOfTheMonth[i]);

		//Still in tiny font
		display.setCursor(70, textY + 6);
		if(bRoshHodesh){
			display.print("Rosh Hodesh");
		}

		if(yomtov!=0){
			display.setFont(regularSmallFont);
			display.setCursor(31, textY + 20);
			display.print(hebrewHolidaysNames[yomtov]);
		}

		//Other stuff
		display.drawFastVLine(28, textY + 10, RCAL_DAY - 10, GxEPD_BLACK);


		tTime+=24 * 60 * 60; // 1 days in seconds, increment by one day

	}

	//display.drawFastHLine(0,display.height()/2,display.width(),GxEPD_BLACK);

	display.update();
	display.setFont();
	display.updateWindow(0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, false);

	bUpdating=false;
}
