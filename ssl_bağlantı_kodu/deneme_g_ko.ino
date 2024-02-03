#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Arduino_JSON.h>
#include <ArduinoJson.h>
#include <WiFiClientSecure.h>

size_t bytesReceived;
char messageBuffer[10];
char sendBuffer[6];
int mesafedata = 0;
int roofdurum = 0;

int firebuzzerdurum= 0;
int fandurum= 0;
int servodurum= 0;
int touchbuzzerdurum= 0;
int feeddurum= 0;

WiFiClient wfc;

const char* ssid = "HUAWEI Mate 20 lite"; // Wifi kullanıcı adını yazın
const char* pwd = "eac6a6c8217f"; //Wifi parolanızı yazın

String owmWebroofpost = "http://ipmapi.ipmsoft.com.tr/api/RainSensor/SendData" ;
String owmWebroofget = "http://ipmapi.ipmsoft.com.tr/api/RainSensor/GetRoofEndData" ;

String owmWebfirepost = "http://ipmapi.ipmsoft.com.tr/api/FireSensor/SendData" ;
String owmWebfirebuzzerget = "http://ipmapi.ipmsoft.com.tr/api/FireSensor/GetBuzzerEndData" ;
String owmWebfanget = "http://ipmapi.ipmsoft.com.tr/api/FireSensor/GetFanEndData" ;

String owmWebtouchpost = "http://ipmapi.ipmsoft.com.tr/api/MoveSensor/SendData" ;
String owmWebtouchdoorget = "http://ipmapi.ipmsoft.com.tr/api/MoveSensor/GetEndData" ;
String owmWebtouchbuzzerget = "http://ipmapi.ipmsoft.com.tr/api/MoveSensor/GetBuzzerEndData" ;

String owmWebfeedpost = "http://ipmapi.ipmsoft.com.tr/api/FoodSensor/SendData" ;
String owmWebfeedget = "http://ipmapi.ipmsoft.com.tr/api/FoodSensor/GetMachineEndData" ;

const char* host = "ipmapi.ipmsoft.com.tr"; // Host adı
const int httpsPort = 443; // HTTPS port numarası

WiFiClientSecure client;
HTTPClient http;

void post_data(String url, String postData)
{

    http.begin(client, url);
    http.addHeader("Content-Type", "application/json");
    int httpCode = http.POST(postData);
    Serial.printf("%d\n", httpCode);
    if (httpCode > 0) {
        String response = http.getString();
        Serial.println("POST Yanıt: " + response);
    } else {
        Serial.println("POST İsteği başarısız");
    }
    http.end();

}

int get_data(String url, String variable)
{
    http.begin(client, url);
    int httpCode = http.GET();
    if (httpCode > 0) {
        String response = http.getString();
        Serial.println("GET Yanıt: " + response);

        StaticJsonDocument<200> doc;
        deserializeJson(doc, response);
        int buzzerActivity = doc[variable];
        Serial.println(buzzerActivity);
        http.end();
        return buzzerActivity;
    } else {
        Serial.println("GET İsteği başarısız");
        http.end();
        return NULL;
    }
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pwd);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi bağlandı");

  client.setInsecure(); // Sertifika doğrulamasını devre dışı bırak

  if (!client.connect(host, httpsPort)) {
    Serial.println("Bağlantı başarısız");
    return;
  }

}

