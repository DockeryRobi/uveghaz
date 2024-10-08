#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

//192.168.139.52 - saját gép

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

void notfoundPage(){ 
  webserver.send(404, "text/plain", "404: Not found"); 
}

void szellozesbekapcsolas(){
	//Ide kell írni a ledkapcsolás kódját
  delay(1000);
  //digitalWrite(fan, HIGH);
  webserver.send(200, "text/html", "ok"); 

}

void szellozeslekapcsolas(){
	//Ide kell írni a ledkapcsolás kódját
  delay(1000);
  //digitalWrite(fan, LOW);
  webserver.send(200, "text/html", "nem ok"); 

}

void ontesbekapcsolas(){
	//Ide kell írni a ledkapcsolás kódját
  delay(2000);
  //digitalWrite(motor, HIGH);
  webserver.send(200, "text/html", "ok"); 

}

void onteslekapcsolas(){
	//Ide kell írni a ledkapcsolás kódját
  delay(2000);
  //digitalWrite(motor, LOW);
  webserver.send(200, "text/html", "nem ok"); 

}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  
  /*if (WiFi.config(local_IP, gateway, subnet, dns1, dns2)) {
    Serial.println("Static IP Configured");
  }else{
    Serial.println("Static IP Configuration Failed");
  }*/

  //Begin WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) { 
    
    Serial.println(".");
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
}

void loop() {
  // put your main code here, to run repeatedly:
  webserver.handleClient();
}
/*
void adatkuldes(float h, float tc, int sensorValue){
  const char *URL = "http://192.168.139.51/uveghaz/public/api/kuldes"; //ip cím ahova küldi az adatot - gép címe
  String data = "paratartalom="+String(h)+"&homerseklet="+String(tc)+"&tn="+String(sensorValue);
  httpClient.begin(client,URL);
  httpClient.addHeader("Content-Type","application/x-www-form-urlencoded");
  httpClient.POST(data);
  String content = httpClient.getString();
  httpClient.end();
  Serial.print("RESPONSE: ");
  Serial.println(content);

}*/
