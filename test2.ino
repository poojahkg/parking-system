#include <ArduinoJson.h>
#include<FirebaseArduino.h>
#include<ESP8266WiFi.h>

#define FIREBASE_HOST "parking-c9501-default-rtdb.firebaseio.com"  //Your Firebase Project URL goes here without "http:" , "\" and "/"
#define FIREBASE_AUTH "6SrSKRIdOntdYSqDv042S5kf2h5z9jNXPsSiU0v8"   //Your Firebase Database Secret goes here

#define WIFI_SSID "One Plus 6"                  //your WiFi SSID(Hotspot Name) for which your NodeMCU connects 
#define WIFI_PWD "Poojah55"           //Password of your wifi network 


void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PWD);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print('.');
    delay(500);
  }
  Serial.print("Connected to ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setFloat("Float", 2.5);
}

void loop()
{
  // put your main code here, to run repeatedly:
    float val = Firebase.getFloat("Float");
    if (Firebase.failed()) {
Serial.print("setting /message failed:");
//Serial.println(Firebase.error());
return;
}

    Serial.println(val);
    Firebase.setFloat("Float", val + 1.0);
    if (Firebase.failed()) {
Serial.print("setting /message failed:");
//Serial.println(Firebase.error());
return;
}

    delay(2000);
}
