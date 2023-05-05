#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Arduino_JSON.h>

const char* ssid = "FiberHGW_ZTYUD5_2.4GHz"; // Wifi kullanıcı adını yazın
const char* pwd = "A3RfuUFyEsY9"; //Wifi parolanızı yazın

String owmWeb = "http://ipmapi.ipmsoft.com.tr/api/RainSensor/EndDataGet" ;
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
 String owmJson = getWebPage(owmWeb.c_str());
 JSONVar jsonData = JSON.parse(owmJson);
 if (JSON.typeof(jsonData) == "undefined")
 {
  Serial.println("Json data ayıklanamadı.");
  return;
 }
 Serial.print("Rain Durumu : ");
 double raindurum = (jsonData["isRain"]);
 Serial.println(raindurum);
}

String getWebPage(const char* address)
{
  WiFiClient wfc;
  HTTPClient http;
  http.begin(wfc,address);
  int httpCode = http.GET();
  //Serial.println(httpCode);
  String payload = http.getString();
  return payload;
}
