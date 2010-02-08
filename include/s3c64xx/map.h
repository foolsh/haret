/* haret/include/s3c64xx/map.h
 *
*/

#define S3C6400_PA_IRQ		(0x71200000) // VIC0
#define S3C6400_PA_VIC0		(0x71200000) // VIC0
#define S3C6400_PA_VIC1		(0x71300000) // VIC1
//#define S3C2410_PA_MEMCTRL	(0x48000000) //?
#define S3C6400_PA_DMA0		(0x75000000)
#define S3C6400_PA_DMA1		(0x75100000)
#define S3C6400_PA_SDMA0	(0x7db00000) //HANG ON READ
#define S3C6400_PA_SDMA1	(0x7dc00000)
//#define S3C2410_PA_CLKPWR	(0x4C000000)
#define S3C6400_PA_LCD		(0x77100000)
#define S3C6400_PA_NAND		(0x70200000)
//#define S3C2400_PA_MMC	(0x15A00000)
#define S3C6410_PA_MMC0		(0x7C200000)
#define S3C6410_PA_MMC1		(0x7C300000)
#define S3C6410_PA_MMC2		(0x7C400000)
#define S3C6400_PA_UART		(0x7F005000)
#define S3C6400_SZ_UART		SZ_4K
#define S3C6400_PA_TIMER	(0x7F006000)
//#define S3C2410_PA_USBDEV	(0x52000000)
#define S3C6400_PA_USBHOST	(0x74300000)
#define S3C6410_PA_USBHOST	(0x74300000)
#define S3C6410_PA_OTG		(0x7C000000)
#define S3C6410_PA_OTGSFR	(0x7C100000)
#define S3C6400_PA_WATCHDOG	(0x7E004000)
#define S3C6400_PA_IIC0		(0x7F004000)
#define S3C6400_PA_IIC1		(0x7F00F000)
#define S3C6400_PA_IIS		(0x7F002000)
#define S3C6410_PA_IIS_V40	(0x7F00D000)
#define S3C6400_PA_GPIO		(0x7F008000)
#define S3C6400_SZ_GPIO		SZ_4K
#define S3C6400_PA_RTC		(0x7E005000)
#define S3C6400_PA_ADC		(0x7E00B000)
#define S3C6400_PA_SPI		(0x7F00B000)
//#define S3C2410_PA_SDI	(0x5A000000)
#define S3C6400_PA_CAMIF	(0x78000000)

#define S3C6410_USB_SIG_MASK 	(0x7E00F900) //Set Bit 16 to 0 before shutdown (or not...) pfb 0x7E00F902 1 0

#define S3C64XX_VA_GPIO (0x00) //? to check