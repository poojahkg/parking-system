#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "parking-c9501-default-rtdb.firebaseio.com"  //Your Firebase Project URL goes here without "http:" , "\" and "/"
#define FIREBASE_AUTH "6SrSKRIdOntdYSqDv042S5kf2h5z9jNXPsSiU0v8"   //Your Firebase Database Secret goes here

#define WIFI_SSID "One Plus 6"                  //your WiFi SSID(Hotspot Name) for which your NodeMCU connects 
#define WIFI_PASSWORD "12345678"           //Password of your wifi network 

#define trigPin1 16   //D0 (We Used GPIO Pin Number)
#define echoPin1 5    //D1
#define trigPin2 4    //D2
#define echoPin2 0    //D3


 
void setup() 
{
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  Serial.begin(9600);            // Select the same baud rate if you want to see the datas on Serial Monitor
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected:");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
}

void firebasereconnect()
{
  Serial.println("Trying to reconnect");
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
delay(5000);
}

void loop() 
{
  
  //Ultrasonic Sensor 1

  digitalWrite(trigPin1, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  long duration1 = pulseIn(echoPin1, HIGH);
  long inch1 = duration1 / 74 / 2;         // In Inch
  
  if(inch1 <=2)
  {
    Firebase.setString("Slot3","11");  
    Serial.println(inch1);
    Serial.println("Slot3 = 11");
  }
  else
  {
     Firebase.setString("Slot3","00"); 
     Serial.println("Slot3 = 00");
  }
  
  //Ultrasonic Sensor 2

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  long duration2 = pulseIn(echoPin2, HIGH);
  long inch2 = duration2 / 74 / 2;         // In Inch

  if(inch2 <=2)
  {
    Firebase.setString("Slot4","11"); 
    Serial.println("Slot4 = 11");
  }
  else
  {
     Firebase.setString("Slot4","00"); 
     Serial.println("Slot4 = 00");
  }
}
  
