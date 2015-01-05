LF10 - RFID, NFC, Arduino & Co.
===============================

Software für Arduino und Raspbery Pi, um das Referat über Authentifizierungs-,
Identifikations-, RFID Systeme zu unterstützen.

Bereitgestellt von Marvin und Pierre, SYK12A


Shopping:
---------

+ [Arduino UNO Rev3][1]
+ [RFID-RC522 RF IC Card Sensor Module][2]
+ [Rewritable Waterproof 13.56Mhz Water Droplets NFC Smart Tag][3]
+ [Solderless Breadboard - White (Large Size)][4]
+ [JY-MCU 5V 3V IIC UART SPI Level 4-Way Converter][5]
+ [3x 220kΩ Widerstand][6]
+ [RGB LED (Common Anode)][7] 

[1]: <http://store.arduino.cc/product/A000066>

[2]: <http://eud.dx.com/product/rfid-rc522-rf-ic-card-sensor-module-blue-silver-844203517#.VDvDGxaNAbc>

[3]: <http://eud.dx.com/product/rewritable-waterproof-13-56mhz-water-droplets-nfc-tag-transparent-copper-red-844234180#.VDvDHxaNAbc>

[4]: <http://eud.dx.com/product/solderless-breadboard-white-large-size-844121529>

[5]: <http://eud.dx.com/product/jy-mcu-5v-3v-iic-uart-spi-level-4-way-converter-module-adapter-844178286#.VKnjayuG-k0>

[6]: <http://www.conrad.de/ce/de/product/419842/Metallschicht-Widerstand-220-k-axial-bedrahtet-0414-1-W-1-St>

[7]: <http://www.conrad.de/ce/de/product/1050466/LED-mehrfarbig-Rot-Blau-Gruen-Rund-5-mm-200-mcd-300-mcd-1300-mcd-60-20-mA-195-V-33-V-33-V-Kingbright-L-154A4SU>

Zielsetzung:
---------
Eine kurze Demonstration einer RFID-basierten Zugangskontrolle mit 2
authorisierten Karten, sowie einer nicht authorisierten Karte. Je nach Karte wir
ein eigener Programmzweig ausgeführt, welcher zur visuellen Darstellung
beiträgt.


Lizenz:
---------
Der gesamte Code (sofern nicht anders gekennzeichnet) steht unter
der GNU General Public License (GPL) v3. Eine Online Version ist [hier][5]
abrufbar. Ansonsten liegt eine Kopie der Lizenz in der entsprechenden Datei bei.

[5]: <https://www.gnu.org/copyleft/gpl.html>

Ablauf:
---------
Ein Arduino UNO wird mit einem RFID Kartenleser verbunden. Es werden zwei Karten als authorisiert einprogrammiert. Abhängig davon ob eine Karte authorisiert ist oder nicht wir eine bestimmt Farbe über eine RGB Led ausgegeben

Aufbau:
---------
![Aufbau des Projekts](http://i.imgur.com/TzlYvN0.png)
