#include <TridentTD_EasyFreeRTOS32.h>

TridentOS   task1, task2;  // Create as many tasks as possible
void myblink(void*), myprint(void*); // Function name that task will launch

// ---- This area is for declaring variables to share data between tasks ------

//---------------------------------------------------------

void setup() {
  Serial.begin(115200); Serial.println();
  task1.start( myblink );     // Start the first task, call myblink to work
  task2.start( myprint );     // Start the second task, run myprint
}

void loop() {}                // No need to use anymore, but with

