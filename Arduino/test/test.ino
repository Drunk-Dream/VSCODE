#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN)
LiquidCrystal_I2C lcd(0x27, 16, 2)

byte nuidPICC[4];
double balanceOf = 100.00;

void setup() {
    Serial.begin(9600);
    SPI.begin();
    rfid.PCD_Init();
    Serial.println("RC522初始化成功...");
    lcd.init();
    lcd.backlight();
}

void loop() {
    lcd.setCursor(0, 0);
    lcd.print("deductions:");
    lcd.setCursor(2, 1);
    lcd.print("5 yuan");
    if ( ! rfid.PICC_IsNewCardPresent())
        return;

    if (! rfid.PICC_ReadCardSerial())
        return;

    MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);

    if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K){
    Serial.println("不支持读取此卡类型");
    return;
    }

}
