#include <stdio.h>
#include <stdint.h>

// Will oveflow
void arithmetic_swap(uint32_t *a, uint32_t *b)
{
    // a = 1, b = 2
    *a = *a + *b; // a = 3
    *b = *a - *b; // b = 1
    *a = *a - *b; // a = 2
}

void xor_swap(uint32_t *a, uint32_t *b)
{
    // a ^ a = 0
    // a ^ b == b ^ a
    // (a ^ b) ^ c = a ^ (b ^ c)

    *a = *a ^ *b; // Combined difference
    *b = *a ^ *b; // Cancel out b, left with a
    *a = *a ^ *b; // Cancel out a, left with b
}

int main(int argc, char *argv[])
{
    uint32_t one = 1;
    uint32_t other = 2;

    printf("Originals: a: %d, b: %d \n", one, other);

    arithmetic_swap(&one, &other);

    printf("Swap     : a: %d, b: %d \n", one, other);

    xor_swap(&one, &other);

    printf("Swap back: a: %d, b: %d \n", one, other);

    return 0;
}
