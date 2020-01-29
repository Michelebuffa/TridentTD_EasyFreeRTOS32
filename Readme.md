TridentTD_EasyFreeRTOS32 Library
===

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
TridentTD multitasking library on the ESP32 platform  

<p align="center">
  <img src="Picture.png" alt="image"/>
</p>  

### How to use

1.Run the library 
```c  
     #include <TridentTD_EasyFreeRTOS32.h>
``` 
2. Announcement of sub-task variables and functions that the task will call up  
```c  
     TridentOS   task1, task2, task3;
     void task1_func(void*), task2_func(void*), task3_func(void*);
```
3. The standard type of the sub-task function that will be called is as follows.
```c
    void task1_func(void*)  {   // Function that task1 activates - void uses lowercase
          // ---- Space for declaring variables used within this task only ----

          //-----------------------------------------------

          VOID SETUP() {  // VOID SETUP() In the task, use capital letters.

          }
          VOID LOOP() {   // VOID LOOP() In the task, use capital letters.

          }
    }

```
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
**note** 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
Within the task function, use delay with the DELAY command (..) in uppercase only.

4. If calling a task, for example, for task1, use the command  
```c
     task1.start(task1_func);
```
5. If going to stop which task, for example, for task1, use the command
```c
     task1.stop();
```
6. If you want to continue using which task, for example, for task1, use the command
```c
     task1.resume();
```

7. For data exchange between tasks, declare variables in
Variable notification area for sharing between tasks (see Template)
By having the standard for naming Variables for sharing between tasks. Begin with x (lowercase x).
```c
   // ------- Space for declaring shared variables between tasks ---------------
     float  xDHT_temp, xDHT_humid;    // has a small prefix x for easy observation
    //---------------------------------------------------------
```

### Tuning memory space for a task
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
Sometimes for the task of a task to be able to work more efficiently.
Sometimes we may need to adjust the memory space for a task to suit the use.
  
The method of adjusting memory space for a task can be adjusted with the following command.
```c
     task1.start(task1_func, NULL, 4096);  // Request to use the space 4096bytes
```


-----
** TridentTD **
24 May 2018 (the year of heavy rain)
5 days 7 screen years
Version 1.0

