#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Arduino_JSON.h>

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
HTTPClient http;

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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.print(ssid);
  //Serial.println(" bağlanıyor.");
  WiFi.begin(ssid, pwd);
  while (WiFi.status() != WL_CONNECTED)
  {
    //  Serial.print(".");
    delay(500);
  }
  //Serial.println(" bağlandı.");
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
    roofpostfunction();
    int httpResponseCode = http.POST("{\"isRain\":\"1\"}");
  }
  else if (messageBuffer[0] == '0')
  {
    roofpostfunction();
    int httpResponseCode = http.POST("{\"isRain\":\"0\"}");
  }

  //catı durumu
  String owmJsonroof = getroof(owmWebroofget.c_str());
  JSONVar jsonData0 = JSON.parse(owmJsonroof);
  if (JSON.typeof(jsonData0) == "undefined")
  {
    //  Serial.println("Json data ayıklanamadı.");
    return;
  }

  // Serial.print("Roof Durumu : ");
 roofdurum = (jsonData0["activityType"]);

  /*****************************************************************************************************************/
  /*                                     GAZ SENSORU-BUZZER-FAN                                                    */
  /*****************************************************************************************************************/
  //gaz icin
  if (messageBuffer[1] == '1')
  {
    firepostfunction();
    int httpResponseCode1 = http.POST("{\"isFire\":\"1\"}");
  }
  else if (messageBuffer[1] == '0')
  {
    firepostfunction();
    int httpResponseCode1 = http.POST("{\"isFire\":\"0\"}");
  }

  //buzzer durumu
  String owmJsonfirebuzzer = getfirebuzzer(owmWebfirebuzzerget.c_str());
  JSONVar jsonData1 = JSON.parse(owmJsonfirebuzzer);
  if (JSON.typeof(jsonData1) == "undefined")
  {
    //  Serial.println("Json data ayıklanamadı.");
    return;
  }

  //fan durumu
  String owmJsonfan = getfan(owmWebfanget.c_str());
  JSONVar jsonData2 = JSON.parse(owmJsonfan);
  if (JSON.typeof(jsonData2) == "undefined")
  {
    //  Serial.println("Json data ayıklanamadı.");
    return;
  }

  firebuzzerdurum = (jsonData1["buzzerActivity"]);
  fandurum = (jsonData2["activity"]);

  /*****************************************************************************************************************/
  /*                                     TOUCH SENSORU-SERVO-BUZZER                                                   */
  /*****************************************************************************************************************/
  //touch icin
  if (messageBuffer[2] == '1')
  {
    touchpostfunction();
    int httpResponseCode = http.POST("{\"animalNumber\":\"1\"}");
  }

  else if (messageBuffer[2] == '2')
  {
    touchpostfunction();
    int httpResponseCode = http.POST("{\"animalNumber\":\"2\"}");
  }

  else if (messageBuffer[2] == '3')
  {
    touchpostfunction();
    int httpResponseCode = http.POST("{\"animalNumber\":\"3\"}");
  }

  else if (messageBuffer[2] == '4')
  {
    touchpostfunction();
    int httpResponseCode = http.POST("{\"animalNumber\":\"4\"}");
  }

  else if (messageBuffer[2] == '5')
  {
    touchpostfunction();
    int httpResponseCode = http.POST("{\"animalNumber\":\"5\"}");
  }

  else if (messageBuffer[2] == '6')
  {
    touchpostfunction();
    int httpResponseCode = http.POST("{\"animalNumber\":\"6\"}");
  }

  else if (messageBuffer[2] == '7')
  {
    touchpostfunction();
    int httpResponseCode = http.POST("{\"animalNumber\":\"7\"}");
  }

  else if (messageBuffer[2] == '8')
  {
    touchpostfunction();
    int httpResponseCode = http.POST("{\"animalNumber\":\"8\"}");
  }

  else if (messageBuffer[2] == '9')
  {
    touchpostfunction();
    int httpResponseCode = http.POST("{\"animalNumber\":\"9\"}");
  }

  else if (messageBuffer[2] == '0')
  {
    touchpostfunction();
    int httpResponseCode = http.POST("{\"animalNumber\":\"0\"}");
  }

  //servo durumu
  String owmJsonkapiservo = getkapiservo(owmWebtouchdoorget.c_str());
  JSONVar jsonData3 = JSON.parse(owmJsonkapiservo);
  if (JSON.typeof(jsonData3) == "undefined")
  {
    //  Serial.println("Json data ayıklanamadı.");
    return;
  }

  //  //buzzer durumu
  //  String owmJsontouchbuzzer = gettouchbuzzer(owmWebtouchbuzzerget.c_str());
  //  JSONVar jsonData4 = JSON.parse(owmJsontouchbuzzer);
  //  if (JSON.typeof(jsonData4) == "undefined")
  //  {
  //    //  Serial.println("Json data ayıklanamadı.");
  //    return;
  //  }
  //
  servodurum = (jsonData3["doorActivity"]);
  touchbuzzerdurum = (jsonData3["buzzerActivity"]);

  /*****************************************************************************************************************/
  /*                                     MESAFE SENSORU-SERVO                                               */
  /*****************************************************************************************************************/
  //mesafe sensoru
  int a = messageBuffer[3] - '0';
  int b = messageBuffer[4] - '0';
  mesafedata = (a * 10) + b;

  if (mesafedata == 1)
  {
    feedpostfunction();
    int httpResponseCode = http.POST("{\"Distance\":\"1\"}");
  }
  else if (mesafedata == 2)
  {
    feedpostfunction();
    int httpResponseCode = http.POST("{\"Distance\":\"2\"}");
  }
  else if (mesafedata == 3)
  {
    feedpostfunction();
    int httpResponseCode = http.POST("{\"Distance\":\"3\"}");
  }
  else if (mesafedata == 4)
  {
    feedpostfunction();
    int httpResponseCode = http.POST("{\"Distance\":\"4\"}");
  }
  else if (mesafedata == 5)
  {
    feedpostfunction();
    int httpResponseCode = http.POST("{\"Distance\":\"5\"}");
  }
  else if (mesafedata == 6)
  {
    feedpostfunction();
    int httpResponseCode = http.POST("{\"Distance\":\"6\"}");
  }
  else if (mesafedata == 7)
  {
    feedpostfunction();
    int httpResponseCode = http.POST("{\"Distance\":\"7\"}");
  }
  else if (mesafedata == 8)
  {
    feedpostfunction();
    int httpResponseCode = http.POST("{\"Distance\":\"8\"}");
  }
  else if (mesafedata == 9)
  {
    feedpostfunction();
    int httpResponseCode = http.POST("{\"Distance\":\"9\"}");
  }
  else if (mesafedata == 10)
  {
    feedpostfunction();
    int httpResponseCode = http.POST("{\"Distance\":\"10\"}");
  }
  else
  {
    feedpostfunction();
    int httpResponseCode = http.POST("{\"Distance\":\"10\"}");
  }

  String owmJsonfeedstatus = getfeed(owmWebfeedget.c_str());
  JSONVar jsonData5 = JSON.parse(owmJsonfeedstatus);
  if (JSON.typeof(jsonData5) == "undefined")
  {
    //  Serial.println("Json data ayıklanamadı.");
    return;
  }
  feeddurum = (jsonData5["fillingType"]);

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
