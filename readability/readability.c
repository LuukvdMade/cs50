#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentances(string text);

int main(void)
{
    string text = get_string("Text: ");

    float letter_number = count_letters(text);

    float words_number = count_words(text);

    float sentance_number = count_sentances(text);


    float l = 100 * ((float)letter_number / (float)words_number);
    float s = 100 * ((float)sentance_number / (float)words_number);

    int index = round(0.0588 * l - 0.296 * s - 15.8);
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    if (isalpha(text[i]))
    {
        letters++;
    }
    return letters;
}

int count_words(string text)
{
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    if (text[i] == ' ')
    {
        words++;
    }
    return words;
}

int count_sentances(string text)
{
    int sentances = 0;
    for (int i = 0; i < strlen(text); i++)
    if (text[i] == '.' || text [i] == '?' || text[i] == '!')
    {
        sentances++;
    }
    return sentances;
}