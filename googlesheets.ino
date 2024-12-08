char devid[] = "v025EACE0E8F3D22";
char serverName[] = "api.pushingbox.com";
boolean DEBUG = true;

#include <Bridge.h>
#include <HttpClient.h>

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  digitalWrite(13, HIGH);

  Serial.begin(9600);
  while (!Serial);
}

void loop() {
  HttpClient client;
  int sensorValue = analogRead(A0);

  String APIRequest;
  APIRequest = String(serverName) + "/pushingbox?devid=" + String(devid) + "&IDtag=100&TimeStamp=50&TempC=" + sensorValue;
  client.get(APIRequest);

  while (client.available()) {
    char c = client.read();
  }
  Serial.flush();
  Serial.print("\n Uploaded temp value: ");
  Serial.print(sensorValue);
  delay(5000);
}
