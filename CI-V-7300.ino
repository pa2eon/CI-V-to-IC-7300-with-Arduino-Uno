/* This small script will 'ask the IC-7300' the active frequency
*  (c) PA2EON - Version 0.1 with LCD - 0x26 = address LCD
*  To do - correct routine to display correct !
*        - while () routine check
 */
#include <Wire.h>               // Library for I2C communication
#include <LiquidCrystal_I2C.h>  // Library for LCD
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x26, 20, 4); // Change to (0x26,20,4) for 20x4 LCD.

#include <SoftwareSerial.h>   // for comms to IC7300
#include <avr/wdt.h>          // Watchdog timer
#define BAUD_RATE 19200       // CI-V speed
#define TRX_address (0x94)    // HEX $94 = Icom IC-7300

// serial connection to the Arduino UNO
// RX = Icom radio to Arduino  : to pin 4 via resistor 4k7
// TX = Arduino to Icom radio  : to pin 7 via diode 1N4148, with pull up 10k to Vcc (5V) on tip of 3.5 mm connector

SoftwareSerial mySerial = SoftwareSerial(4, 7); // (RX, TX)

void setup() { 

  pinMode(4, INPUT);   // CI-V serial communication from IC7300
  pinMode(7, OUTPUT); // CI-V serial communication to IC7300
  mySerial.begin(BAUD_RATE);
  mySerial.listen();  // only one port can be made to listen with software serial
 
  lcd.init();
  lcd.backlight();
  //lcd.begin(20,4);
  //lcd.setCursor(0, 2);
  //lcd.print("CI-V address 94H");  // If used it mix up the LCD screen !!
  
  while (mySerial.available())mySerial.read(); // clean buffer
  wdt_enable(WDTO_1S); // Set WDT timer
 }

void loop() {

  // Send ci-v command
  mySerial.write(0xFE); 
  mySerial.write(0xFE); 
  mySerial.write(TRX_address); 
  mySerial.write(0xE0);
  mySerial.write(0x03); // Read freq
  mySerial.write(0xFD); // End sequence
  delay(40); 
  
  int stri[20];             // Receiving array of numbers (string)
  recvStr(stri);            // Data received from the serial, see void below
  
  wdt_reset(); // Reset WDT 

  //lcd.begin(20,4);
  lcd.setCursor(0, 0);
  lcd.print(stri[8],HEX);
  lcd.print(".");
   p(stri[7]);              // p value 0-9 to 00-09 see void below
   p(stri[6]);
   p(stri[5]); 
  lcd.setCursor(8, 0); 
  //lcd.print(" Mhz");
  lcd.print(" Mhz at 0x94");
  lcd.print("    ");
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
if (0x00 <= X && X <= 0x09) {lcd.print("0");}
lcd.print(X, HEX);  
}
