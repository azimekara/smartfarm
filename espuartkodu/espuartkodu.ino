size_t bytesReceived;
char messageBuffer[10];
char sendBuffer[10];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {  
  if(Serial.available()>0)
  {
     bytesReceived = Serial.readBytesUntil('>',messageBuffer,6);
//     Serial.println(bytesReceived); // kaç veri geldiğini görmek için
     if(bytesReceived == 5)
     {
//        Serial.println(messageBuffer[0]);
//        Serial.println(messageBuffer[1]);
//        Serial.println(messageBuffer[2]);
//        Serial.println(messageBuffer[3]);
//        Serial.println(messageBuffer[4]);
//        Serial.println(messageBuffer[5]);      
     }

     sendBuffer[0]='0';
     sendBuffer[1]='1';
     sendBuffer[2]='2';     
     sendBuffer[3]='3';
     sendBuffer[4]='4';
     sendBuffer[5]='5';  
                 
     Serial.write(sendBuffer[0]);
     Serial.write(sendBuffer[1]);
     Serial.write(sendBuffer[2]);
     Serial.write(sendBuffer[3]);
     Serial.write(sendBuffer[4]);
     Serial.write(sendBuffer[5]);
  }
}
