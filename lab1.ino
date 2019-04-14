/* Lab1 - LED light
 * The code is going to flash 3 LED pins - only one should be on at a time so there will be a delay 
 * Alternating flashes using 2 external LED pins and one on board
 */

#define LED 13
#define RED 12
#define GREEN 8

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);  // turns the pin on
  delay(1000);              // delay
  digitalWrite(LED, LOW);   // turns the pin off
 
  digitalWrite(RED, HIGH);
  delay(1000);                 
  digitalWrite(RED, LOW); 

  digitalWrite(GREEN, HIGH);
  delay(1000);  
  digitalWrite(GREEN, LOW);
}
