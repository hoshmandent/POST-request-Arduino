# ESP8266 HTTP POST Request Example

This code demonstrates how to send a HTTP POST request from an ESP8266 microcontroller and receive the response from a remote server. The code is written in Arduino and uses the **WiFiClient** library to handle the WiFi connection and the HTTP communication.

## Requirements
- ESP8266 microcontroller board
- Arduino IDE
- **WiFiClient** library installed in the Arduino IDE

## Usage

1. Replace the **ssid** and **password** variables with your own WiFi network credentials.
1. Replace the **host** variable with the URL of the server you want to send the POST request to.
1. Upload the code to the ESP8266 board.
1. Open the Serial Monitor in the Arduino IDE to see the debugging output and the response from the server.

## Code Structure

The code starts by defining the credentials for the WiFi network that the ESP8266 should connect to, and the URL of the server that the POST request will be sent to.

In the **setup()** function, the code starts a serial communication for debugging purposes and connects the ESP8266 to the WiFi network.

The **loop()** function is the main part of the code and is executed repeatedly. It first creates a **WiFiClient** object to handle the connection to the server. Then it connects to the server using the **host** and **httpPort** variables, and sends a HTTP POST request with a JSON payload. The response from the server is read and output to the serial monitor for debugging purposes. Finally, the connection is closed and the code waits for 5 seconds before sending another POST request.

This code can be adapted to send different payloads and communicate with different servers by modifying the values of the **url** and **payload** variables, as well as the **host** and **httpPort** variables

## Conclusion

This code serves as a starting point for projects that require the ESP8266 to send HTTP POST requests and receive responses from a remote server. With some modifications, this code can be used in a variety of IoT applications.
