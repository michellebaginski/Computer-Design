Lab1: 
Use the onboard LED on pin 13, a red LED on a second digital pin of your choice and a green LED on a third
digital pin of your choice.
Have these three LED’s cycle so only one LED is on at any given point in time. So your onboard LED should turn
on, then it should turn off and your red LED should turn on, then it should turn off and your green LED should turn
on, then onboard, then red, then green, etc . . .


Lab2:
Use two switches and three LEDS for the circuit. One switch will increment a 3-bit count. The other switch will decrement
the 3-bit count. The 3-bit count will be displayed on the three LEDs in binary (a 1 is LED on).
You should write code to keep track of the number of button presses and algorithmically convert that
number to a binary output. Your code should NOT just be implementing a giant lookup table to translate
to binary, and solutions which do so will not receive credit.
Your lights should increment (or decrement) by one each time the switch is pressed. If we continually
depress the switch, the lights should not run up (or down) to 7 (or 0) (i.e. it should only change the value once per 
button press).


Lab3:
Display your name and your favorite quote to appear on the 16x2 LCD. Name on the first line, quote on the second line.
The quote should not all fit on the screen and so should scroll across the screen. Your name should not scroll across the 
screen, only the quote should scroll.


Lab4:
Your design will incorporate the light sensitive resistor photocell and display relevant information about the photocell 
value onto the 16x2 display.
Create a circuit and program that will use a photoresistor and the 16x2 display.
The display should state the relative amount of light in the room as one of 5 predefined text values based on the value 
read from the photocell. 

The 5 predefined text values are:
  - dark
  - partially dark
  - medium
  - partially light
  - fully lit 

This involves you determining the range of values the photoresistor provides and then making reasonable ranges for the 
values being considered.


Lab5: 
1. Use 4 LEDS and a photoresistor. Put all 4 LEDS next to eachother (preferably the same color). As the amount of light 
seen by the photoresistor decreases, increase the number of LEDS that are lit. For example, if your circuit recieves no 
light at all, then all 4 LEDS should illuminate. As you continue to increase the amount of light, the number of LEDS on
should decrease. So, when the photoresistor recieves half the amount of light, 2 LEDS should light up. When there is no 
light,all 4 LEDS should light up.

2. In parallel with part 1, you will be using the passive buzzer and the potentiometer. Use the potentiometer as an analog 
input and have the output come from another analog pin. Control the volume or tone of the buzzer by adjusting the 
potentiometer. Make sure to have code to control the output of the buzzer based on the potentiometer.
A servo-motor can be used in place of the buzzer.


Lab7: 
For this lab:
  - Connect two Arduino's via a hardwired serial connection (no usb cable) (digital pins 0 and 1).
  - Connect a button and an external LED to each device.
  - Pressing the button on one Arduino should cause the other Arduino's LED to change state (on to off, or off to on).
  - Button press on one Arduino should toggle the state of the LED on the other (on/off) and not keep the LED lit while 
    being pressed.
  - Utilize the 16x2 display for debugging.
  - Refer to lab 6 for all the info about serial communication and lab2 for maintaining led states with button presses.
  - Both boards have to share the same ground in order for the serial communication to work properly. -
  
The same code MUST run on both Arduinos.


Lab8: 
Write a program for the Arduino that utilizes interrupts. Interrupts allow a section of Arduino code to be called without 
writing code in the loop( ) function to explicitly check that code.
The lab is to have you use 2 buttons and the 16x2 LCD display. Each button is to trigger an interrupt. 
The interrupts are to toggle between two states/messages displayed on the 16x2 LCD.

- When no button has been pressed your 16x2 display should say something like "We have been waiting for X seconds", where 
  X starts at the value 0 and is updated as time goes on. This is State 0.
- When the first button is pressed, the display should display “Interrupt received! Press button 2 to continue”. This is 
  State 1.
- When the user presses the second button, the display goes back to displaying "We have been waiting for X seconds", and 
  restarts the time at 0 seconds. (I.E. go back to State 0.) -
  
Important note: You must use pin 2 and pin 3 for this lab. Those two pins are specifically set up to work with interrupts.


Lab9:
Connect two analog devices to the arduino and plot the data received on the computer using processing.
Data could be displayed in two separate graphs or both on one graph.

Some analog devices that you might already have include:
  - potentiometer
  - thermal sensitive resistor
  - photo resistor
  - force sensitive resistor
