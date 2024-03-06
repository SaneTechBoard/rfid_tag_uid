#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 4
#define RST_PIN 5
MFRC522 mfrc522(SS_PIN, RST_PIN);  
void setup() {
    Serial.begin(9600); 
    SPI.begin();        
    mfrc522.PCD_Init(); 
    Serial.println("Scan tag:");
}
void loop() 
{
    if ( ! mfrc522.PICC_IsNewCardPresent()) {
        return;
    }
    if ( ! mfrc522.PICC_ReadCardSerial()) {
        return;
    }
    mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}