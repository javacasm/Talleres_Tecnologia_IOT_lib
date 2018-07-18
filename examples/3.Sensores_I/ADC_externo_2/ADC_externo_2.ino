// Ejemplo tomado de https://arduinodiy.wordpress.com/2016/10/17/adding-a-pcf-8591-adcdac-to-esp8266-01/

#include <Wire.h>

#define ADC0 0x00 // control bytes for reading individual ADCs
#define ADC1 0x01
#define ADC2 0x02
#define ADC3 0x03


int PCF8591 = 0x48; // I2C bus address
byte ana0, ana1, ana2, ana3;
void setup()
{
 Wire.pins(D2,D1);// just to make sure
 Wire.begin(D2,D1);// the SDA and SCL

 Serial.begin(9600);
}
void loop()
{
 Wire.beginTransmission(PCF8591); // wake up PCF8591
 Wire.write(ADC0); // control byte - read ADC0
 Wire.endTransmission(); // end tranmission
 Wire.requestFrom(PCF8591, 2);
 ana0=Wire.read();
 ana0=Wire.read();
 Wire.beginTransmission(PCF8591); // wake up PCF8591
 Wire.write(ADC1); // control byte - read ADC1
 Wire.endTransmission(); // end tranmission
 Wire.requestFrom(PCF8591, 2);
 ana1=Wire.read();
 ana1=Wire.read();
 Wire.beginTransmission(PCF8591); // wake up PCF8591
 Wire.write(ADC2); // control byte - read ADC2
 Wire.endTransmission(); // end tranmission
 Wire.requestFrom(PCF8591, 2);
 ana2=Wire.read();
 ana2=Wire.read();
 Wire.beginTransmission(PCF8591); // wake up PCF8591
 Wire.write(ADC3); // control byte - read ADC3
 Wire.endTransmission(); // end tranmission
 Wire.requestFrom(PCF8591, 2);
 ana3=Wire.read();
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
