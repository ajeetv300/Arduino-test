const int ledPin =D1;
const int ldrPin =A0;
const int buzzer =D2;
const int IR=D3;

void setup() 
{

Serial.begin(9600);

pinMode(ledPin, OUTPUT);
pinMode(ldrPin, INPUT);
pinMode(IR,INPUT);
  pinMode(buzzer, OUTPUT);

}

void loop() {

int ldrStatus = analogRead(ldrPin);
int IRStatus = digitalRead(IR);

if (ldrStatus >= 300) {

digitalWrite(ledPin, LOW);

Serial.print("Its Bright, Turn on the LED : ");

Serial.println(ldrStatus);
Serial.println(IRStatus);
       


} else {

digitalWrite(ledPin, HIGH);

Serial.print("Its BRIGHT, Turn off the LED : ");

Serial.println(ldrStatus);
 tone(buzzer, 1000); 
  delay(1000);       
  noTone(buzzer);    
  delay(1000);  

}

}
