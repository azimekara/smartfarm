#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Arduino_JSON.h>

const char* ssid = "HUAWEI Mate 20 lite"; // Wifi kullanıcı adını yazın
const char* pwd = "eac6a6c8217f"; //Wifi parolanızı yazın

String owmWebroof = "http://ipmapi.ipmsoft.com.tr/api/MoveSensor/GetBuzzerEndData" ;
char sendBuffer[10];

void setup() {
  Serial.begin(115200);
  Serial.print(ssid);
//  Serial.println(" bağlanıyor.");
  WiFi.begin(ssid, pwd);
  while (WiFi.status() != WL_CONNECTED)
  {
//    Serial.print(".");
    delay(500);
  }
//  Serial.println(" bağlandı.");
}

void loop() {
 String owmJson = getWebPage(owmWebroof.c_str());
 JSONVar jsonData = JSON.parse(owmJson);
 if (JSON.typeof(jsonData) == "undefined")
 {
//  Serial.println("Json data ayıklanamadı.");
  return;
 }
// Serial.print("Roof Durumu : ");
 int touchbuzzerdurum = (jsonData["buzzerActivity"]);

 sendBuffer[0]='>';
 sendBuffer[1]=1;
 sendBuffer[2]=2;
 sendBuffer[3]=3;
 sendBuffer[4]=touchbuzzerdurum;
 sendBuffer[5]='5';

 Serial.println(sendBuffer);
// Serial.println(sendBuffer[1]);
}

String getWebPage(const char* owmJson)
{
  WiFiClient wfc;
  HTTPClient http;
  http.begin(wfc,owmJson);
  int httpCode = http.GET();
  //Serial.println(httpCode);
  String payload = http.getString();
  return payload;
}
