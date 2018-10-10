
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include "index.h"
/* Set these to your de82sired credentials. */
const char *ssid = "ESP8266";
const char *password = "12345678";

ESP8266WebServer server(80);

boolean b = false;
void handleRoot() {
	server.send(200, "text/html", "<h1>You are connected</h1>");
}
void handleNotFound() {
  String s = MAIN_page; //Read HTML contents
  server.send(200, "text/html", s);
}
void post() {
  String data = server.arg("msg");
  if(b){
    digitalWrite(D5,LOW);
    b=false;
  }
  else{
    digitalWrite(D5,HIGH);
    b=true;
  }
  server.send(200, "text/plain", "Got this data " + data);
}
void setup() {
  pinMode(D5,OUTPUT);
	delay(1000);
	Serial.begin(115200);
	Serial.println();
	Serial.print("Configuring access point...");
	/* You can remove the password parameter if you want the AP to be open. */
	WiFi.softAP(ssid, password);

	IPAddress myIP = WiFi.softAPIP();
	Serial.print("AP IP address: ");
	Serial.println(myIP);
//	server.on("/", handleRoot);
 server.onNotFound(handleNotFound);
 server.on("/post", post);
	server.begin();
	Serial.println("HTTP server started");
}

void loop() {
	server.handleClient();
}
