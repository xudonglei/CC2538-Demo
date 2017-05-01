#define GPIO_C_DIR				0x400DB400
#define GPIO_C_DATA				0x400DB000

#define HWREG(x)                             \
	(*((volatile unsigned long *)(x)))

int main(void)
{
    volatile unsigned long ulLoopCount;

    // Set direction output and initial value for PC2 and PC0
    // Greed LED on PC2
    // Red LED on PC0
    HWREG(GPIO_C_DIR) |= 0x05;
    HWREG(GPIO_C_DATA + (0x05 << 2)) = 0;

    // Loop forever.
    while(1)
    {
        // Turn on both LED's.
        HWREG(GPIO_C_DATA + (0x05 << 2)) ^= 0x05;

        // Delay for a bit
        for(ulLoopCount = 600000; ulLoopCount > 0; ulLoopCount--)
        {
        }
    }
    return 0;
}
