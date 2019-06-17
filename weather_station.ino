#include <Seeed_BME280.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>
#include <Wire.h>

#define LED D4
#define SEALEVELPRESSURE_HPA (1013.25)

char ssid[] = "SSID";
char password[] = "PASSWORD";
String host = "/api/sendweather.php?t=";

int retryCount = 0;
float temperature, humidity, pressure, altitude;
BME280 bme;

HTTPClient http;

void setup() {
  
  Serial.begin(115200);
  delay(10);
  if(!bme.init()){
    Serial.println("Device error!");
  }
  // Connect WiFi
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.hostname("Name");
  WiFi.begin(ssid, password);

  Wire.begin();
  Serial.begin(115200);
  pinMode(LED, OUTPUT);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    retryCount++;

    if (retryCount == 10){
      Serial.print("Connection failed, going to sleep.");
      ESP.deepSleep(1000000 * 60 * 10);
    }
    // Blink LED when connecting to wifi
    digitalWrite(LED, LOW);
    delay(250);
    digitalWrite(LED, HIGH);
    delay(250);
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Print the IP address
  Serial.print("IP address: ");
  Serial.print(WiFi.localIP());
  Serial.println("");
  
}
 
void loop() {
   
  while (1) {
    digitalWrite(LED, LOW);
    digitalWrite(LED, HIGH);
    
    Serial.println();
    measure();
    
    if(WiFi.status()== WL_CONNECTED){ 
      HTTPClient http; 
      http.begin(host+temperature+"&h="+humidity+"&p="+pressure); 
      int httpCode = http.GET(); //Send the request
      if (httpCode > 0) { 
        String payload = http.getString(); 
        Serial.println(payload); 
      }
      http.end(); //Close connection
    } else {
        Serial.println("Error in WiFi connection");   
    }

    Serial.println("Going into deep sleep");
    ESP.deepSleep(1000000 * 60 * 10); //microseconds , 10 minutes
  }
}

void measure(){
  temperature = bme.getTemperature();
  humidity = bme.getHumidity();
  pressure = bme.getPressure() / 100.0F;

  Serial.println(temperature);
  Serial.println(humidity);
  Serial.println(pressure);
}