void loop() {
  if (Serial.available() > 0)
  {
    bytesReceived = Serial.readBytesUntil('>', messageBuffer, 6);
    //    if (bytesReceived == 5)
    //    {
    //      Serial.println(messageBuffer[0]);
    //      Serial.println(messageBuffer[1]);
    //      Serial.println(messageBuffer[2]);
    //      Serial.println(messageBuffer[3]);
    //      Serial.println(messageBuffer[4]);
    //      Serial.println(messageBuffer[5]);
    //    }
  }

  /*************************************************************************************************************/
  /*                                     YAGMUR SENSORU-CATI(STEP MOTORU)                                      */
  /*************************************************************************************************************/
  //yagmur icin
  if (messageBuffer[0] == '1')
  {
    post_data("https://ipmapi.ipmsoft.com.tr/api/MoveSensor/SendData", "{\"isRain\":\"1\"}");
    Serial.println("asd1");
  }
  else if (messageBuffer[0] == '0')
  {   
    post_data("https://ipmapi.ipmsoft.com.tr/api/MoveSensor/SendData", "{\"isRain\":\"0\"}");
    Serial.println("asd1.1");
  }
delay(7000);
  //catı durumu
  roofdurum = get_data("https://ipmapi.ipmsoft.com.tr/api/RainSensor/GetRoofEndData", "activityType");
  Serial.printf("asdas%d\n", roofdurum);
  // Serial.print("Roof Durumu : ");

  /*****************************************************************************************************************/
  /*                                     GAZ SENSORU-BUZZER-FAN                                                    */
  /*****************************************************************************************************************/
  //gaz icin
  if (messageBuffer[1] == '1')
  {
    post_data("https://ipmapi.ipmsoft.com.tr/api/FireSensor/SendData", "{\"isFire\":\"1\"}");
    Serial.println("asd2");
  }
  else if (messageBuffer[1] == '0')
  {
    post_data("https://ipmapi.ipmsoft.com.tr/api/FireSensor/SendData", "{\"isFire\":\"0\"}");
    Serial.println("asd2.1");
  }
delay(7000);
  firebuzzerdurum = get_data("https://ipmapi.ipmsoft.com.tr/api/FireSensor/GetBuzzerEndData", "buzzerActivity");
  fandurum = get_data("https://ipmapi.ipmsoft.com.tr/api/FireSensor/GetFanEndData", "activity");
  Serial.printf("Fire %d\nFan %d\n", firebuzzerdurum, fandurum);
  /*****************************************************************************************************************/
  /*                                     TOUCH SENSORU-SERVO-BUZZER                                                   */
  /*****************************************************************************************************************/
  //touch icin
  
  if (messageBuffer[2] == '1')
  {
    post_data("https://ipmapi.ipmsoft.com.tr/api/MoveSensor/SendData", "{\"animalNumber\":\"1\"}");
    Serial.println("asd3.1");
  }

  else if (messageBuffer[2] == '2')
  {
    post_data("https://ipmapi.ipmsoft.com.tr/api/MoveSensor/SendData", "{\"animalNumber\":\"2\"}");
    Serial.println("asd3.2");
  }

  else if (messageBuffer[2] == '3')
  {
    post_data("https://ipmapi.ipmsoft.com.tr/api/MoveSensor/SendData", "{\"animalNumber\":\"3\"}");
    Serial.println("asd3.3");
  }

  else if (messageBuffer[2] == '4')
  {
    post_data("https://ipmapi.ipmsoft.com.tr/api/MoveSensor/SendData", "{\"animalNumber\":\"4\"}");
    Serial.println("asd3.4");
  }

  else if (messageBuffer[2] == '5')
  {
    post_data("https://ipmapi.ipmsoft.com.tr/api/MoveSensor/SendData", "{\"animalNumber\":\"5\"}");
    Serial.println("asd3.5");
  }

  else if (messageBuffer[2] == '6')
  {
    post_data("https://ipmapi.ipmsoft.com.tr/api/MoveSensor/SendData", "{\"animalNumber\":\"6\"}");
    Serial.println("asd3.6");
  }

  else if (messageBuffer[2] == '7')
  {
    post_data("https://ipmapi.ipmsoft.com.tr/api/MoveSensor/SendData", "{\"animalNumber\":\"7\"}");
    Serial.println("asd3.7");
  }

  else if (messageBuffer[2] == '8')
  {
    post_data("https://ipmapi.ipmsoft.com.tr/api/MoveSensor/SendData", "{\"animalNumber\":\"8\"}");
    Serial.println("asd3.8");
  }

  else if (messageBuffer[2] == '9')
  {
    post_data("https://ipmapi.ipmsoft.com.tr/api/MoveSensor/SendData", "{\"animalNumber\":\"9\"}");
    Serial.println("asd3.9");
  }

  else if (messageBuffer[2] == '0')
  {
    post_data("https://ipmapi.ipmsoft.com.tr/api/MoveSensor/SendData", "{\"animalNumber\":\"0\"}");
    Serial.println("asd3.0");
  }
delay(7000);
  //servo durumu
  servodurum = get_data("https://ipmapi.ipmsoft.com.tr/api/MoveSensor/GetEndData", "doorActivity");
  touchbuzzerdurum = get_data("https://ipmapi.ipmsoft.com.tr/api/MoveSensor/GetEndData", "buzzerActivity");
  Serial.printf("Servo %d\nTouch %d\n", servodurum, touchbuzzerdurum);

  /*****************************************************************************************************************/
  /*                                     MESAFE SENSORU-SERVO                                               */
  /*****************************************************************************************************************/
  //mesafe sensoru
  int a = messageBuffer[3] - '0';
  int b = messageBuffer[4] - '0';
  mesafedata = (a * 10) + b;

  if (mesafedata == 1)
  {    
    post_data("https://ipmapi.ipmsoft.com.tr/api/FoodSensor/SendData", "{\"Distance\":\"1\"}");
    Serial.println("asd4.1");
  }
  else if (mesafedata == 2)
  {
    post_data("https://ipmapi.ipmsoft.com.tr/api/FoodSensor/SendData", "{\"Distance\":\"2\"}");
    Serial.println("asd4.2");
  }
  else if (mesafedata == 3)
  {
    post_data("https://ipmapi.ipmsoft.com.tr/api/FoodSensor/SendData", "{\"Distance\":\"3\"}");
    Serial.println("asd4.3");
  }
  else if (mesafedata == 4)
  {
    post_data("https://ipmapi.ipmsoft.com.tr/api/FoodSensor/SendData", "{\"Distance\":\"4\"}");
    Serial.println("asd4.4");
  }
  else if (mesafedata == 5)
  {
    post_data("https://ipmapi.ipmsoft.com.tr/api/FoodSensor/SendData", "{\"Distance\":\"5\"}");
    Serial.println("asd4.5");
  }
  else if (mesafedata == 6)
  {
    post_data("https://ipmapi.ipmsoft.com.tr/api/FoodSensor/SendData", "{\"Distance\":\"6\"}");
    Serial.println("asd4.6");
  }
  else if (mesafedata == 7)
  {
    post_data("https://ipmapi.ipmsoft.com.tr/api/FoodSensor/SendData", "{\"Distance\":\"7\"}");
    Serial.println("asd4.7");
  }
  else if (mesafedata == 8)
  {
    post_data("https://ipmapi.ipmsoft.com.tr/api/FoodSensor/SendData", "{\"Distance\":\"8\"}");
    Serial.println("asd4.8");
  }
  else if (mesafedata == 9)
  {
    post_data("https://ipmapi.ipmsoft.com.tr/api/FoodSensor/SendData", "{\"Distance\":\"9\"}");
    Serial.println("asd4.9");
  }
  else if (mesafedata == 10)
  {
    post_data("https://ipmapi.ipmsoft.com.tr/api/FoodSensor/SendData", "{\"Distance\":\"10\"}");
    Serial.println("asd4.10");
  }
  else
  {
    post_data("https://ipmapi.ipmsoft.com.tr/api/FoodSensor/SendData", "{\"Distance\":\"10\"}");
    Serial.println("asd4.11");
  }

  feeddurum = get_data("https://ipmapi.ipmsoft.com.tr/api/FoodSensor/GetMachineEndData", "Distance");
  Serial.printf("Feed %d\n", feeddurum);

  /*****************************************************************************************************************/
  /*                                       STM'E VERI GONDERME                                                     */
  /*****************************************************************************************************************/

  senddata();
}

