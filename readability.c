#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int count_index(int letters, int words, int sentences);
int count_grade(int index);

int main(void)
{
    string text = get_string("Text: "); // promt the user for some text
    // Count the number of letters, words, and sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    // Compute the Coleman-Liau index
    int index = count_index(letters, words, sentences);
    int grade = count_grade(index);
    // Print grade level
}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, len = strlen(text); i < len;
         i++) // some kind of looop with int isalpha(char a);
    {
        if (isalpha(text[i]))
        {
            letters += 1;
        }
    }
    return letters; // return number of letters in text
}

int count_words(string text)
{
    int words = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isblank(text[i]))
        {
            words += 1;
        }
    } // int isblank(char c);

    return words; // return number of words in text
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (ispunct(text[i]))
        {
            sentences += 1;
        }
    }
    // loop that finds how many "." "?" "!" are in text
    return sentences; // Return the number of sentences in text
}

int count_index(int letters, int words, int sentences)
{
    int index = 0;

    float l = letters / words * 100;   // average number of letters per 100 words
    float s = sentences / words * 100; // average number of sentences per 100 words

    index = round(0.0588 * l - 0.296 * s - 15.8); // count index = 0.0588 * L - 0.296 * S - 15.8

    // round index to nearest integer
    return index;
}

int count_grade(int index)
{
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
        printf("Grade %i\n", index);
    }
    return 0;
}
