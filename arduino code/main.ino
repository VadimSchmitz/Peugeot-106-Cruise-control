#include <Servo.h>  // add servo library
Servo myservo; 
int val;   

#define POT_PIN 0
#define POWER_PIN 12
#define BUTTON_PIN 7

byte lastButtonState = LOW;
byte powerState = LOW;

unsigned long debounceDuration = 50; // millis
unsigned long lastTimeButtonStateChanged = 0;

void setup() {
  Serial.begin(9600);
  
  myservo.attach(11);  
  pinMode(POT_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(POWER_PIN, OUTPUT);
}

void loop() {
  if (millis() - lastTimeButtonStateChanged > debounceDuration) {
    byte buttonState = digitalRead(BUTTON_PIN);
    if (buttonState != lastButtonState) {
      lastTimeButtonStateChanged = millis();
      lastButtonState = buttonState;
      if (buttonState == LOW) {
        powerState = (powerState == HIGH) ? LOW: HIGH;
        Serial.println(powerState);
        if (powerState == 0){digitalWrite(POWER_PIN, LOW);};
        if (powerState == 1){digitalWrite(POWER_PIN, HIGH);};
      }
    }
  }
  val = analogRead(POT_PIN);            
  val = map(val, 1023, 0, 180, 0);     
  myservo.write(val);                
  delay(100);  
  Serial.println(powerState);
}

