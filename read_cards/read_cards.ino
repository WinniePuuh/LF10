//Marvin Meissner und Pierre Dennert
//SYK12A - MMBbs Hannover (LF10)
//RFID Code Reading
//https://github.com/WinniePuuh/LF10
//Basierend auf "Tutorial 12 - RFID Cards" von http://www.jeremyblum.com

 byte data[5];  //For holding the ID we receive
 int val = 0;
 byte pierre[5] = {0x00,0x00,0x00,0x00,0x00};
 byte marvin[5]  = {0x00,0x00,0x00,0x00,0x00};

 void setup()
 {
   // Serial Port mit 9600bps
   Serial.begin(9600);
   
   // Setting Auto Read Mode - EM4102 Decoded Mode - No password
   // command: FF 01 09 87 01 03 02 00 10 20 30 40 37
   Serial.write(0xFF);  //Header
   Serial.write(0x01);  //Reserved
   Serial.write(0x09);  //Length (Command + Data)
   Serial.write(0x87);  //Command (0x87 sets auto mode behavior
   Serial.write(0x01);  //Data 1: Enable Auto-Read
   Serial.write(0x03);  //Data 2: Mode – Parity decoded – Manchester RF/64
   Serial.write(0x02);  //Data 3: Total number of block to be read (2)
   Serial.write((byte)0x00);  //Data 4: No password expected
   Serial.write(0x10);  //Data 5: Password byte 1
   Serial.write(0x20);  //Data 6: Password byte 2
   Serial.write(0x30);  //Data 7: Password byte 3
   Serial.write(0x40);  //Data 8: Password byte 4
   Serial.write(0x37);  //Checksum
   
   delay(500);
   while(Serial.available()>0)
   {
     Serial.read();
   }
   Serial.println();
   Serial.println("Warte auf Karte...");
 }

 void loop()
 {
 
   val = Serial.read();
   while (val != 0xff)
   {  //Bei Erfolg ist der erste Byte ist immer 0xFF
      val = Serial.read();
      delay(1000);
   }
   
   //we already read the header (0xff)
   Serial.read();              // reserved
   Serial.read();              // length
   Serial.read();              // command (indicates tag data)
   data[0] = Serial.read();    // we read data 1
   data[1] = Serial.read();    // we read data 2
   data[2] = Serial.read();    // we read data 3
   data[3] = Serial.read();    // we read data 4
   data[4] = Serial.read();    // we read data 5
   Serial.read();              // checksum
   
   // Indentify RFID Card
   boolean p_card = true;
   boolean m_card = true;
   Serial.print("Karte erkannt - UID: ");
   for (int i=0; i<5; i++)
   {
     if (data[i] < 16) Serial.print("0");
     Serial.print(data[i], HEX);
      
     //cross-check
     if (data[i] != pierre[i]) p_card = false;
     if (data[i] != marvin[i]) m_card = false;
   }
   Serial.println();
   
   if (p_card) Serial.println("Hallo Pierre!");
   else if (m_card) Serial.println("Hallo Marvin!");
   else Serial.println("der Puuh- Bär, Winnie der Puuh-Bär Bienen passt auf, denn Honig liebt er so sehr Puuh- Bär sucht immerzu mehr, rumpel die bumpel sitzt Er schon im Honigbaum");
   Serial.println();
 }
