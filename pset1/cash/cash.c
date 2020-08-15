#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change;
    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0);
    int cents = round(change * 100);
    int count = 0;
    while (cents >= 25)
    {
        cents -= 25;
        count++;
    }
    while (cents >= 10)
    {
        cents -= 10;
        count++;
    }
    while (cents >= 5)
    {
        cents -= 5;
        count++;
    }
    while (cents >= 1)
    {
        cents -= 1;
        count++;
    }
    printf("%i\n", count);
}