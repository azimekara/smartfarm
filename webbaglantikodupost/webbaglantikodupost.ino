//1 gidince yagmur yagiyor 0 gidince yağmıyor

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Arduino_JSON.h>

const char* ssid = "HUAWEI Mate 20 lite"; // Wifi kullanıcı adını yazın
const char* pwd = "eac6a6c8217f"; //Wifi parolanızı yazın

String owmWeb = "http://ipmapi.ipmsoft.com.tr/api/RainSensor/SendData" ;

String counter = "0";
float counter1 = 1;

String tagID="1";

void setup() {
  Serial.begin(115200);
  Serial.print(ssid);
  Serial.println(" bağlanıyor.");
  WiFi.begin(ssid, pwd);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println(" bağlandı.");
}
void loop() {
  WiFiClient wfc;
  HTTPClient http;
  const char* address = owmWeb.c_str();
  http.begin(wfc, address);
  http.addHeader("Content-Type", "application/json");
  int httpResponseCode = http.POST("{\"isRain\":\"1\"}");
  Serial.println(httpResponseCode);
  delay(2000);

}
