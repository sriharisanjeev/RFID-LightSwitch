#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
#define RELAY_PIN 7   // Relay (or LED) pin

MFRC522 mfrc522(SS_PIN, RST_PIN);

bool relayState = false; // to remember relay state

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // start OFF

  Serial.println("Scan RFID card...");
}

void loop() {
  // Look for a card
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  // Read UID
  String content = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  Serial.print("UID: "); Serial.println(content);

  // Authorized UID (replace with your card UID)
  if (content.substring(1) == "25 4D 42 02") {
    relayState = !relayState; // toggle state
    digitalWrite(RELAY_PIN, relayState ? HIGH : LOW);

    if (relayState) {
      Serial.println("Authorized card → Relay ON");
    } else {
      Serial.println("Authorized card → Relay OFF");
    }
  } else {
    Serial.println("Unauthorized card → Ignored");
  }

  // Halt until card is removed (prevents multiple reads in one tap)
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
}
