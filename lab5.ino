/* Lab5
 * Description: As the amount of light seen by the photoresistor decreases, 
 * increase the number of LEDs that are lit.
 * Simultaneously, as the knob of a potentiometer is turned, the servo-motor will
 * be turning with it. Max it can move is 180 degrees.
 */

#include <Servo.h>
#define LED_1 13
#define LED_2 8
#define LED_3 10
#define LED_4 7

const int potPin = A1;    // potentiometer at analog pin A1
const int pResistor = A0; // photoresistor at analog pin A0
int pot_val, pr_val;
Servo servo_motor;

void setup() {
  Serial.begin(9600);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(pResistor, INPUT);
  pinMode(potPin, INPUT);
  servo_motor.attach(9);
}

void loop() {
  pr_val = analogRead(pResistor);
  pot_val = analogRead(potPin);
  // adjust the servo motor to move as the potentiometer values change
  servo_motor.write(pot_val/5.6);   // 1023 / 180 degrees
  
  Serial.println(pr_val);
  Serial.println(pot_val);

  // if there is none to very little lighting, all LEDS are on
  if (pr_val <= 205) {
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, HIGH);
  }
  else if (pr_val > 205 && pr_val <= 410) {
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, HIGH);
  }
  // intermediate light has some LEDS turn on
  else if(pr_val > 410 && pr_val <= 615) {
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_1, HIGH);
  }
  else if (pr_val > 615 && pr_val < 820) {
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_1, HIGH);
  }
  // all LEDS are off when there is a lot of light
  else if (pr_val >= 820) {
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_1, LOW);
  }

  delay(400);
}
