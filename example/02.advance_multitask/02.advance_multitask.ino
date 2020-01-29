/ *******************************************************************
 * Example
 * - WiFi task: for managing WiFi
 * - DHT task: for reading DHT Sensor values only continuously
 * - Blink task: for flashing lights Depending on usage
 * - AsyncWebServer task: For creating Asynchonous WebServer.
 * Every time a Wifi connection is successful
 *
 * Note
 * Install all 4 libraries
 * library for Asynchronous WebServer
 * https://github.com/me-no-dev/AsyncTCP
 * https://github.com/me-no-dev/ESPAsyncWebServer
 *
 * library for DHT sensor
 * https://github.com/adafruit/Adafruit_Sensor
 * https://github.com/adafruit/DHT-sensor-library
 *
 ******************************************************************** /

#include <TridentTD_EasyFreeRTOS32.h>

// declare task and function variables for task
TridentOS   DHT_task, Blink_task, WiFi_task, AsyncWebServer_task;
void DHT_func(void*), Blink_func(void*), WiFi_func(void*), AsyncWebServer_func(void*);

// ---- This area is for declaring variables to share data between tasks ------
int     xBlink_Delay;    // set the speed of flashing lights (Standard, use x lead)
float   xDHT_temp;       // Temperature from DHT, the latest value that can be read (Standard, use x lead)
float   xDHT_humid;      // Moisture from DHT. The latest value that can be read. (Standard, use x lead)
//---------------------------------------------------------

void setup(){  // setup () lowercase digits
  Serial.begin(115200); Serial.println();
    
  DHT_task.start( DHT_func );
  WiFi_task.start( WiFi_func );  
}

void loop(){}  // loop (), lowercase digits Not needed, but always have

