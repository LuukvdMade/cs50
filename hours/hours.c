#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{
    float average = 0;
    float total = 0;
    if (output == 'T')
    {
        for (int i = 0; i < weeks; i++)
        {
            total = hours[i] + total;
        }
        return total;
    }
    else if (output == 'A')
    {
        for (int j = 0; j < weeks; j++)
        {
            total = hours[j] + total;
        }
        average = total / weeks;
        return average;
    }
    return 0;
}