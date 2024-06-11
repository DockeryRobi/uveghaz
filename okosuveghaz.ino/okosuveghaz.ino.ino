#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

//nem kell?
#define WIFI_SSID "Cisco3"
#define WIFI_PASS "Eotvos2024"
//

//Fix ip beállítás
IPAddress subnet(255, 255, 0, 0);       
IPAddress gateway(192, 168, 1, 95);     
IPAddress local_IP(192, 168, 12, 19);    
IPAddress dns1(8, 8, 8, 8);            
IPAddress dns2(192, 168, 100, 150);    

ESP8266WebServer webserver(80);

HTTPClient httpClient;
WiFiClient client;

#include "DHT.h"
#define DHTPIN D6
#define DHTTYPE DHT12 //22

DHT dht(DHTPIN,DHTTYPE);

int led = D5;

//#define nedves ? < 520
//#define szaraz ? 1024

//int max; //max 1024
int sensorValue; //aktuális

int motor = D7; //9
int fan = D8; //10

void notfoundPage(){ 
  webserver.send(404, "text/plain", "404: Not found"); 
}

void szellozesbekapcsolas(){
	//Ide kell írni a ledkapcsolás kódját
  delay(2000);
  digitalWrite(fan, HIGH);
  webserver.send(200, "text/html", "ok"); 

}

void szellozeslekapcsolas(){
	//Ide kell írni a ledkapcsolás kódját
  delay(2000);
  digitalWrite(fan, LOW);
  webserver.send(200, "text/html", "nem ok"); 

}

void ontesbekapcsolas(){
	//Ide kell írni a ledkapcsolás kódját
  delay(2000);
  digitalWrite(motor, HIGH);
  webserver.send(200, "text/html", "ok"); 

}

void onteslekapcsolas(){
	//Ide kell írni a ledkapcsolás kódját
  delay(2000);
  digitalWrite(motor, LOW);
  webserver.send(200, "text/html", "nem ok"); 

}

void setup() {
  // put your setup code here, to run once:
  dht.begin();

  Serial.begin(115200);
  Serial.println();
  
  if (WiFi.config(local_IP, gateway, subnet, dns1, dns2)) {
    Serial.println("Static IP Configured");
  }else{
    Serial.println("Static IP Configuration Failed");
  }

  //Begin WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) { 
    
    Serial.print(".");
    delay(100); 
  }

  // WiFi Connected
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());

  // Start Web Server
  //webserver.on("/hello", rootPage);

  webserver.on("/szellozesbekapcsolas", szellozesbekapcsolas);
  webserver.on("/szellozeslekapcsolas", szellozeslekapcsolas);

  webserver.on("/ontesbekapcsolas", ontesbekapcsolas);
  webserver.on("/onteslekapcsolas", onteslekapcsolas);

  webserver.onNotFound(notfoundPage);
  webserver.begin();


  pinMode(motor, OUTPUT);
  pinMode(fan, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(A0, INPUT);
  /*max = analogRead(A0);
  Serial.println(max);*/
}

void loop() {
  // put your main code here, to run repeatedly:
  webserver.handleClient(); 
  delay(5000);
  sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  float h = dht.readHumidity();
  float tc = dht.readTemperature();
  float tf = dht.readTemperature(true); //nem szükséges
  if (isnan(h) || isnan(tc) || isnan(tf)){
    Serial.println("Nem tudok mérni,");
  } else {
    Serial.print("Páratartalom: ");
    Serial.print(h);
    Serial.print("%");
    Serial.print(" || ");
    Serial.print("Hőmérséklet: ");
    Serial.print(tc);
    Serial.print("C / ");
    /*Serial.print(tf);
    Serial.println("F");*/
  }
  if(tc > 30){
    delay(500);
    digitalWrite(led, HIGH);
  }
  else{
    delay(500);
    digitalWrite(led, LOW);
  }

    //adatkuldes(h, tc, sensorValue); //Kell?
}

void adatkuldes(float h, float tc, int sensorValue){
  const char *URL = "http://192.168.21.20/uveghaz/public/api/kuldes"; //ip cím ahova küldi az adatot
  String data = "paratartalom="+String(h)+"&homerseklet="+String(tc)+"&tn="+String(sensorValue);
  httpClient.begin(client,URL);
  httpClient.addHeader("Content-Type","application/x-www-form-urlencoded");
  httpClient.POST(data);
  String content = httpClient.getString();
  httpClient.end();
  Serial.print("RESPONSE: ");
  Serial.println(content);

}
/*
void probafan(){
  // Check if there is any incoming data
  if(Serial.available() > 0) {
    // Read the incoming data
    char command = Serial.read();
    
    // Check the received command
    if(command == '1') {
      // Turn on the fan
      digitalWrite(fanPin, HIGH);
      Serial.println("Fan turned on");
    } else if(command == '0') {
      // Turn off the fan
      digitalWrite(fanPin, LOW);
      Serial.println("Fan turned off");
    }
  }
}*/
