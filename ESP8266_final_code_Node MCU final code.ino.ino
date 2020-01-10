//The esp8266 cost 14000frw and the reader 10000frw the whole project will now cost 250000
#include <MFRC522.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <SPI.h >


ESP8266WiFiMulti WiFiMulti;
#define RST_PIN 15 // RST-PIN for RC522 - RFID - SPI - Modul GPIO15 
#define SS_PIN  2  // SDA-PIN for RC522 - RFID - SPI - Modul GPIO2
#define BUZZER 5
#define RED_LIGHT 16
#define YELLOW_LIGHT 15
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance


int frequency = 2000;
char *UID;
String data, tag;

void setup() {
  const uint16_t port = 80;
  const char * host = "192.168.0.104"; // ip or dns
  pinMode(BUZZER, OUTPUT);
  pinMode(RED_LIGHT, OUTPUT);
  pinMode(YELLOW_LIGHT, OUTPUT);
  digitalWrite(BUZZER, LOW);
  digitalWrite(YELLOW_LIGHT, LOW);
  digitalWrite(RED_LIGHT, HIGH);
  Serial.begin(115200);
  SPI.begin();           // Init SPI bus
  mfrc522.PCD_Init();    // Init MFRC522
  delay(30);


  // We start by connecting to a WiFi network
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("Olivier", "Mugeni123");

  Serial.println();
  Serial.println();
  Serial.print("Wait for WiFi... ");

  while (WiFiMulti.run() != WL_CONNECTED) {
    Serial.print(".");
    delay(10);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");

  Serial.println(WiFi.localIP());
  Serial.print("connected to ");
  Serial.println(host);
}

void loop() {

  const uint16_t port = 80;
  const char * host = "192.168.0.104"; // ip or dns

  // Use WiFiClient class to create TCP connections
  HTTPClient http;

  //if (!client.connect) {
  //Serial.println("Connection to host failure");
  //Serial.println("Refresh, 2 sec...");
  //delay(2000);
  //return;
  //}

  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    delay(20);
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    delay(20);
    return;
  }

  for (byte i = 0; i <  mfrc522.uid.size; i++) {
    tag += mfrc522.uid.uidByte[i];
  }
  data += "?status=" + tag ;
  String Link = "http://192.168.0.104/rfid/postdemo.php" + data;
  http.begin(Link);
  int httpCode = http.GET();
  Serial.println(Link);
  Serial.println(httpCode);
  http.end();
  tag = "";
  data = "";
  if(httpCode==200){
  tone(BUZZER, frequency);
  digitalWrite(RED_LIGHT, LOW);
  digitalWrite(YELLOW_LIGHT, HIGH);
  delay(400);
  noTone(BUZZER);
  digitalWrite(RED_LIGHT, 1);
  digitalWrite(YELLOW_LIGHT, 0);
  delay(500);
  }

  else{
   
  tone(BUZZER, frequency);
  digitalWrite(RED_LIGHT, LOW);
  digitalWrite(YELLOW_LIGHT, HIGH);
  delay(100);
  noTone(BUZZER);
  digitalWrite(RED_LIGHT, 1);
  digitalWrite(YELLOW_LIGHT, 0);
  delay(150);
  tone(BUZZER, frequency);
  digitalWrite(RED_LIGHT, LOW);
  digitalWrite(YELLOW_LIGHT, HIGH);
  delay(100);
  noTone(BUZZER);
  digitalWrite(RED_LIGHT, 1);
  digitalWrite(YELLOW_LIGHT, 0);
  delay(150); 
   
  tone(BUZZER, frequency);
  digitalWrite(RED_LIGHT, LOW);
  digitalWrite(YELLOW_LIGHT, HIGH);
  delay(100);
  noTone(BUZZER);
  digitalWrite(RED_LIGHT, 1);
  digitalWrite(YELLOW_LIGHT, 0);
  delay(150);
  tone(BUZZER, frequency);
  digitalWrite(RED_LIGHT, LOW);
  digitalWrite(YELLOW_LIGHT, HIGH);
  delay(100);
  noTone(BUZZER);
  digitalWrite(RED_LIGHT, 1);
  digitalWrite(YELLOW_LIGHT, 0);
  delay(150); 
  }
}


