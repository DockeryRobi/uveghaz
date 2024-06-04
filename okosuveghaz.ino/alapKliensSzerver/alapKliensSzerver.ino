#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

// Set WiFi credentials
#define WIFI_SSID "Cisco3"
#define WIFI_PASS "Eotvos2024"

//Fix ip beállítás
IPAddress subnet(255, 255, 0, 0);       // Subnet Mask
IPAddress gateway(192, 168, 1, 95);     // Default Gateway
IPAddress local_IP(192, 168, 12, 1);    // 192.168.12.x ahol x={1..28}
IPAddress dns1(8, 8, 8, 8);            //Google dns
IPAddress dns2(192, 168, 100, 150);    //Alternate dns



// Create a new web server
ESP8266WebServer webserver(80);

//Kliens beállítás
WiFiClient client;
HTTPClient httpClient;

// Főoldal
void rootPage() { 
  webserver.send(200, "text/html", "<h1>Helló 2 world</h1>"); 
}

// Nem létező oldal
void notfoundPage(){ 
  webserver.send(404, "text/plain", "404: Not found"); 
}

void ledKapcsolas(){
	//Ide kell írni a ledkapcsolás kódját
}


void setup()
{
  // Setup serial port
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
  Serial.print("Connected! IP adress: ");
  Serial.println(WiFi.localIP());

  // Start Web Server
  webserver.on("/hello", rootPage);

  webserver.onNotFound(notfoundPage);
  webserver.begin();
}

// Listen for HTTP requests
void loop(void){ 
  webserver.handleClient(); 
  delay(1000);

}

void adatKuldesPelda(float data1, int data2){
  String data = "data1="+String(data1)+"&data2="+String(data2);
  const char *URL = "http://192.168.12.19/";
  httpClient.begin(client,URL);
  httpClient.addHeader("Content-Type","application/x-www-form-urlencoded");
  httpClient.POST(data);
  String content = httpClient.getString();
  httpClient.end();
  Serial.println("Response:");
  Serial.println(content);
}

http://192.168.12.19/futeslekapcsolas
