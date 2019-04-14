/* Lab 3 - LCD display scroll
 * The code displays my name in row 0 and a scrolling quote in row 1.
 * References used: https://www.arduino.cc/en/Tutorial/LiquidCrystalScroll
 */

#define WIDTH 16
#include <LiquidCrystal.h> // library for LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // pins attached to the LCD
//LiquidCrystal lcd(12, 11, 5, 4, 8, 7);  // pins attached to the LCD
String my_name = "MichelleBaginski";
String quote = "Think positively like a proton ";
int str_len = quote.length();
int start_str, end_str, num_processed = 0;

void setup() { 
  lcd.begin(WIDTH, 2); // initialize the LCD  
  lcd.setCursor(0, 0); // col, row
  lcd.print(my_name);  // display name (static)
}

void loop() {
  // cursor starts at the right most part of the lcd for the initial scroll
  if (num_processed <= WIDTH) {
    lcd.setCursor(WIDTH-num_processed, 1);  // cursor will move from right to left 1 each iteration
    lcd.print(quote.substring(start_str, num_processed));   // display the appropriate amount of characters
  }
  // first 16 char have been scrolled, now display the rest of the substring
  if (num_processed > WIDTH && num_processed <= str_len+WIDTH) {
    start_str++;
    end_str++;
    lcd.setCursor(0, 1);
    lcd.print(quote.substring(start_str, num_processed));
  }
  // all the characters have been displayed, reset the scroller to default and repeat
  if (num_processed == 16*3) {
    num_processed = 0;
    start_str = 0;
    end_str = 0;
  }
  else {
    num_processed++;  // characters displayed so far
  }
  delay(400);
}
