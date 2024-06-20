/* Logging the number of tips since reset
   
  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

*/

// Which pin would I like to read?
int tip_pin = 7;

// initialize the tip_counter at 0
int counter = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  // initialize the digital pin we want to read for tips
  pinMode(tip_pin, INPUT);

  // set that pin High
  digitalWrite(tip_pin, HIGH);

  // start communication with serial terminal
  Serial.begin(115200);

}

// the loop function runs over and over again forever
void loop() {

  // read the tip_pin
  int switch_cond = digitalRead(tip_pin);

  // when the switch_cond is NOT high increment the counter by 1
  if (!switch_cond) {
    counter += 1;
    
    // turn the LED on when the switch cond is on (needs the ! since 
    // reed switch is normally closed)
    digitalWrite(LED_BUILTIN, HIGH);  

    // delay 1 millisecond (as recommended by HOBO)
    delay(500);
  }
  // Set the LED low
  digitalWrite(LED_BUILTIN, LOW);
  // print the tip counter to the serial port
  Serial.println(counter);


}


