
/*
 * PIR sensor tester
 */
 
int copblue = A2; // choose the pin for the LED
int copred = A0;
int naturalgreen = A1;
int siren = 10;
int inputPin = 11;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
int brightness = 0;            // how bright the LED is starting
int fadeAmount = 5;           // how many points to fade the LED by
long randNumber;               // introduce randomizer

void setup() {
   Serial.begin(9600);
  pinMode(copred, OUTPUT);      // declare LED as output
   pinMode(copblue, OUTPUT); 
   pinMode(naturalgreen, OUTPUT);
   pinMode(siren, OUTPUT);
  pinMode(inputPin, INPUT);     // declare sensor as input 
}
 
void loop(){
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {

    digitalWrite(copred, HIGH); 
    digitalWrite(copblue, LOW);// turn LED ON
    digitalWrite(siren, HIGH);
    delay(200);
       digitalWrite(copred, LOW); 
    digitalWrite(copblue, HIGH);// turn LED ON
      digitalWrite(siren, LOW);
    delay(200);
        digitalWrite(copred, HIGH); 
    digitalWrite(copblue, LOW);// turn LED ON
      digitalWrite(siren, HIGH);
    delay(200);
       digitalWrite(copred, LOW); 
    digitalWrite(copblue, HIGH);// turn LED ON
      digitalWrite(siren, LOW);
    delay(200);
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else { 
    analogWrite(copred, 255);
 analogWrite(copblue, 255);// turn LED OFF
analogWrite(naturalgreen, 255);
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
  
}
