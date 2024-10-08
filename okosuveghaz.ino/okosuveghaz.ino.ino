#include <Wire.h>

//#include <Timezone.h>

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

//192.168.139.52 - saját gép
//192.168.139.51 - arduino

#define WIFI_SSID "Titkos" //Cisco3 (suli_static) || Titkos (suli_wifi)
#define WIFI_PASS "19880216" //Eotvos2024 (suli_static) || 19880216 (suli_wifi)
//

//Fix ip beállítás - ha wifi nem kell
/*IPAddress subnet(255, 255, 0, 0);       
IPAddress gateway(192, 168, 1, 95);     
IPAddress local_IP(192, 168, 12, 19);    
IPAddress dns1(8, 8, 8, 8);            
IPAddress dns2(192, 168, 100, 150);    
*/
ESP8266WebServer webserver(80);

HTTPClient httpClient;
WiFiClient client;

#include "DHT.h"
#define DHTPIN D6
#define DHTTYPE DHT22 //22 - 12

DHT dht(DHTPIN,DHTTYPE);

int led = 2; //D4 - 2

//WEMOS D1 MINI PINOUT!!! - D7:13 D2:4

#define nedves 562
#define szaraz 1024

int sensorValue; //aktuális

//int motor = 5; //D1 + pin legyen
int motor2 = 4; //D2

//int enb = 0; //ENB pin D3

//int enA = A0; //D4 - nem valószínű
int fan = 13; //D5 - 14 D8 - 15 Lehet GPIO - wemos d1 r1 pinout + pin legyen, IN3 pin legyen felkapcsolva || fordított logika pumpánál is(?)
//int fan2 = 13; //D7 fan2

unsigned long utIdo = 0;
unsigned long idozito = 60000;

void notfoundPage(){ 
  webserver.send(404, "text/plain", "404: Not found"); 
}

void szellozesbekapcsolas(){
	//Ide kell írni a ledkapcsolás kódját
  delay(500);
  //analogWrite(enA, 255);
  digitalWrite(fan, LOW); //LOW - HIGH
  //digitalWrite(fan2, LOW);
  webserver.send(200, "text/html", "ok"); 

}

void szellozeslekapcsolas(){
	//Ide kell írni a ledkapcsolás kódját
  delay(500);
  //analogWrite(enA, 0);
  digitalWrite(fan, HIGH); //HIGH - LOW
  //digitalWrite(fan2, LOW);
  webserver.send(200, "text/html", "nem ok"); 

}

void ontesbekapcsolas(){
	//Ide kell írni a ledkapcsolás kódját
  delay(500);
  //digitalWrite(motor, LOW);
  digitalWrite(motor2, LOW); //LOW
  webserver.send(200, "text/html", "ok"); 

}

void onteslekapcsolas(){
	//Ide kell írni a ledkapcsolás kódját
  delay(500);
  //digitalWrite(motor, HIGH);
  digitalWrite(motor2, HIGH); //LOW
  webserver.send(200, "text/html", "nem ok"); 

}

void setup() {
  // put your setup code here, to run once:
  dht.begin();

  Serial.begin(115200);
  Serial.println();
  
  /*if (WiFi.config(local_IP, gateway, subnet, dns1, dns2)) {
    Serial.println("Static IP Configured");
  }else{
    Serial.println("Static IP Configuration Failed");
  }*/ //otthon, suli wifi nem kell csak cisco

  //Begin WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) { 
    
    Serial.print(".");
    delay(100); 
  }

  // WiFi Connected
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());

  webserver.on("/szellozesbekapcsolas", szellozesbekapcsolas);
  webserver.on("/szellozeslekapcsolas", szellozeslekapcsolas);

  webserver.on("/ontesbekapcsolas", ontesbekapcsolas);
  webserver.on("/onteslekapcsolas", onteslekapcsolas);

  webserver.onNotFound(notfoundPage);
  webserver.begin();


  //pinMode(motor, OUTPUT);
  pinMode(motor2, OUTPUT);

  //pinMode(enA, OUTPUT);
  pinMode(fan, OUTPUT);
  //pinMode(fan2, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(A0, INPUT);

  //analogWrite(enA, 0);
  digitalWrite(fan, HIGH); //LOW
  //digitalWrite(fan2, LOW);
  //digitalWrite(motor, LOW); 
  digitalWrite(motor2, HIGH); //LOW
  
}

void loop() {
  // put your main code here, to run repeatedly:
  webserver.handleClient(); 

  sensorValue = analogRead(A0);

  int tnSzazalek = map(sensorValue, szaraz, nedves, 0, 100);

  Serial.print("Talajnedvesség: ");
  Serial.print(tnSzazalek);
  Serial.println("%");
  //Serial.println(sensorValue);

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
    Serial.println("C ");
    //Serial.print(tf);
    //Serial.println("F");
  }
  if(tc > 30){
    delay(300);
    digitalWrite(led, HIGH);
  }
  else{
    delay(300);
    digitalWrite(led, LOW);
  }

  if ((millis() - utIdo) > idozito) {
    adatkuldes(h, tc, sensorValue);
    utIdo = millis();
  }

  delay(2000);
  
  //adatkuldes(h, tc, sensorValue); //
}

void adatkuldes(float h, float tc, int tnSzazalek){ //sensorValue
  const char *URL = "http://192.168.139.52/uveghaz/public/api/kuldes"; //ip cím ahova küldi az adatot - gép címe, suliban titkos - 192.168.139.52
  String data = "paratartalom="+String(h)+"&homerseklet="+String(tc)+"&tn="+String(tnSzazalek); //sensorValue
  httpClient.begin(client,URL);
  httpClient.addHeader("Content-Type","application/x-www-form-urlencoded");
  httpClient.POST(data);
  String content = httpClient.getString();
  httpClient.end();
  Serial.print("RESPONSE: ");
  Serial.println(content);

}
