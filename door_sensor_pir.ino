#include <IRremote.h>
/*
   PIR sensor tester
*/
int RECV_PIN = 10;
int blue = A2;                   // choose the pin for the blue LED
int red = A0;                   // choose the pin for the red LED
int green = A1;               // choose the pin for the green LED
int siren = 9;
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
void ir() {

  if (irrecv.decode(&results)) {
    switch (results.value) {
      case 0xFFA25D: Serial.println("CH-");
        analogWrite(red, 255);
        analogWrite(blue, 0);
        analogWrite(green, 255);
        break;
      case 0xFFE21D: Serial.println("CH+");
        analogWrite(red, 255);
        analogWrite(blue, 0);
        analogWrite(green, 0);
        break;
      case 0xFF629D: Serial.println("CH");

        analogWrite(red, 255);
        analogWrite(blue, 255);
        analogWrite(green, 0);
        delay(5000);
        break;
      case 0xFF906F: Serial.println("EQ");

        break;
      case 0xFFE01F: Serial.println("-");

        break;
      case 0xFF22DD: Serial.println("PREVIOUS");


        break;
      case 0xFF02FD: Serial.println("NEXT");


        break;
      case 0xFFC23D: Serial.println("PLAY");

        break;
      case 0xFFA857: Serial.println("+");


        break;
      case 0xFF6897: Serial.println("0");

        break;
      case 0xFF9867: Serial.println("100+");

        break;
      case 0xFFB04F: Serial.println("200+");

        break;
      case 0xFF30CF: Serial.println("1");

        break;
      case 0xFF18E7: Serial.println("2");

        break;
      case 0xFF7A85: Serial.println("3");

        break;
      case 0xFF10EF: Serial.println("4");

        break;
      case 0xFF38C7: Serial.println("5");

        break;
      case 0xFF5AA5: Serial.println("6");

        break;
      case 0xFF42BD: Serial.println("7");

        break;
      case 0xFF4AB5: Serial.println("8");

        break;
      case 0xFF52AD: Serial.println("9");

    }
    irrecv.resume();
    analogWrite(red, 255);
    analogWrite(blue, 255);
    analogWrite(green, 255);
  }
  delay(10);

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
    ir();

    if (pirState == HIGH) {
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
}
