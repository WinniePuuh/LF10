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
+ 3x 220kΩ Widerstand
+ RGB LED (com. anode, rbg)

[1]: <http://store.arduino.cc/product/A000066>

[2]: <http://eud.dx.com/product/rfid-rc522-rf-ic-card-sensor-module-blue-silver-844203517#.VDvDGxaNAbc>

[3]: <http://eud.dx.com/product/rewritable-waterproof-13-56mhz-water-droplets-nfc-tag-transparent-copper-red-844234180#.VDvDHxaNAbc>

Zielsetzung:
---------
Eine kurze Demonstration einer RFID-basierten Zugangskontrolle mit 2
authorisierten Karten, sowie einer nicht authorisierten Karte. Je nach Karte wir
ein eigener Programmzweig ausgeführt, welcher zur visuellen Darstellung
beiträgt.


Lizenz:
---------
Der gesamte Code (sofern nicht anders gekennzeichnet) steht unter
der GNU General Public License (GPL) v3. Eine Online Version ist [hier][4]
abrufbar. Ansonsten liegt eine Kopie der Lizenz in der entsprechenden Datei bei.

[4]: <https://www.gnu.org/copyleft/gpl.html>

Ablauf:
---------
Ein Arduino UNO wird mit einem RFID Kartenleser verbunden. Es werden zwei Karten als authorisiert einprogrammiert. Abhängig davon ob eine Karte authorisiert ist oder nicht wir eine bestimmt Farbe über eine RGB Led ausgegeben

Aufbau:
---------
![Aufbau des Projekts](http://i.imgur.com/hCirT89.png)
