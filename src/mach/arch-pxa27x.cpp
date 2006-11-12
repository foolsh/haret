#include "machines.h"
#include "cpu.h" // DEF_GETCPR
#include "memory.h" // memPhysMap
#include "util.h" // ARRAY_SIZE
#define CONFIG_PXA27x
#include "pxa2xx.h" // pxaDMA

DEF_GETCPR(get_p15r0, 15, 0, c0, c0, 0)

MachinePXA27x::MachinePXA27x()
{
    name = "Generic PXA27x";
}

int
MachinePXA27x::detect()
{
    uint32 p15r0 = get_p15r0();
    return ((p15r0 >> 24) == 'i'
            && ((p15r0 >> 13) & 0x7) == 2
            && ((p15r0 >> 4) & 0x3f) == 17);
}

int
MachinePXA27x::preHardwareShutdown()
{
    MachinePXA::preHardwareShutdown();
    cken = (uint32 *)memPhysMap(CKEN);
    uhccoms = (uint32 *)memPhysMap(UHCCOMS);
    return 0;
}

#define DCSR_REG_COUNT27x    32

void
Reset27xDMA(pxaDMA *dma)
{
    // Set DMAs to Stop state
    for (int i = 0; i < DCSR_REG_COUNT27x; i++)
        dma->DCSR [i] = DCSR_NODESC | DCSR_ENDINTR | DCSR_STARTINTR | DCSR_BUSERR;
}

void
Reset27xUDC(pxaUDC *udc)
{
    udc->_UDCCR = 0;
}

// disable USB host.
void
Reset27xUHC(volatile uint32 *uhccoms)
{
    // Reset usb host
    *uhccoms=1;
}

void
MachinePXA27x::hardwareShutdown()
{
    Reset27xDMA((pxaDMA*)dma);
    Reset27xUDC((pxaUDC*)udc);
    Reset27xUHC(uhccoms);

    *cken=(*cken)&(~(
//    CKEN5_STUART|
//    CKEN6_FFUART|
//    CKEN7_BTUART|
                       CKEN10_USBHOST|
                       CKEN11_USB|
                       CKEN12_MMC|
                       CKEN13_FICP|
                       CKEN19_KEYPAD|
                       CKEN23_SSP1|
                       CKEN24_CAMERA
                       ));
}

static const char * const irq_names[] = {
    "SSP3", "MSL", "USBh2", "USBh1",
    "Keypad", "MemoryStick", "pI2C", "OS Timer",
    "GPIO0", "GPIO1", "GPIOx", "USBc",
    "PMU", "I2S", "AC97", "USIM",
    "SSP2", "LCD", "I2C", "ICP",
    "STUART", "BTUART", "FFUART", "MMC",
    "SSP", "DMA", "TMR0", "TMR1",
    "TMR2", "TMR3", "RTC0", "RTC1",
    "TPM", "QCap",
};

const char *
MachinePXA27x::getIrqName(uint irq)
{
    if (irq >= ARRAY_SIZE(irq_names))
        return "Unknown";
    return irq_names[irq];
}