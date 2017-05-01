#include <stdint.h>

#define FLASH_START_ADDR                0x00200000
#define BOOTLOADER_BACKDOOR_ENABLE      0xF3FFFFFF

//*****************************************************************************
//
// Customer Configuration Area in Lock Page
// Holds Image Vector table address (bytes 2013 - 2015) and
// Image Valid bytes (bytes 2008 -2011)
//
//*****************************************************************************
typedef struct
{
    uint32_t ui32BootldrCfg;
    uint32_t ui32ImageValid;
    uint32_t ui32ImageVectorAddr;
}
lockPageCCA_t;

__attribute__ ((section(".flashcca"), used))
const lockPageCCA_t __cca =
{
  BOOTLOADER_BACKDOOR_ENABLE,  // Bootloader backdoor enabled
  0,                            // Image valid bytes
  FLASH_START_ADDR              // Vector table located at flash start address
};
