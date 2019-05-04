/* Michelle Baginski; mbagin3; 676954872
 * Lab 9: Using Arduino with Processing
 * The code will map values read from a photoresistor and a potentiometer to a graph using processing.
 * References: https://learn.sparkfun.com/tutorials/connecting-arduino-to-processing#introduction
 * https://www.arduino.cc/en/Tutorial/Graph
 * https://learn.adafruit.com/experimenters-guide-for-metro/circ08-using%20the%20arduino%20serial%20plotter
 */
 
import processing.serial.*;
Serial myPort;  
String read, input;  // change val to read
int xPos = 1, start, end;
float photoresistor, potentiometer, p_photoresistor, p_potentiometer;

void setup(){
  size(1000,1000);
  background(255);       
  String portName = Serial.list()[7];
  myPort = new Serial(this, portName,9600);
  myPort.bufferUntil('\n');
}

void draw(){
  // draw the line for the potentiometer read
  stroke(100, 150, 220);
  line(xPos-1, height - p_potentiometer, xPos, height - potentiometer); 
  p_potentiometer= potentiometer;
  
  // draw the line for the photo resistor read
  stroke(255, 100, 75); 
  line(xPos-1, height - p_photoresistor, xPos, height - photoresistor); 
  p_photoresistor = photoresistor;
  
  if(xPos >= width){
    xPos = 1;
    background(255);
  }
  else{
    xPos++;
  }
}

void serialEvent(Serial myPort){
    read = myPort.readStringUntil('\n');
    if (read != null) {
      // read from the potentiometer
      if (read.substring(0,2).equals("PO")) {  
      start = 2;
      end = read.length()-1;
      input = read.substring(start, end); 
      potentiometer = map(float(input), 0, 1023, 0, height);
      }
      // read from the photoresistor
      if (read.substring(0,2).equals("PH")) { 
        start = 2;
        end = read.length()-1; 
        input = read.substring(start, end);
        photoresistor = map(float(input), 0, 1023, 0,height); 
    } 
 } 
}
