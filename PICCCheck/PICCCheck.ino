/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    
    LF10 - Authentifikation, 2-Faktor, RFID, NFC - SKY12A
    Marvin  und Pierre
    https://github.com/WinniePuuh/LF10
*/
#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9

// RGB LED Pins
int redPin = 3;
int greenPin = 5;
int bluePin = 6;

MFRC522 mfrc522(SS_PIN, RST_PIN);
#define COMMON_ANODE
void setup()
{
  // Serielles Interface initialisieren
  Serial.begin(9600);
  // SPI initialisieren
  SPI.begin();
  
  mfrc522.PCD_Init();
  
  // RGB LED Pins als Output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  
  // Initialisierung, weils toll aussieht!
  setColor(255, 0, 0); // Rot
  delay(500);
  setColor(0, 255, 0); // Grün
  delay(300);
  setColor(0, 0, 255); // Blau
  delay(600);
  setColor(255, 255, 255); // Weiß
  delay(400);
  setColor(255, 255, 0); // Gelb
  delay(600);
  setColor(0, 255, 255); // Türkis
  delay(500);
}
 
void loop()
{
  


      // RGB LED aus
      setColor(0, 0, 0); // Schwarz

    // Für einen schöneren Übergang
    delay(100);
    
    // Nach neuen Karten suchen.
    if ( ! mfrc522.PICC_IsNewCardPresent())
    {
      
      return;
    }

  // Eine der gefunden Karten auswählen
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }

  // Eigene UID bilden. Dazu nehmen wir die 4(7)Byte Hex UID aus Block 0 und quetschen sie in einen schönen String.
  String uID = String(mfrc522.uid.uidByte[0],HEX)+String(mfrc522.uid.uidByte[1],HEX)+String(mfrc522.uid.uidByte[2],HEX)+String(mfrc522.uid.uidByte[3],HEX);
  
  // PICC Typ herausbekommen
  byte piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);


  //Debug Ausgabe
  Serial.println();
  Serial.print("Die Kartennummer lautet: ");
  Serial.print(uID);
  Serial.println();
  Serial.print("Picc Type: ");
  Serial.println(mfrc522.PICC_GetTypeName(piccType));
  Serial.println();

/* 
// Überprüfe auf unterstützten PICC Typ und noch mehr Debug Kram
  if ( piccType != MFRC522::PICC_TYPE_MIFARE_MINI && piccType != MFRC522::PICC_TYPE_MIFARE_1K&& piccType != MFRC522::PICC_TYPE_MIFARE_1K) {
    Serial.println("Diese Tech-Demo benötigt MIFARE Classic Karten.");
    // RGB LED für 3,5sek auf BLAU
   setColor(0,0,255); // blau
    delay(3500);
    return;
  }
 */
// Den UID String vergleichen und eine entsprechende Aktion ausführen
  if( uID=="5b19d5ec" || uID=="4664d835")  {
     Serial.println("Access granted for uID " + uID);
    // RGB LED für 3,5sek auf GRÜN
    setColor(0, 255, 0); // grün
    delay(3500);  
  }
  
  else {
       Serial.println("I can't let you do that Dave (" + uID + ")");
      // RGB LED für 3,5sek auf ROT
      setColor(255, 0, 0); // rot
      delay(3500);
  }
}

// Funktion um die Farbe der RGB LED zu setzen
void setColor(int red, int green, int blue)
{
#ifdef COMMON_ANODE
red = 255 - red;
green = 255 - green;
blue = 255 - blue;
#endif
analogWrite(redPin, red);
analogWrite(greenPin, green);
analogWrite(bluePin, blue);
}
