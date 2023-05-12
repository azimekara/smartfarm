size_t bytesReceived;
char messageBuffer[10];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {  
  if(Serial.available()>0)
  {
     bytesReceived = Serial.readBytesUntil('>',messageBuffer,6);
     Serial.println(bytesReceived);
     if(bytesReceived == 5)
     {
        Serial.println(messageBuffer);
        Serial.println(messageBuffer[0]);
        Serial.println(messageBuffer[1]);
        Serial.println(messageBuffer[2]);
        Serial.println(messageBuffer[3]);
        Serial.println(messageBuffer[4]);
        Serial.println(messageBuffer[5]);
        Serial.println(messageBuffer[6]);
        Serial.println(messageBuffer[7]);
        
     }
  }
}
