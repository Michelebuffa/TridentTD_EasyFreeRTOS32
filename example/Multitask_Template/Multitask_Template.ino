/ *
 * TridentOS standard specifications
 * - In the main setup (), there is nothing else.
 * In addition to calling the desired task to work
 * - In the main loop (), there is no other operation at all
 * - Each task has its own VOID SETUP () and VOID LOOP () By using a big print
 * And if using DELAY (..), always use uppercase
 * - In a single task, can call other tasks to work
 * For example, can call task3.begin (task3_func); Can work from within task1
 * - If the task will be stopped after work
 * For example, to stop the task3, use the command task3.stop ();
 * - If wanting to resume working, call task3.resume ();
 * - Variables used to share between standard tasks. Always use the lowercase x in front.
 * /
       
#include <TridentTD_EasyFreeRTOS32.h>

TridentOS   task1, task2, task3, task4, task5;    // declare task variable
void  task1_func(void*), task2_func(void*),       // The function that the task will launch
      task3_func(void*), task4_func(void*), task5_func(void*);

// ---- This area is for declaring variables to share data between tasks ------


//---------------------------------------------------------

void setup(){  // setup () digits using lowercase
  Serial.begin(115200); Serial.println();

  task1.start( task1_func );  // calling task1_func up and running
  task2.start( task2_func );	// call task2_func up and running
}

void loop(){}  // loop () digits use lowercase
