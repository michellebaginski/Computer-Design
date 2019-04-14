/* Lab 8 - Interrupts with LCD
 * The code initially starts counting seconds waiting from 0. 
 * When the first button is pressed it will go to state 1 and prompt for the
 * second button to be pressed.
 * In this state, the code will then again count seconds waiting from time 0.
 * References used: https://www.arduino.cc/en/Tutorial/LiquidCrystalScroll
 */
 
int sec = 0;
boolean wait_time = true;
#define BUTTON_1 3 // button 1 is on pin 3
#define BUTTON_2 2 // button 2 is on pin 2
#include <LiquidCrystal.h> // library for LCD
LiquidCrystal lcd(12, 11, 5, 4, 8, 7);  // pins attached to the LCD

void setup() { 
  pinMode(BUTTON_1, INPUT);
  pinMode(BUTTON_2, INPUT);
  lcd.begin(16, 2); // initialize the LCD  
  lcd.setCursor(0, 0); // col, row
  attachInterrupt(digitalPinToInterrupt(3), state1, RISING);
  attachInterrupt(digitalPinToInterrupt(2), waiting, RISING);
}

void loop() {
  state0();
}

// prints the time waiting
void state0() {
  sec = 0;
  while (wait_time) {
    lcd.setCursor(0, 0);
    lcd.print("Waiting: ");
    String seconds = String(sec);
    lcd.setCursor(9, 0);
    lcd.print(seconds);
    lcd.setCursor(0, 1);
    lcd.print("seconds");
    delay(1000);
    sec++;
  }
}

void waiting() {
  lcd.clear();
  sec = 0;
  wait_time = true; // turn the counter on
}

// code that will interrupt
void state1() {
  wait_time = false;  // turn the counter off
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Interrupted!");
  lcd.setCursor(0, 1);
  lcd.print("Press BUTTON 2");
}
