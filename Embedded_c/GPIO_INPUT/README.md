1.2. GPIO Ports Configure to Input with Polling:
Lab Experiment 3: Whenever SW_UP is pressed RED LED is ON, whenever SW_DN is pressed GREEN LED is ON.
Assign breakpoints after if condition and click run button in debugger window. Whenever SW1/SW2 presses 
program stops at any one of the breakpoint.
 
Lab Experiment 4: Use “SW_ENT” and declare “counter” global variable. Your program should increment counter
by one, every time switch is pressed. Note how the value of counter changes on each “ENTER SWITCH” press. Use 
debugger and add Counter to “Watch Expression” window. Does the value of counter increment by one always?
Note: Define counter as a global variable and in debug perspective use continuous refresh option (You will find 
Continuous Refresh button on top of the Expression Window). You can use step debugging or breakpoints to check 
the variable value.

Hint: To add variable to Expression Window, select and right click the variable name and select “Add Watch 
Expression”. To view Expression Window, click on View button from Keil menu bar and select Expressions.
Embedded C & RTOS [STM32 Controller] Lab Assignments

Lab Experiment 5: Whenever ENTER SWITCH is Press toggle RED LED.

Lab Experiment 6: Read SW_ENT, if switch is press RED LED is ON otherwise RED LED is OFF. Note that RED LED 
should remain ON for the duration switch is kept pressed i.e. RED LED should turn OFF when switch is released.

Lab Experiment 7: Whenever SW_ENT Press turn ON BUZZER up to 250msec and Turn OFF BUZZER.
