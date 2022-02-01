/* This small script will 'ask the IC-7300' the active frequency
*  (c) PA2EON - Eric
*/

#include <SoftwareSerial.h> // for comms to IC7300
#define BAUD_RATE 19200     // CI-V speed
#define TRX_address (0x94)  // HEX $94 = Icom IC-7300

// serial connection to the Arduino UNO
// RX = Icom radio to Arduino  : to pin 1 via resistor 4k7
// TX = Arduino to Icom radio  : to pin 2 via diode 1N4148, with pull up 10k to Vcc (5V) on tip of 3.5 mm connector

SoftwareSerial mySerial = SoftwareSerial(1, 2); // (RX, TX)

//Now create the data and send it to the RIG
int readCounter; // counts the number of bytes received from the radio

void setup() { 
  
  pinMode(1, INPUT);   // CI-V serial communication from IC7300
  pinMode(2, OUTPUT); // CI-V serial communication to IC7300
  
  Serial.begin(BAUD_RATE);   // Dump info to serial monitor
  mySerial.begin(BAUD_RATE);
  mySerial.listen();  // only one port can be made to listen with software serial

while (mySerial.available()) mySerial.read(); // clean buffer
Serial.print("waiting for CI-V");

}

void loop() {

  mySerial.flush();
  mySerial.write(0xFE); 
  mySerial.write(0xFE); 
  mySerial.write(TRX_address); 
  mySerial.write(0xE0);
  mySerial.write(0x03); 
  mySerial.write(0xFD); // end sequence
  delay(20);
 
// code to read //
  
}



