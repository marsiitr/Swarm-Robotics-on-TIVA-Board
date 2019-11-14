/*  Connects to the home WiFi network
 *  Asks some network parameters
 *  Sends and receives message from the server in every 2 seconds
 *  Communicates: wifi_server_01.ino
 */ 
#include <SPI.h>
#include <ESP8266WiFi.h>
#define M1_D1 D0
#define M1_D2 D1
#define M2_D1 D3
#define M2_D2 D2

byte ledPin = 2;
char ssid[] = "MaRS_private";           // SSID of your home WiFi
char pass[] = "marsiitr1";            // password of your home WiFi

unsigned long askTimer = 0;

IPAddress server(192,168,0,80);       // the fix IP address of the server
WiFiClient client;

void setup() {
  Serial.begin(115200);               // only for debug
  WiFi.begin(ssid, pass);             // connects to the WiFi router
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
/*  Serial.println("Connected to wifi");
  Serial.print("Status: "); Serial.println(WiFi.status());    // Network parameters
  Serial.print("IP: ");     Serial.println(WiFi.localIP());
  Serial.print("Subnet: "); Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: "); Serial.println(WiFi.gatewayIP());
  Serial.print("SSID: "); Serial.println(WiFi.SSID());
  Serial.print("Signal: "); Serial.println(WiFi.RSSI());*/
  pinMode(ledPin, OUTPUT);
  pinMode(M1_D1, OUTPUT);
  pinMode(M1_D2, OUTPUT);
  pinMode(M2_D1, OUTPUT);
  pinMode(M2_D2, OUTPUT);
}

void loop () {
  client.connect(server, 80);   // Connection to the server
  digitalWrite(ledPin, LOW);    // to show the communication only (inverted logic)
  Serial.println(".");
  String answer = client.readStringUntil('\r');   // receives the answer from the sever
  Serial.println("from server: " + answer);
  if(answer=="49"){
    forward();
  }
  else if(answer=="50"){
    left();
  }
  else if(answer=="51"){
    right();
  }
  else if(answer=="52"){
    halt();
  }
  
  client.flush();
  digitalWrite(ledPin, HIGH);
  delay(100);                  // client will trigger the communication after two seconds
}

void forward(){
  digitalWrite(M1_D1,HIGH);
  digitalWrite(M1_D2,LOW);
  digitalWrite(M2_D1,HIGH);
  digitalWrite(M2_D2,LOW);
  }

void left(){
  digitalWrite(M1_D1,HIGH);
  digitalWrite(M1_D2,LOW);
  digitalWrite(M2_D1,LOW);
  digitalWrite(M2_D2,LOW);
  }

void right(){
  digitalWrite(M1_D1,LOW);
  digitalWrite(M1_D2,LOW);
  digitalWrite(M2_D1,HIGH);
  digitalWrite(M2_D2,LOW);
  }
void halt(){
  digitalWrite(M1_D1,LOW);
  digitalWrite(M1_D2,LOW);
  digitalWrite(M2_D1,LOW);
  digitalWrite(M2_D2,LOW);
  }  

