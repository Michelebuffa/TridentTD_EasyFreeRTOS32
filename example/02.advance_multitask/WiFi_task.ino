/ *************************************************** ****
  *
  * WiFi_func
  *
  * This task will connect to WiFi only.
  * If the Wi-Fi is disconnected, skip to Blink_task to blink rapidly
  *
  * Note
  * Within the task, use all capital letters DELAY ()
  *
  **************************************************** **** /

#include <WiFi.h>

#define WIFI_SSID           "---------"
#define WIFI_PASSWORD       "---------"
#define WIFI_INTERVAL       2           // (minutes) time to check the next Wi-Fi status

void WiFi_func(void*){  
  // ---- Space for declaring variables used within this task only ----

  //-----------------------------------------------

  VOID SETUP(){                       // VOID SETUP() In the task, use uppercase
    WiFi.begin( WIFI_SSID, WIFI_PASSWORD );
  }
  VOID LOOP(){                        // VOID LOOP() In the task, use uppercase
    if( !WiFi.isConnected() ) {
      // Order Blink_task to blink light every 80 ms
      xBlink_Delay = 80;  //ms
      Blink_task.start( Blink_func );
  
      while(!WiFi.isConnected() ) DELAY(400);
      Serial.print("[WiFi] WiFi Connected, IP : ");
      Serial.println(WiFi.localIP());
      
      // Sang the Blink Task has stopped working after connecting to Wi-Fi
      Blink_task.stop();  

      // instruct AsyncWebServer_task to start
      AsyncWebServer_task.start(AsycWebServer_func);
    }
    
    DELAY( WIFI_INTERVAL *60000); // Check the wifi status every few minutes
  }
}

