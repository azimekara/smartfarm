/*
  IRF520-MOSFET-Driver
  made on 28 oct 2020
  by Amir Mohammad Shojaee @ Electropeak
  Home

*/
#define PWM 3
int pot;
int out;

void setup() {
  Serial.begin(9600);
  pinMode(PWM,OUTPUT);
 
}
 
 
void loop() {
  out = 225;  // 72 yavas,100 orta,225 hizli
  analogWrite(PWM,out);
}
