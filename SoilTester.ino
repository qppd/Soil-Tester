int OPERATION = 0;
float NITROGEN_LIMIT = 0;
float PHOSPHORUS_LIMIT = 0;
float POTASSIUM_LIMIT = 0;

float CURRENT_NITROGEN = 0;
float CURRENT_PHOSPHORUS = 0;
float CURRENT_POTASSIUM = 0;

#include "NPK_CONFIG.h"
#include "LIB_CONFIG.h"
#include "LCD_CONFIG.h"
#include "FIREBASE_CONFIG.h"

void setup() {
  Serial.begin(9600);

  initFIREBASE();
  delay(1500);
  initNPK();
  Serial.println("Setup done!");

  initLCD();
  Serial.println("LCD initialized!");
  setLCDText("IoT Soil Tester", 0, 0);
  delay(1500);
  setLCDText("LSPU - BSIT", 0, 1);
  delay(3000);
  clearLCD();
  Serial.println("Clearing LCD");
  setLCDText("N:", 0, 0);
  setLCDText("P:", 0, 1);
  setLCDText("K:", 8, 0);
}

int interval = 1000;
unsigned long time_for_interval;


void loop() {

  if (millis() - time_for_interval > interval) {
    time_for_interval = millis();

    if (OPERATION == 1) {
      getNPKReading();

      setLCDText(CURRENT_NITROGEN, 2, 0);
      setLCDText(CURRENT_PHOSPHORUS, 2, 1);
      setLCDText(CURRENT_POTASSIUM, 10, 0);

      sendToFirebase(CURRENT_NITROGEN, CURRENT_PHOSPHORUS, CURRENT_POTASSIUM);
    } else if (OPERATION <= 0) {
      clearLCD();
      setLCDText("STAND BY", 0, 0);
    }
  }
}