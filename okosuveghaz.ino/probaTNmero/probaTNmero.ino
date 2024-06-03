
//int szaraz = 1024;
//int wet = >500

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
/*
  if(WiFi.config(local_IP,gateway,subnet,dns1,dns2)){
    Serial.println("Statikus IP konfigurálva");
  }else{
    Serial.println("Statikus IP SIKERTELEN!!!");
  }

  WiFi.begin(ssid,password);
  Serial.print("Csatlakozás....");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("Wifi kapcsolodas Sikeres!");
  Serial.println(WiFi.localIP());
*/

  pinMode(A0, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensor = analogRead(A0); //?
  Serial.println(sensor); //?
  delay(500);
}
