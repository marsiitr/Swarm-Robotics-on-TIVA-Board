#include <SPI.h>
#include <ESP8266WiFi.h>

byte ledPin = 2;
char ssid[] = "MaRS_private";               // SSID of your home WiFi
char pass[] = "marsiitr1";               // password of your home WiFi
WiFiServer server(80);

IPAddress ip(192, 168, 0, 80);            // IP address of the server
IPAddress gateway(192, 168, 0, 1);        // gateway of your network
IPAddress subnet(255, 255, 255, 0);       // subnet mask of your network

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.config(ip, gateway, subnet);       // forces to use the fix IP
  WiFi.begin(ssid, pass);                 // connects to the WiFi router
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  server.begin();
  pinMode(ledPin, OUTPUT);


}
int state;
void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0) {
    state = Serial.read();
    Serial.println(state);
     WiFiClient client = server.available();
  if (client) {
    if (client.connected()) {
      digitalWrite(ledPin, LOW);  // to show the communication only (inverted logic)
      Serial.println(".");
      client.println(state); // sends the answer to the client
      digitalWrite(ledPin, HIGH);
    }
    client.stop();                // tarminates the connection with the client
  }
  }
  Serial.println("a");
  delay(100);
}


