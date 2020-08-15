#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");  
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            printf(" ");
        }
        
        for (int z = -1; z < i; z++)
        {
            printf("#");
        }
        printf("  ");
        for (int z = -1; z < i; z++)
        {
            printf("#");
        }
        printf("\n");
    }
}