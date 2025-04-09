/* Connection Testing
Date 25/01/2025

Documentation for HTTPClient.h
https://links2004.github.io/Arduino/dd/d8d/class_h_t_t_p_client.html#a5b90eb84c3dcc89a534ac9956418001d
*/

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>  // For JSON parsing

// Wi-Fi credentials
const char* ssid = "PeppaPaige";
const char* password = "Paige04102400";

// Replace this with your server's local IP address
const char* serverUrl = "http://192.168.254.111:8080/products/all";

WiFiClient client;  // Global WiFi client for HTTP
HTTPClient http;    // Global HTTP client

// Function to connect to Wi-Fi
void connect_wifi() {
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi!");
  Serial.print("ESP IP Address: ");
  Serial.println(WiFi.localIP());
}

// Function to fetch data from the server
void fetch_http_data() {
  // Ensure Wi-Fi is connected before making HTTP requests
  if (WiFi.status() == WL_CONNECTED) {
    // Begin the HTTP GET request
    http.begin(client, serverUrl);
    int httpCode = http.GET();  // Perform the GET request

    Serial.print("HTTP Response code: ");
    Serial.println(httpCode);

    if (httpCode == 200) {  // Check if the request was successful
      String payload = http.getString();  // Get the response payload
      Serial.println("Received data:");
      Serial.println(payload);

      /*// Parse JSON
      DynamicJsonDocument doc(1024);
      DeserializationError error = deserializeJson(doc, payload);

      if (!error) {
        JsonArray posts = doc["posts"].as<JsonArray>();
        for (JsonObject post : posts) {
          int id = post["id"];
          const char* title = post["title"];
          const char* author = post["author"];
          const char* date = post["date"];

          // Print out the JSON content
          Serial.print("ID: ");
          Serial.println(id);
          Serial.print("Title: ");
          Serial.println(title);
          Serial.print("Author: ");
          Serial.println(author);
          Serial.print("Date: ");
          Serial.println(date);
          Serial.println();
        }
      } else {
        Serial.print("JSON Parsing Error: ");
        Serial.println(error.c_str()); 
      }*/

    } else {
      Serial.println("Error in HTTP request");
    }

    http.end();  // Free resources
  } else {
    Serial.println("WiFi is not connected!");
  }
}

// Send Data
void post_http_data() {
  if (WiFi.status() == WL_CONNECTED) {
    http.begin(client, serverUrl);  // Begin HTTP request
    http.addHeader("Content-Type", "application/json"); // Set content type

    // Hardcoded JSON payload
    String postData = R"({
      "id": 5,
      "title": "Post 3",
      "author": "Author 3",
      "date": "2025-01-25"
    })";

    Serial.println("Sending POST data:");
    Serial.println(postData);

    int httpCode = http.POST(postData);  // Perform the POST request
    Serial.print("HTTP Response code: ");
    Serial.println(httpCode);

    if (httpCode == 200 || httpCode == 201) {  // Check for successful response
      String response = http.getString();  // Get the response payload
      Serial.println("Server response:");
      Serial.println(response);
    } else {
      Serial.println("Error in POST request or non-200 response");
    }

    http.end();  // Free resources
  } else {
    Serial.println("WiFi is not connected!");
  }
}

//Add Data to existing json
void append_http_data() {
  if (WiFi.status() == WL_CONNECTED) {
    http.begin(client, serverUrl);
    http.addHeader("Content-Type", "application/json");

    String postData = R"({ 
      "id": 1,
      "title": "Q 5",
      "author": "asdfasdf 4",
      "date": "2025-01-25"
    })";    

    Serial.println("Sending POST data:");
    Serial.println(postData);

    int httpCode = http.POST(postData); // Send POST request
    Serial.print("HTTP Response code: ");
    Serial.println(httpCode);

    if (httpCode == 200 || httpCode == 201) { // Check for successful response
      String response = http.getString();
      Serial.println("Server response:");
      Serial.println(response);
    } else {
      Serial.println("Error in POST request or non-200 response");
    }

    http.end(); // Free resources
  } else {
    Serial.println("WiFi is not connected!");
  }
}

void setup() {

  Serial.begin(115200);   // Start the Serial Monitor
  connect_wifi();   // Connect to Wi-Fi
  fetch_http_data(); // Connect to the server and fetch data
  //post_http_data(); // Send Data 
  // append_http_data(); // Append to lower part
}

void loop() {
  delay(10000); 
}
