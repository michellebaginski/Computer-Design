/* Lab 9: Using Arduino with Processing
 * The code will map values read from a photoresistor and a potentiometer to a graph using processing.
 * References: https://learn.sparkfun.com/tutorials/connecting-arduino-to-processing#introduction
 * https://www.arduino.cc/en/Tutorial/Graph
 * https://learn.adafruit.com/experimenters-guide-for-metro/circ08-using%20the%20arduino%20serial%20plotter
 */

#define potentiometer A1
#define photoresistor A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("PO"+String(analogRead(potentiometer))); // send from the potentiometer
  delay(10);
  Serial.println("PH"+String(analogRead(photoresistor))); // send from the photoresistor
  delay(10);
}
