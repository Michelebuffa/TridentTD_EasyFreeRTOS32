/ *************************************************** ****
  *
  * Blink_func
  *
  * This task will perform Order flashing lights
  * Can adjust flashing quickly, slowly as scheduled
  *
  * Note
  * Within the task, use all capital letters DELAY ()
  *
  **************************************************** ** /

#define BLINK_LED_PIN       2
#define DEFAULT_BLINK_DELAY 1000

// Task Share Variables Info
// xBlink_Dalay: For external tasks, you can set the blink speed in this task.
  
void Blink_func(void* arg){  // Blink_task launch here
  VOID SETUP(){                       // VOID SETUP () in the task using uppercase
    pinMode(BLINK_LED_PIN,OUTPUT);
    if( xBlink_Delay <= 0) xBlink_Delay = DEFAULT_BLINK_DELAY;
  }

  VOID LOOP() {                       // VOID LOOP() in the task using uppercase
    digitalWrite(BLINK_LED_PIN,HIGH);
    DELAY(xBlink_Delay);              // DELAY(..) in the task using uppercase
    digitalWrite(BLINK_LED_PIN,LOW);
    DELAY(xBlink_Delay);
  }
}

