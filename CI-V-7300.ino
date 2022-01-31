/* This smal script will 'ask the IC-7300' the active frequency
*  (c) PA2EON - Eric
*/

#include <SoftwareSerial.h> // for comms to IC7300
#define BAUD_RATE 19200     // CI-V speed
#define TRX_address (0x94)  // HEX $94 = Icom IC-7300

// serial connection to the Arduino UNO
// RX = Icom radio to Arduino  : to pin 1 via resistor 4k7
// TX = Arduino to Icom radio  : to pin 2 via diode 1N4148, with pull up 10k to Vcc (5V) on tip of 3.5 mm connector

SoftwareSerial mySerial = SoftwareSerial(1, 2); // (RX, TX)
