#include <stdio.h>
#include <stdint.h>

void set(uint32_t *target, uint8_t position)
{
    if (position > 31)
    {
        return;
    }

    uint32_t mask = (0x1 << position);

    *target |= mask;
}

void reset(uint32_t *target, uint8_t position)
{
    if (position > 31)
    {
        return;
    }

    uint32_t mask = ~(0x1 << position);

    *target &= mask;
}

int main(int argc, char *argv[])
{
    uint32_t value = 0;

    printf("Original: %d \n", value);

    set(&value, 0);
    set(&value, 1);

    printf("Set: %d \n", value);

    reset(&value, 0);

    printf("Reset: %d \n", value);

    return 0;
}
