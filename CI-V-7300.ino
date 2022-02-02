/* This small script will 'ask the IC-7300' the active frequency
*  PA2EON - Eric
*/

#include <SoftwareSerial.h> // for comms to IC7300
#include <avr/wdt.h>        // Watchdog timer
#define BAUD_RATE 19200     // CI-V speed
#define TRX_address (0x94)  // HEX $94 = Icom IC-7300

// serial connection to the Arduino UNO
// RX = Icom radio to Arduino  : to pin 4 via resistor 4k7
// TX = Arduino to Icom radio  : to pin 7 via diode 1N4148, with pull up 10k to Vcc (5V) on tip of 3.5 mm connector

SoftwareSerial mySerial = SoftwareSerial(4, 7); // (RX, TX)
//SoftwareSerial mySerial(4, 7);  // (RX, TX)

//Now create the data and send it to the RIG

void setup() { 

pinMode(4, INPUT);   // CI-V serial communication from IC7300
pinMode(7, OUTPUT); // CI-V serial communication to IC7300
Serial.begin(BAUD_RATE);  // Dump info to serial monitor 

 mySerial.begin(BAUD_RATE);
mySerial.listen();  // only one port can be made to listen with software serial

while (mySerial.available())mySerial.read(); // clean buffer

//Serial.print("waiting for CI-V");

wdt_enable(WDTO_1S); // Set WDT timer
}

void loop() {

  //mySerial.flush();
  mySerial.write(0xFE); 
  mySerial.write(0xFE); 
  mySerial.write(TRX_address); 
  mySerial.write(0xE1);
  mySerial.write(0x03); // Read freq
  mySerial.write(0xFD); // End sequence
  delay(40); 
// code to read //

  int stri[20];             // Receiving array of numbers (string)
 
  recvStr(stri);            // Data received from the serial, see void below
  recvStr(stri);            // No dump on screen !

  wdt_reset(); // Reset WDT 

  Serial.print(stri[8],HEX);
  Serial.print(".");
   p(stri[7]);
   p(stri[6]);
   p(stri[5]); 
  Serial.print(" Mhz\n");
  Serial.print(" ");

  delay(250);
  Serial.print("waiting for CI-V");
}

void recvStr(int *buf)
{
int i = 0;
int c;
while (1) {
if (mySerial.available() > 0) {
  c = mySerial.read();
  buf[i] = c;
  if (c == 0xFD) break;         //The end of the string is determined by the FD
  i++;
  }
}
buf[i] = '0xFD';
}


// Display HEX 0-9 to 00-09
void p(int X) {
if (0x00 <= X && X <= 0x09) {Serial.print("0");}
Serial.print(X, HEX);
}
