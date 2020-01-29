/ *************************************************** *************
 *
 * DHT_func
 *
 * This task will perform Read DHT sensor values ​​only
 * There will be no other work being divided Absolutely work together, not mixed
 * The latest value of the DHT sensor is stored in the variable DHT_temp, DHT_humid.
 * Which other tasks can be used when needed
 *
 * Note
 * Within the task, use all capital letters DELAY ().
 * DHT libraries are used by Adafruit. To install these 2 libraries
 * https://github.com/adafruit/Adafruit_Sensor
 * https://github.com/adafruit/DHT-sensor-library
 *
 **************************************************** ************ /
 
#include <DHT.h>

#define DHT_PIN             5           // set pin pin
#define DHT_TYPE            DHT11      // Set type DHT11 or DHT22
#define DHT_INTERVAL        1000        // (ms) set the time period for repeat sensor readings

// Task Share Variables Info
// xDHT_temp: Latest temperature data for other tasks.
// xDHT_humid: Latest moisture data for other tasks is available.
  
void DHT_func(void*) {
  // ---- Space for declaring variables used within this task only ----
  DHT dht(DHT_PIN, DHT_TYPE);
  //-----------------------------------------------
  VOID SETUP() {                       // VOID SETUP() In the task, use uppercase
    Serial.println("[DHT] task begin");
    dht.begin();
  }

  VOID LOOP() {                       // VOID LOOP() In the task, use uppercase
    float t = NAN; float h = NAN;  
    while( isnan(t) || isnan(h) ) {
      t = dht.readTemperature();
      h = dht.readHumidity();
    }
    xDHT_temp = t;  xDHT_humid = h; // The value that has been read is correct and then copied to the latest variable
    Serial.printf("[DHT] temp : %.2f C\thumid : %.2f %%\n", xDHT_temp, xDHT_humid);
    
    DELAY(DHT_INTERVAL);              // Next loop to read the sensor again
  }
}

