// Define Serial2 RX and TX pins for NPK sensor
#define NPK_RX_PIN 17 // 17 is esp32 TX pin
#define NPK_TX_PIN 16 // 16 is esp32 RX pin

// Serial2bus RTU requests for reading NPK values
const byte READ_NITROGEN[]    = { 0x01, 0x03, 0x00, 0x1E, 0x00, 0x01, 0xE4, 0x0C };
const byte READ_PHOSPHORUS[]  = { 0x01, 0x03, 0x00, 0x1F, 0x00, 0x01, 0xB5, 0xCC };
const byte READ_POTASSIUM[]   = { 0x01, 0x03, 0x00, 0x20, 0x00, 0x01, 0x85, 0xC0 };

byte responseBuffer[8];  // Storage for response

byte readNitrogen() {
  Serial2.flush();                             // Clear outgoing buffer
  while (Serial2.available()) Serial2.read();  // Clear incoming buffer

  Serial2.write(READ_NITROGEN, sizeof(READ_NITROGEN));
  delay(100);

  for (byte i = 0; i < 7; i++) {
    if (Serial2.available()) {
      responseBuffer[i] = Serial2.read();
      Serial.print(responseBuffer[i], HEX);
      Serial.print(" ");
    }
  }
  Serial.println();
  return responseBuffer[4];  // Value position
}

byte readPhosphorus() {
  Serial2.flush();
  while (Serial2.available()) Serial2.read();

  Serial2.write(READ_PHOSPHORUS, sizeof(READ_PHOSPHORUS));
  delay(100);

  for (byte i = 0; i < 7; i++) {
    if (Serial2.available()) {
      responseBuffer[i] = Serial2.read();
      Serial.print(responseBuffer[i], HEX);
      Serial.print(" ");
    }
  }
  Serial.println();
  return responseBuffer[4];
}

byte readPotassium() {
  Serial2.flush();
  while (Serial2.available()) Serial2.read();

  Serial2.write(READ_POTASSIUM, sizeof(READ_POTASSIUM));
  delay(100);

  for (byte i = 0; i < 7; i++) {
    if (Serial2.available()) {
      responseBuffer[i] = Serial2.read();
      Serial.print(responseBuffer[i], HEX);
      Serial.print(" ");
    }
  }
  Serial.println();
  return responseBuffer[4];
}

void initNPK() {
  Serial2.begin(4800, SERIAL_8N1, NPK_RX_PIN, NPK_TX_PIN);
  delay(500);
}

void getNPKReading() {
  byte nitrogenVal = readNitrogen();
  delay(250);
  byte phosphorusVal = readPhosphorus();
  delay(250);
  byte potassiumVal = readPotassium();
  delay(250);

  Serial.print("Nitrogen: ");
  Serial.print(nitrogenVal);
  Serial.println(" mg/kg");

  Serial.print("Phosphorus: ");
  Serial.print(phosphorusVal);
  Serial.println(" mg/kg");

  Serial.print("Potassium: ");
  Serial.print(potassiumVal);
  Serial.println(" mg/kg");

  CURRENT_NITROGEN   = nitrogenVal;
  CURRENT_PHOSPHORUS = phosphorusVal;
  CURRENT_POTASSIUM  = potassiumVal;
}
