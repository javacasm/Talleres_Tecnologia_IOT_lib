// Tomado de http://tronixstuff.com/2013/06/17/tutorial-arduino-and-pcf8591-adc-dac-ic/

#define PCF8591 (0x48) // I2C bus address

#define VREF 4.49    // Medimos el voltaje de la alimentacion

#include <Wire.h>

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
    Serial.begin(9600);

    Wire.pins(D2,D1);// just to make sure
    Wire.begin(D2,D1);
    lcd.begin();

    lcd.home();
    lcd.backlight();
}

void loop() {
   for (int i=0; i<=255; i++)  {

     Wire.beginTransmission(PCF8591); // wake up PCF8591
     Wire.write(0x40); // turn on DAC b1000000
     Wire.write(i);
     Wire.endTransmission();

     float voltaje = 4.49 * i / 255;

     lcd.setCursor(0, 0);
     lcd.print(i);
     lcd.print(" ");
     lcd.print(voltaje);
     lcd.print("V");

     Serial.print(i);
     Serial.print(", ");
     Serial.println(voltaje);

     delay(1000);
   }
}
