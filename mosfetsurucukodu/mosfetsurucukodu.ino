/*
  IRF520-MOSFET-Driver
  made on 28 oct 2020
  by Amir Mohammad Shojaee @ Electropeak
  Home

*/
//arduinoda tx lerin yanındaki 3.pin
//stm32 de pa9->tx,pa10->rx

#define PWM 3
#define PIN1 8
#define PIN2 9
#define PIN3 10
#define PIN4 11

int pot;
int out;
char durum;
int status1 = 0;
int status2 = 0;
int status3 = 0;
int status4 = 0;

void setup() {

  pinMode(PWM, OUTPUT);
  pinMode(PIN1, INPUT);
  pinMode(PIN2, INPUT);
  pinMode(PIN3, INPUT);
  pinMode(PIN4, INPUT);
}

void loop() {

  status1 = digitalRead(PIN1);
  status2 = digitalRead(PIN2);
  status3 = digitalRead(PIN3);
  status4 = digitalRead(PIN4);

  Serial.println(status1);
  Serial.println(status2);
  Serial.println(status3);
  Serial.println(status4);

  if (status1 == HIGH)
  {
    out = 72;  // 65 yavas,100 orta,225 hizli
    analogWrite(PWM, out);
  }

  else if (status2 == HIGH)
  {
    out = 150;  // 72 yavas,100 orta,225 hizli
    analogWrite(PWM, out);
  }

  else if (status3 == HIGH)
  {
    out = 225;  // 72 yavas,100 orta,225 hizli
    analogWrite(PWM, out);
  }

  else if (status4 == HIGH)
  {
    out = 0;  // 72 yavas,100 orta,225 hizli
    analogWrite(PWM, out);
  }
}
