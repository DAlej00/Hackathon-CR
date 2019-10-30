#define buzzer 2
#define led1 3
#define but1 4
#define led2 9
#define but2 6
#define led3 7
#define but3 8

#define SS_PIN 53
#define RST_PIN 5

#include <SoftwareSerial.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x26, 16, 2);
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

int mode = 0;
int last_time1;
unsigned int a;
void setup() {
  Serial.begin(115200);
  SPI.begin();          // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  lcd.init();
  lcd.backlight();
  lcd.clear();
  pinMode(buzzer, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(but1, INPUT);
  pinMode(but2, INPUT);
  pinMode(but3, INPUT);
}
boolean lcd_state = false;

void theft() {
  lcd.clear();
  digitalWrite(led1, HIGH);
  for (a = 0; a > 5; a++) {
    lcd.setCursor(0, 0);
    lcd.print("ROBO");
    lcd.setCursor(0, 1);
    lcd.print("THEFT");
    digitalWrite(buzzer, HIGH);
    delay(500);
    lcd.clear();
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(led2, LOW);
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ayuda en camino");
  lcd.setCursor(0, 1);
  lcd.print("Help is coming");
  digitalWrite(buzzer, HIGH);
  delay(5000);
  digitalWrite( led1, LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Espere");
  lcd.setCursor(0, 1);
  lcd.print("Wait");
  delay(2000);
  digitalWrite(led1, LOW);
}

void lost() {
  lcd.clear();
  for (a = 0; a > 5; a++) {
    lcd.print("Perdido");
    delay(500);
    lcd.print("Lost");
    delay(500);
  }
}



void health() {
  lcd.clear();
  for (a = 0; a > 5; a++) {
    lcd.print("Ambulance on way");
    delay(500);
    lcd.print("Salud");
    delay(500);
  }
}

String uuidFinal = "";

void loop() {
//  if (millis() - last_time1 > 1000) {
//    if (lcd_state) {
//      lcd.clear();
//      last_time1 = millis();
//    } else {
//      lcd.print("PRESION UN BOTON");
//      last_time1 = millis();
//      lcd_state = !lcd_state;
//    }
//  }
//
//  digitalRead(but1);
//  if (but1 == HIGH) {
//    theft();
//  }
//
//  digitalRead(but2);
//  if (but2 == HIGH) {
//    lost();
//  }
//
//  digitalRead(but3);
//  if (but3 == HIGH) {
//    health();

    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {

      // Mostramos el ID de la tarjeta leída
      for (byte i = 0; i < mfrc522.uid.size; i++) {
        if (mfrc522.uid.uidByte[i] < 0x10) {
//          uuidFinal += " 0";
          Serial.print(" 0");
        }
        else {
//          uuidFinal += " ";
          Serial.print(" ");
        }

//        uuidFinal += mfrc522.uid.uidByte[i];
        if  ((BIN)mfrc522.uid.uidByte[i] ==11011 1100101 100001 11011){

        Serial.print(1);}
      }

      Serial.println();
//      Serial.print(uuidFinal);
//      uuidFinal = "";

      // Despues de leer una tarjeta esperamos 1 segundo antes de seguir (para evitar multiples lecturas)
      delay(1000);
    }
//  }

}
