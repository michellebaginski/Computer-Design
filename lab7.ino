/* Lab 7: Communicating two arduinos
 *Two arduinos are serially hardwired and pressing the button on one arduino causes the LED for the other arduino to light up, vice versa.
 * References: 
 * https://www.arduino.cc/en/serial/read
 * https://iotguider.in/arduino/serial-communication-between-two-arduino-boards/
 */

int val1, val2;
int LED = 12;   // LED connected to digital pin 12
int BUTTON = 7; // button connected to digital pin 7

void setup() {
  pinMode(LED, OUTPUT); 
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);

}

void loop() {
  // initial read from the button
  val1 = digitalRead(BUTTON);  

  // button is read as pressed
  if (val1 == 1) {
    delay(50);  // delay for debouncing
    val2 = digitalRead(BUTTON);
    if (val2 == 0) {
       Serial.write("Pressed");
    }
  }

  if(Serial.available() > 0 && Serial.read() != -1) {
     if (digitalRead(led) == LOW) {
      digitalWrite(led, HIGH);
    }
    else {
      digitalWrite(led, LOW);
    }
  }

}
