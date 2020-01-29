/ *************************************************** ****
 *
 * AsycWebServer_func
 *
 * This task will create the Asynchronous WebServer.
 * WebServer doesn't have to wait for any client to contact
 * Run until the end of the process for the next client to use
 * Makes Multitask work more fluid than usual
 *
 * Note
 * Within the task, use all capital letters DELAY ().
 * The library creates an Asynchronous WebServer to install both libraries.
 * https://github.com/me-no-dev/AsyncTCP
 * https://github.com/me-no-dev/ESPAsyncWebServer
 *
 **************************************************** ** /

#include <ESPAsyncWebServer.h>

AsyncWebServer server(80);

void AsycWebServer_func(void*) {
 // ---- Space for declaring variables used within this task only ----

  //-----------------------------------------------
  VOID SETUP() {                      // VOID SETUP () in the task using uppercase
    server.on("/heap", HTTP_GET, [](AsyncWebServerRequest * request) {
      request->send(200, "text/plain", String(ESP.getFreeHeap()));
    });
    
    server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
      char buf[50];
      sprintf(buf, "<H2>Temp  : %.2f<br>\nHumid : %.2f<br></H2>\n", xDHT_temp, xDHT_humid);      
      request->send(200, "text/html", String(buf));
    });
    
    server.onNotFound([](AsyncWebServerRequest * request) {
      Serial.println("[AsyncWebServer] Page NOT FOUND ");
      request->send(404, "text/plain", "Page not found");
    });

    Serial.println("[AsyncWebServer] start!");
    Serial.printf ("[AsyncWebServer] Open http://%s on the browser.\n", WiFi.localIP().toString().c_str());
    server.begin();
  }

  VOID LOOP() {                        // VOID LOOP () in the task using uppercase
    DELAY(1);                          // DELAY (..) in the task, use uppercase
  }
}

