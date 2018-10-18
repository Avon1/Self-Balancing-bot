
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "index.h"
/*The hotspot*/
const char *ssid = "Self Balancing Bot";
const char *password = "12345678";

ESP8266WebServer server(80);

boolean b = false;
void handleRoot() {
  String s = MAIN_page; //Read HTML contents
  server.send(200, "text/html", s);
}
void handleNotFound() {
  
}
void post() {
  String data = server.arg("updown");
  int pwmValue = data.toInt();
  if (pwmValue > 0) {
    analogWrite(D6, LOW);
    analogWrite(D5, pwmValue);
    analogWrite(D8, LOW);
    analogWrite(D7, pwmValue);
  }
  else if (pwmValue < 0) {
    analogWrite(D5, LOW);
    analogWrite(D6, (pwmValue * -1));
    analogWrite(D7, LOW);
    analogWrite(D8, (pwmValue * -1));
  }
  else {
    analogWrite(D5, LOW);
    analogWrite(D6, LOW);
    analogWrite(D7, LOW);
    analogWrite(D8, LOW);
  }
  Serial.println(pwmValue);
  server.send(200, "text/plain", data);
}
void setup() {
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);
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
