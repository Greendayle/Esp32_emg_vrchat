#include <ArduinoOSCWiFi.h>

#include <Wire.h>
#include "WiFi.h"
#include "AsyncUDP.h"


const char * ssid = "YOUR_WIFI_SSID_HERE";
const char * password = "YOUR WIFI PASSWORD HERE";
IPAddress broadcastIp(192, 255, 255, 255);
AsyncUDP udp;
float emg;
float emg_buffer[4];
int buf_index = 0;
int iopin = 36;
OscWiFiClient  client;
void setup()
{
  adcAttachPin(iopin);
  analogSetAttenuation(ADC_11db);
  analogSetWidth(12);
  analogReadResolution(12);
  
  Serial.begin(115200);
  Serial.println("Initializing...");

  WiFi.mode(WIFI_STA);
  Serial.print("Connecting to WiFi ..");

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(10);
  }
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
     Serial.println("WiFi Failed");
     while(1) {
          delay(1000);
      }
  }
  emg_buffer[0] = 0;
  emg_buffer[1] = 0;
  emg_buffer[2] = 0;
  emg_buffer[3] = 0;
}

void loop()
{ 
    emg = analogRead(iopin);
    emg = (float)(emg/4096);
    buf_index += 1;
    buf_index = buf_index % 4;
    emg_buffer[buf_index] = emg;
    Serial.printf("%f\n", (float)(emg/4096));
    
    client.send("YOUR PC WITH VRCHAT LAN IP ADDRESS HERE", 9000, "/avatar/parameters/emg", (emg_buffer[0] + emg_buffer[1] + emg_buffer[2] + emg_buffer[3]) / 4.0f);
    delay(33);
}
