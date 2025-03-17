#include <stdio.h>
#include <stdint.h>

void perform_swap(uint32_t *source, uint32_t *target)
{
    // Reset target
    *target = 0;

    // Shift bytes into LSB to consume their souls
    uint8_t first = *source >> (8 * 3) & 0xFF; // 0xFF reduddant due to uint8
    uint8_t second = *source >> (8 * 2) & 0xFF;
    uint8_t third = *source >> (8 * 1) & 0xFF;
    uint8_t fourth = (uint8_t)*source;

    // printf("First: %#x Second: %#x Third: %#x Fourth: %#x \n\r", first, second, third, fourth);

    // Or it all together
    *target = first | (second << 8) | (third << 16) | (fourth << 24);
}

int main(int argc, char *argv[])
{
    uint32_t original = 0xAABBCCDD;
    uint32_t swap = 0x0;

    perform_swap(&original, &swap);

    printf("Original: %#010x\n\r", original);
    printf("Swap:     %#010x\n\r", swap);

    return 0;
}
