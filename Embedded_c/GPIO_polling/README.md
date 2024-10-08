1.3. GPIO Ports Configure to Input with Interrupt:
Lab Experiment 8: Write a program Request an interrupt on the Falling edge of ENTER Switch, whenever the user 
button is pressed and increment a counter in the interrupt and RED LED is ON.

Lab Experiment 9: Write an Embedded C Program Whenever SW_UP press RED LED is ON, whenever SW_DN press 
GREEN LED is ON using Falling edge GPIO interrupt.

Lab Experiment 10: Write an Embedded C Program to measure interrupt latency. By default RED LED (-ve Logic 
Level) is ON. Whenever ENT SWITCH (-ve Logic Level) is press RED LED is OFF.

2. Mini Project: 16x2 Monochrome LCD Interface:
GPIO Pin Pin function Device
PB0 GPIO LCD_DATA_4
PB1 GPIO LCD_DATA_5
PB2 GPIO LCD_DATA_6
PB3 GPIO LCD_DATA_7
PB4 GPIO LCD_RS
PB5 GPIO LCD_RW
PB8 GPIO LCD_EN
Interview Questions
What is Interrupt Latency?
Interrupt latency is the time that elapses from when an interrupt is generated to when the source of the 
interrupt is serviced. For many operating systems, devices are serviced as soon as the device's interrupt 
handler is executed. Interrupt latency may be affected by microprocessor design, interrupt 
controllers, interrupt masking, and the operating system's (OS) interrupt handling methods
How to measure interrupt latency?
To measure a time interval, like interrupt latency, with any accuracy, requires a suitable instrument. The 
best tool to use is an oscilloscope. One approach is to use one pin on a GPIO interface to generate the 
interrupt. This pin can be monitored on the ‘scope. At the start of the interrupt service routine, another 
pin, which is also being monitored, is toggled. The interval between the two signals may be easily read from 
the instrument.
How to reduce interrupt latency?
To reduce interrupt latency ARM Cortex M4 introduce new feature “tail chain”
ARM Cortex M4 processor reduces interrupt latency using tail-chain