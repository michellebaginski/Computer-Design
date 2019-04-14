/* Code integrates 2 switches and 3 LEDS that increment and decrement 3-bit counts
 * References used for circuitry: https://programmingelectronics.com/tutorial-17-using-a-button-old-version/
 * Note: When reaching above 7 or below 0, all 3 LEDS will shut off, and if incremented, then it will start
 *  again from count 0.
 *  When decremented < 0, the LEDS will loop back down counting from 7.
 */
 
#define RED 12      // represents 0th bit = 2^0
#define GREEN 8     // represents 1th bit = 2^1
#define YELLOW 9    // represents 2th bit = 2^2
#define BUTTON_I 4  // increment button
#define BUTTON_D 7  // decrement button

int i_status1, i_status2, d_status1, d_status2 = 0;  // records if the button is pressed or not
unsigned int num = 0;

void setup() {
  // initialize pins and buttons
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(BUTTON_I, INPUT);
  pinMode(BUTTON_D, INPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  // read initial inputs from both buttons 
  i_status1 = digitalRead(BUTTON_I);  
  d_status1 = digitalRead(BUTTON_D);
  delay(200); // delay to eliminate any "bounce"
  // read the input a second time
  i_status2 = digitalRead(BUTTON_I); 
  d_status2 = digitalRead(BUTTON_D);

  // increment button pressed
  if (i_status1 == i_status2 && i_status1 == HIGH) {
    num++;
    if (num > 7) { num = 0;}
  }
  // decrement button pressed
  else if (d_status1 == d_status2 && d_status1 == HIGH) {
    num--;
    if (num < 0) { num = 0; }
  }
  
  // zero out the LEDS per each input 
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);

  /* bitwise logical right-shift is preformed on the number's current value per button press 
   * checks the 0th, 1th and 2th bit to see which lights should be eliminated based on the values
  */
  // illuminates if the LSB is a 1
  if (num & 1) { 
    digitalWrite(RED, HIGH); 
    }
  // shifts right 1 binary digit and checks if 2^1 is a 1
  if ((num >> 1) & 1) { 
    digitalWrite(YELLOW, HIGH); 
    }
    // shifts right 2 binary digits and checks if 2^2 is a 1
  if ((num >> 2) & 1) { 
    digitalWrite(GREEN, HIGH); 
    }
    
}
