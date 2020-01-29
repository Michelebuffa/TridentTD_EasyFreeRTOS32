
void myprint(void*){         // Task two, activate here
   // ---- Space for declaring variables used within this task only ----

  //-----------------------------------------------
  
  VOID SETUP(){              // Same as setup () but with the name as SETUP () in uppercase instead
    for(int i = 0; i <=20; ++i){
      Serial.println(random(1000));
      DELAY(300);             // Same as delay (..) but with the name as DELAY (..) capitalized instead
    }
    Serial.println("------------------------");
    Serial.println("END myprint Task");
  }

  VOID LOOP(){               // Same as loop () but with the name LOOP () in uppercase instead
    DELAY(1);
  }
}

