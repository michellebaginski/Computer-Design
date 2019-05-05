/* Lab 7: Communicating two arduinos
 *Two arduinos are serially hardwired and pressing the button on one arduino causes the LED for the other arduino to light up, vice versa.
 * References: 
 * https://www.arduino.cc/en/serial/read
 * https://iotguider.in/arduino/serial-communication-between-two-arduino-boards/
 */

int val1, val2; // values for reading button presses
int LED = 12;   // LEDs are connected to digital pin 12 on each arduino
int BUTTON = 7; // buttons connected to digital pin 7 on each arduino

void setup() {
  pinMode(LED, OUTPUT); 
  pinMode(BUTTON, INPUT);
  Serial.begin(9600); // open the serial port
}

void loop() {
  // initial read from the button
  val1 = digitalRead(BUTTON); 
  delay(50);  // delay for debouncing
  val2 = digitalRead(BUTTON);  // read the button again
  // if val1 and val2 are the same and they are both high, then the button was pressed
  if (val1 == val2 && val1 == HIGH) {
    Serial.write("Pressed");
  }

  // Serial.available() > 0 tells how many characters are available in the buffer to be read in
  // Serial.read() will read the first byte of incoming data, or -1 if it is not available
  if (Serial.available() > 0 && Serial.read() != -1) {
     if (digitalRead(LED) == LOW) { // if the light is not on, light it
      digitalWrite(LED, HIGH);
    }
    else {  // if the light is already on, turn it off
      digitalWrite(LED, LOW);
    }
  }
}
