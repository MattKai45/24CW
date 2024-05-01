/* 
 * lib_24CW.h - Bare minimum library for communicating with the Microchip
 * 24CW EEPROM modules using I2C.
 * 
 *
 * Created on June 13, 2023 by Matthew Kaiser
 */

#ifndef LIB_24CW_H
#define	LIB_24CW_H

#include "stdint.h"
#include "Arduino.h"

/**
* 24CW 7-bit base address. This should be shifted by 1 bit to include the R/W bit.
* The base address would appear as 0xA0 for read and 0xA1 for write. If the A0-A2 pins
* are pulled high the appropriate bit should be set. Example, If A1 is high:
* EEPROM_24CW_ADDR = EEPROM_24CW_7BIT_BASE_ADDRESS | EEPROM_24CW_A1.
*/
#define EEPROM_24CW_7BIT_BASE_ADDRESS (uint8_t)0x50
#define EEPROM_24CW_A0                (uint8_t)(1 << 0)
#define EEPROM_24CW_A1                (uint8_t)(1 << 1)
#define EEPROM_24CW_A2                (uint8_t)(1 << 2)

class lib_24CW {
    public:
        lib_24CW();
        uint8_t read( uint16_t addr );
        uint8_t write( uint16_t addr, uint8_t byte );
    
    private:

};

#endif	/* LIB_24CW_H */