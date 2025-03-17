#include <stdio.h>
#include <stdint.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define nested_max(a, b, c) (max(max(a, b), c))
// This looks like ass, avoid
#define very_max(a, b, c) (((a) > (b)) ? (((a) > (c)) ? (a) : (c)) : (((b) > (c)) ? (b) : (c)))

int main(int argc, char *argv[])
{
    printf("Max     : %d \n", max(1, 4));

    printf("Very Max: %d \n", very_max(1, 2, 3));
    printf("Very Max: %d \n", very_max(2, 3, 1));
    printf("Very Max: %d \n", very_max(3, 1, 2));

    printf("Nested Max: %d \n", very_max(1, 2, 3));
    printf("Nested Max: %d \n", very_max(2, 3, 1));
    printf("Nested Max: %d \n", very_max(3, 1, 2));

    return 0;
}
