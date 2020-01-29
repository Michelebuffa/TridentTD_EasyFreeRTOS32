
void myblink(void*){          // The first task launches here.
  // ---- Space for declaring variables used within this task only ----

  //-----------------------------------------------

  VOID SETUP(){               // Same as setup () but with the name SETUP () in uppercase instead
    Serial.println("Hello Blink Task");  
    pinMode(2,OUTPUT);
  }
  
  VOID LOOP() {               // Same as loop () but with the name LOOP () in uppercase instead
    digitalWrite(2,HIGH);
    DELAY(1000);              // Same as delay (..) but with the name as DELAY (..) capitalized instead
    digitalWrite(2,LOW);
    DELAY(1000);
  }
}

