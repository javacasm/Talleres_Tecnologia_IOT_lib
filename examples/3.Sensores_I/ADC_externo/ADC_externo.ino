#include "Wire.h"
int PCF8591=0x48; // I2C bus address
byte ana0, ana1, ana2, ana3;
void setup()
{
 Wire.pins(0,2);// just to make sure
 Wire.begin(0,2);// the SDA and SCL
}
void loop()
{
 Wire.beginTransmission(PCF8591); // wake up PCF8591
 Wire.write(0x04); // control byte: reads ADC0 then auto-increment
 Wire.endTransmission(); // end tranmission
 Wire.requestFrom(PCF8591, 5);
 ana0=Wire.read();// throw this one away

 ana0=Wire.read();
 ana1=Wire.read();
 ana2=Wire.read();
 ana3=Wire.read();
 Serial.print(ana0);
 Serial.print(", ");
 Serial.print(ana1);
 Serial.print(", ");
 Serial.print(ana2);
 Serial.print(", ");
 Serial.print(ana3);
 Serial.println("");
}

