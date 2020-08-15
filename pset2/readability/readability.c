#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    //get a text from the user
    string text = get_string("Text: ");
    //get number of letters
    int n_letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            n_letters += 1;
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            n_letters += 1;
        }
    }
    //get number of words
    int n_words = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= '0'
                && text[i] <= '9'))
        {
            if ((text[i + 1] >= 'a' && text[i + 1] <= 'z') || (text[i + 1] >= 'A' && text[i + 1] <= 'Z') || (text[i + 1] >= '0'
                    && text[i + 1] <= '9') || text[i + 1] == '\'' || text[i + 1] == '-')
            {
            }
            else
            {
                n_words += 1;
            }
        }
    }
    //get number of sentences
    int n_sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= '0' && text[i] <= '9'))
        {
            if (text[i + 1] == '.' || text[i + 1] == '?' || text[i + 1] == '!')
            {
                n_sentences += 1;
            }
        }
    }
    //compute Coleman-Liau formula
    float L = (100 * (float) n_letters) / n_words;
    float S = (100 * (float) n_sentences) / n_words;
    float index = round(0.0588 * L - 0.296 * S - 15.8);
    //print results
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }
}
