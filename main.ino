#include <ESP8266WiFi.h>
#include <WiFiClient.h>

// Replace with your own WiFi network credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// Replace with the URL of the server you want to send the POST request to
const char* host = "API_SERVER_URL";
const int httpPort = 80;

void setup() {
  // Start the serial communication for debugging
  Serial.begin(115200);

  // Connect to the WiFi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  // Create a client object to handle the connection
  WiFiClient client;

  // Connect to the server
  if (!client.connect(host, httpPort)) {
    Serial.println("Connection to server failed");
    return;
  }

  // Define the URL and the payload of the POST request
  String url = "/path";
  String payload = "{\"key1\":\"value1\",\"key2\":\"value2\"}";

  // Debugging output
  Serial.print("Sending POST request to ");
  Serial.println(host);

  // Send the POST request
  client.print("POST " + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Content-Type: application/json\r\n" +
               "Content-Length: " + payload.length() + "\r\n" +
               "Connection: close\r\n\r\n" +
               payload);

  // Debugging output: display the response from the server
  Serial.println("Response:");
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  Serial.println();

  // Close the connection
  client.stop();

  // Wait for 5 seconds before sending another POST request
  delay(5000);
}
