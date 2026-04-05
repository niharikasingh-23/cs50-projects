#include <cs50.h>
#include <stdio.h>

void print_row(int spaces, int bricksl, int bricksr);

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1);

    for (int i = 0; i < n; i++)
    {
        print_row(n - i - 1, i + 1, i + 1);
    }
}

void print_row(int spaces, int bricksl, int bricksr)
{
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }

    for (int i = 0; i < bricksl; i++)
    {
        printf("#");
    }
    printf("  ");

    for (int i = 0; i < bricksr; i++)
    {
        printf("#");
    }
    printf("\n");
}
