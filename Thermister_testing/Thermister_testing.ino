//https://roboindia.com/tutorials/arduino-nano-analog-input/
//https://www.circuitbasics.com/arduino-thermistor-temperature-sensor-tutorial/

int ThermistorPin = A7;   //connected to analog pin of arduino
int Vo;                     //potential difference declaration 
float R1 = 2400;               // pre defined resistance 
float logR2, R2, T;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup() {
Serial.begin(9600);
}

void loop() {

  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15;
  T = (T * 9.0)/ 5.0 + 32.0; // convert in to degree forenheight
 

  Serial.print("Temperature: "); 
  Serial.print(T);
  Serial.println(" f"); // output in forenheight

  delay(500);
}
