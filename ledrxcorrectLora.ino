#include <SPI.h>
#include <LoRa.h>

int led = 3;
String readString;
 char data = 0;

void setup() {
//  Serial.begin(9600);
  // while (!Serial);

// Serial.println(" Receiver A");
if (!LoRa.begin(433E6)) {
    Serial.println(" LoRa Error");
    while (1);
  }

   LoRa.setSpreadingFactor(10);
  LoRa.setSignalBandwidth(62.5E3);
   LoRa.crc();  
  
     pinMode (led, OUTPUT);

  }
 void loop() {
 int packetSize = LoRa.parsePacket();
 if (packetSize)     {
// receive a packet
 }
 Serial.print("received packet from A : ");   // read packet

  while (LoRa.available())
 {
    data = LoRa.read();
   if (data == ',')   
   {
      if (readString.length() > 1)  
{
  Serial.print(readString);  //prints string to serial port
        Serial.println(' ');  // prints delimiting "," */ 
        digitalWrite(led, HIGH); // LED ON
        delay(500);
        digitalWrite(led, LOW);  // LED OFF
        delay(500);          // do stuff with the captured read string
       readString="";  // clear variable for new input   

      }
   }
  else  {
 readString += data;  //makes the string  readString 
   }    
     } 
  }  