/*********************************************************************************************************/
/*                                 FONKSIYONLAR                                                          */
/*********************************************************************************************************/

//rain ve cati
String getroof(const char* owmJsonroof)
{
  http.begin(wfc, owmJsonroof);
  int httpCode = http.GET();
  //Serial.println(httpCode);
  String payload = http.getString();
  return payload;
}
void roofpostfunction(void)
{
  const char* address = owmWebroofpost.c_str();
  http.begin(wfc, address);
  http.addHeader("Content-Type", "application/json");
}

/***********************************************************************************************************/

//fire, buzzer ve fan
String getfirebuzzer(const char* owmJsonfirebuzzer)
{
  http.begin(wfc, owmJsonfirebuzzer);
  int httpCode = http.GET();
  //Serial.println(httpCode);
  String payload = http.getString();
  return payload;
}
String getfan(const char* owmJsonfan)
{
  http.begin(wfc, owmJsonfan);
  int httpCode = http.GET();
  //Serial.println(httpCode);
  String payload = http.getString();
  return payload;
}
void firepostfunction(void)
{
  const char* addressfire = owmWebfirepost.c_str();
  http.begin(wfc, addressfire);
  http.addHeader("Content-Type", "application/json");
}

/***********************************************************************************************************/

//touch ve kapı servo
String getkapiservo(const char* owmJsonkapiservo)
{
  http.begin(wfc, owmJsonkapiservo);
  int httpCode = http.GET();
  //Serial.println(httpCode);
  String payload = http.getString();
  return payload;
}
void touchpostfunction(void)
{
  const char* addresstouch = owmWebtouchpost.c_str();
  http.begin(wfc, addresstouch);
  http.addHeader("Content-Type", "application/json");
}
//String gettouchbuzzer(const char* owmJsontouchbuzzer)
//{
//  http.begin(wfc, owmJsontouchbuzzer);
//  int httpCode = http.GET();
//  //Serial.println(httpCode);
//  String payload = http.getString();
//  return payload;
//}

/***********************************************************************************************************/
void feedpostfunction(void)
{
  const char* addressfeed = owmWebfeedpost.c_str();
  http.begin(wfc, addressfeed);
  http.addHeader("Content-Type", "application/json");
}
String getfeed(const char* owmJsonfeedstatus)
{
  http.begin(wfc, owmJsonfeedstatus);
  int httpCode = http.GET();
  //Serial.println(httpCode);
  String payload = http.getString();
  return payload;
}
/************************************************************************************************************/
void senddata(void)
{
  Serial.print(roofdurum); //çati durumu
  Serial.print(firebuzzerdurum); //gaz sensoru buzzer
  Serial.print(fandurum); //fan durumu
  Serial.print(servodurum); //agilin kapisi
  Serial.print(touchbuzzerdurum); //agilin buzzeri
  Serial.println(feeddurum); //yem durumu

}
