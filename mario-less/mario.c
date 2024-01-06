#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //get int from user
    int hight;
    do
    {
        hight = get_int("Hight of the pyramid between 1 - 8? ");
    }
    while (1 > hight || hight > 8);

    //print pyramid

    for (int i = 0; i < hight; i++)
    {
        for (int k = hight - i - 1; k > 0; k--)
        {
            printf(" ");
        }
            for (int j = 0; j <= i; j++)
            {
                printf("#");
            }
        printf("\n");
    }
}