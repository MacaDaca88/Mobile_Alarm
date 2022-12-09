#include <IRremote.h>
/*
   PIR sensor tester
*/
int RECV_PIN = 9;
int blue = A2;                   // choose the pin for the blue LED
int red = A0;                   // choose the pin for the red LED
int green = A1;               // choose the pin for the green LED
int siren = 10;
int inputPin = 11;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
int brightness = 0;            // how bright the LED is starting
int fadeAmount = 5;           // how many points to fade the LED by
long randNumber;               // introduce randomizer

IRrecv irrecv(RECV_PIN);
decode_results results;
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(red, OUTPUT);      // declare LED as output
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(siren, OUTPUT);
  pinMode(inputPin, INPUT);     // declare sensor as input
}

void loop() {

  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {

    digitalWrite(red, HIGH);
    digitalWrite(blue, LOW);// turn LED ON
    digitalWrite(siren, HIGH);
    delay(200);
    digitalWrite(red, LOW);
    digitalWrite(blue, HIGH);// turn LED ON
    digitalWrite(siren, LOW);
    delay(200);
    digitalWrite(red, HIGH);
    digitalWrite(blue, LOW);// turn LED ON
    digitalWrite(siren, HIGH);
    delay(200);
    digitalWrite(red, LOW);
    digitalWrite(blue, HIGH);// turn LED ON
    digitalWrite(siren, LOW);
    delay(200);
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
       digitalWrite(red, HIGH);
        digitalWrite(green, HIGH);
    digitalWrite(blue, HIGH);// turn LED ON
    digitalWrite(siren, LOW);
    
    if (pirState == HIGH) {
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
}
