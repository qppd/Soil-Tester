#include <WiFi.h>                 // Library to handle WiFi connectivity for ESP8266
#include <Firebase_ESP_Client.h>  // Firebase library for ESP8266

#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

#define FIREBASE_PROJECT_ID "soil-nutrifier"
#define FIREBASE_WEB_API_KEY "AIzaSyDHFtWFW0xOv6jiHiJffhHLLQ9yfONYBJs"      // Firebase Web API Key
#define FIREBASE_URL "https://soil-nutrifier-default-rtdb.firebaseio.com/"  // Firebase database URL

#define WIFI_SSID "QPPD"
#define WIFI_PASSWORD "Programmer136"

FirebaseAuth auth;
FirebaseConfig config;

FirebaseData fbdo;
FirebaseData fb_sensor;

FirebaseData settingStream;

String settingParentPath = "soiltester/device/settings";
String settingPaths[5] = { "/operation", "/nitrogen_limit", "/phosphorus_limit", "/potassium_limit" };

bool signupOk = false;

void settingStreamCallback(MultiPathStream stream) {
  size_t numChild = sizeof(settingPaths) / sizeof(settingPaths[0]);

  for (size_t i = 0; i < numChild; i++) {
    if (stream.get(settingPaths[i])) {
      Serial.println("Setting Updated Path: " + stream.dataPath);
      Serial.println("Setting New Value: " + stream.value);

      if (stream.dataPath == "/operation") {
        OPERATION = stream.value.toInt();

        if (OPERATION == 1) {
          clearLCD();
          Serial.println("Clearing LCD");
          setLCDText("N:", 0, 0);
          setLCDText("P:", 0, 1);
          setLCDText("K:", 8, 0);
        }

      } else if (stream.dataPath == "/nitrogen_limit") {
        NITROGEN_LIMIT = stream.value.toInt();

      } else if (stream.dataPath == "/phosphorus_limit") {
        PHOSPHORUS_LIMIT = stream.value.toInt();

      } else if (stream.dataPath == "/potassium_limit") {
        POTASSIUM_LIMIT = stream.value.toInt();
      }
    }
  }
}

// Callback function to handle cases where the stream experiences a timeout
void settingStreamTimeoutCallback(bool timeout) {
  if (timeout) {
    Serial.println("Setting stream timed out, attempting to resume...");  // Notify of timeout
  }
  if (!settingStream.httpConnected()) {
    Serial.printf("Setting Error code: %d, reason: %s\n", settingStream.httpCode(), settingStream.errorReason().c_str());  // Output HTTP error details if disconnected
  }
}

void initFIREBASE() {
  Serial.println("Connecting to Wifi!");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP:");
  Serial.print(WiFi.localIP());
  Serial.println();

  config.api_key = FIREBASE_WEB_API_KEY;
  config.database_url = FIREBASE_URL;

  if (Firebase.signUp(&config, &auth, "", "")) {
    Serial.println("Signup OK");
    signupOk = true;
  } else {
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  config.token_status_callback = tokenStatusCallback;
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  fb_sensor.setBSSLBufferSize(4096, 1024);
  fbdo.setBSSLBufferSize(4096, 1024);
  fb_sensor.setResponseSize(2048);

  delay(500);

  Serial.println("Starting Setting stream");
  if (!Firebase.RTDB.beginMultiPathStream(&settingStream, settingParentPath)) {
    Serial.printf("Setting stream initialization failed: %s\n", settingStream.errorReason().c_str());  // Output error if stream setup fails
  } else {
    Firebase.RTDB.setMultiPathStreamCallback(&settingStream, settingStreamCallback, settingStreamTimeoutCallback);  // Assign callback functions for stream
    Serial.println("Firebase setting stream initialized successfully!");                                            // Output success message for stream initialization
  }
}

void sendToFirebase(float nitrogen, float phosphorus, float potassium) {
  if (Firebase.ready() && signupOk) {
    Serial.println("Sending to Firebase database");
    Serial.printf("Set float... %s\n", Firebase.RTDB.setFloat(&fb_sensor, F("soiltester/device/readings/nitrogen"), nitrogen) ? "ok" : fb_sensor.errorReason().c_str());
    Serial.printf("Set float... %s\n", Firebase.RTDB.setFloat(&fb_sensor, F("soiltester/device/readings/potassium"), potassium) ? "ok" : fb_sensor.errorReason().c_str());
    Serial.printf("Set float... %s\n", Firebase.RTDB.setFloat(&fb_sensor, F("soiltester/device/readings/phosphorus"), phosphorus) ? "ok" : fb_sensor.errorReason().c_str());
  }
}