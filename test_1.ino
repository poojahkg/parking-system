#include <ESP8266WiFi.h>                                                    // esp8266 library
#include <FirebaseArduino.h>                                                // firebase library
                                                         // dht11 temperature and humidity sensor library
#define FIREBASE_HOST "mittest-d8afa-default-rtdb.firebaseio.com"  //Your Firebase Project URL goes here without "http:" , "\" and "/"
#define FIREBASE_AUTH "UBwTbPMWZotaeR3YpswN3kMbuQ1NBnxjRLnfXVAy"   //Your Firebase Database Secret goes here

#define WIFI_SSID "BATMAN"                  //your WiFi SSID(Hotspot Name) for which your NodeMCU connects 
#define WIFI_PASSWORD "12345678"           //Password of your wifi network 


void setup() {
  Serial.begin(9600);
  delay(1000);                
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                     //try to connect with wifi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                            //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                              // connect to firebase
}

void loop() 
{
  const char* inch1 = "xyz";         // In Inch
  Firebase.pushString("/ParkingSystem_Screen_checkpoint3/Slot1", inch1);    
  Serial.println(inch1);

  //Ultrasonic Sensor 2
  const char* inch2 = "abc";
  Firebase.pushString("/ParkingSystem_Screen_checkpoint3/Slot2",inch2);    
  Serial.println(inch2);
}
