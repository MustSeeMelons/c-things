#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void stack_arrray()
{
    const uint8_t d = 8;
    uint8_t arr[8] = {0, 1, 2, 3, 4, 5, 6, 7};

    printf("1D Stack test: \n\n");

    for (uint8_t i = 0; i < d; i++)
    {
        printf("1D at %d = %d\n\r", i, arr[i]);
    }

    const uint8_t other_d = 3;
    uint8_t other_arr[3][8] = {
        {0, 1, 2, 3, 4, 5, 6, 7},
        {8, 9, 10, 11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20, 21, 22, 23},
    };

    printf("\n\n2D Stack test: \n\n");

    for (uint8_t i = 0; i < other_d; i++)
    {
        for (uint8_t j = 0; j < d; j++)
        {
            printf("%d;%d = %2d, ", i, j, other_arr[i][j]);
        }
        printf("\n\r");
    }
}

void p_array()
{
    printf("1D Pointer test: \n\n");

    const uint8_t d = 8;
    uint8_t *arr = malloc(sizeof(uint8_t) * d);

    // Fill in the array
    uint8_t *p_arr = arr;
    for (uint8_t i = 0; i < d; i++)
    {
        *p_arr = i;
        p_arr++;
    }

    // Print the array
    p_arr = arr;
    for (uint8_t i = 0; i < d; i++)
    {
        printf("1D P at %d = %d\n\r", i, *p_arr);
        p_arr++;
    }

    free(arr);

    printf("\n\n2D Pointer test: \n\n");

    const uint8_t other_d = 8;

    uint8_t **other_arr;

    // Allocate room for pointers to arrays
    other_arr = malloc(sizeof(uint8_t) * d);

    for (uint8_t i = 0; i < other_d; i++)
    {
        // Make each arr point to another array
        other_arr[i] = malloc(sizeof(uint8_t *) * other_d);
    }

    // Set values
    for (uint8_t i = 0; i < d; i++)
    {
        for (uint8_t j = 0; j < other_d; j++)
        {
            other_arr[i][j] = i + j;
        }
    }

    // Clear calues
    for (uint8_t i = 0; i < d; i++)
    {
        for (uint8_t j = 0; j < other_d; j++)
        {
            printf("%d;%d = %2d ", i, j, other_arr[i][j]);
        }
        printf("\n\r");
    }

    for (uint8_t i = 0; i < d; i++)
    {
        free(other_arr[i]);
    }

    free(other_arr);
}

int main(int argc, char *argv[])
{
    // stack_arrray();
    // p_array();

    // const uint8_t d = 3;

    // uint8_t arr_1[d] = {1, 2, 3};
    // uint8_t arr_2[d] = {4, 5, 6};
    // uint8_t arr_3[d] = {7, 8, 9};

    // uint8_t *arr[d] = {arr_1, arr_2, arr_3};

    // printf("%d\n\r", arr[0][0]);
    // printf("%d\n\r", arr[1][0]);
    // printf("%d\n\r", arr[2][0]);
}