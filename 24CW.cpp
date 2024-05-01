#include "lib_24CW.h"
#include <Wire.h>

lib_24CW::lib_24CW()
{ 
    Wire.begin();
}

uint8_t lib_24CW::read( uint16_t addr )
{
    uint8_t data = 0x55;

    Wire.beginTransmission(EEPROM_24CW_7BIT_BASE_ADDRESS);

    Wire.write((int)(addr >> 8));   // MSB
    Wire.write((int)(addr & 0xFF)); // LSB
    Wire.endTransmission();

    Wire.requestFrom((int)EEPROM_24CW_7BIT_BASE_ADDRESS, (int)1);

    data = Wire.read();

    return data;
}

uint8_t lib_24CW::write( uint16_t addr, uint8_t byte )
{
    Wire.beginTransmission(EEPROM_24CW_7BIT_BASE_ADDRESS);
    Wire.write((int)(addr >> 8));   // MSB
    Wire.write((int)(addr & 0xFF)); // LSB

    Wire.write(byte);
    Wire.endTransmission();

    delay(5);

    return 1;
}