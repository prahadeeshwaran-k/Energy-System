//🛜wifi provisioning Headers to connect to networks👀
#include "WiFi.h"
//🕒⌛Time get from the internet📅
#include "time.h"
#include "sntp.h"
//🔥📡📈 Firebase Headers💸
#include <Firebase_ESP_Client.h>
#include <addons/TokenHelper.h>// Provide the token generation process info.
#include <addons/RTDBHelper.h>// Provide the RTDB payload printing info and other helper functions.
//💾🗃️SD Lib Header with SPI🛹
#include "FS.h"
#include "SD.h"
#include "SPI.h"
//⚡💡🔌PZEM Current & Voltage Sensor Lib
#include <PZEM004Tv30.h>
//🔢🧮 16X Analog multiplexer Lib
#include <CD74HC4067.h>

//📚contains all declaration constants
#include"constants.h"


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


#define API_KEY "AIzaSyBq41YVU3zq_0zgIPO7-T-joK3ogz3eoQM"//🗝️ Define the API Key 
#define DATABASE_URL "https://prj-energy-sys-default-rtdb.asia-southeast1.firebasedatabase.app/" //🔗 Define the RTDB URL

// Define the 🦰user 📧Email & 🔐password that alreadey registerd or added in your project
#define USER_EMAIL "ritsucks@mail.com"
#define USER_PASSWORD "12345678"
//Pzem UART Pin Connection
#define PZEM_RTDB_RX_PIN 16//for esp32s3 17 w->17
#define PZEM_RTDB_TX_PIN 17//for esp32s3 18 g->18
#define PZEM_SERIAL_RTDB Serial2


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//📦 Define Firebase,PZEM Data object
//🔥FireBase Object
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
unsigned long sendDataPrevMillis = 0;
//⚡PZEM Object
PZEM004Tv30 pzem(PZEM_SERIAL_RTDB, PZEM_RTDB_RX_PIN, PZEM_RTDB_TX_PIN);


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//🧩 Function Prototyping 🛠️ 
void WifiSetup();
void TimeSetup();
void timeavailable(struct timeval *t);
void LocalTime();
void TaskRTDBmain();
void FirebaseSetup();
void SDSetup();
void appendFile(fs::FS &fs, const char * path, const char * message);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//⚙️ SETUP FUNCTION RUN ONLY ONCE
void setup() {
  Serial.begin(115200);
  while(!Serial && !Serial.available()){} //vTaskDelay(pdMS_TO_TICKS(500));
  WifiSetup();
  Serial.println("Wi-Fi connected");//need to replace led indication 
  TimeSetup();
  FirebaseSetup();
  SDSetup();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//♾️ LOOP FUNCTION
void loop() {
  TaskRTDBmain();
  appendFile(SD, "/hello.txt", "World!\n");
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

