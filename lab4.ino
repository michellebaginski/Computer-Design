/* Lab4
 * Description: A photoresister will capture different ranges of light and display them on the LCD.
 * References for the circuit: http://playground.arduino.cc/Learning/PhotoResistor
 */
 
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // pins attached to the LCD
const int pResistor = A0; // Photoresistor at Arduino analog pin A0
int value;                // Store value from photoresistor (0-1023)

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2); // initialize the LCD  
  lcd.setCursor(0, 0); // col, row
  pinMode(pResistor, INPUT);// Set pResistor - A0 pin as an input (optional)
}

void loop(){
  value = analogRead(pResistor);  // read the resistor value
  Serial.println(value);
  // 0-400 is considered the darkest
  if (value <= 400) { 
    lcd.print("DARK");
  } 
  else if (value > 400 && value <= 470) {
    lcd.print("PARTIALLY DARK");
  }
  else if (value > 470 && value <= 550) {
    lcd.print("MEDIUM");
  }
  else if (value > 550 && value <= 870) {
    lcd.print("PARTIALLY LIGHT");
  }
  else if (value > 870){
   lcd.print("FULLY LIT");
  }
  
  delay(500);
  lcd.clear();  // reset the screen for the next read
}
