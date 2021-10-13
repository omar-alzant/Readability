#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// index = 0.0588 * L - 0.296 * S - 15.8
// L :  the average number of letters per 100 words in the text
// S : the average number of sentences per 100 words in the text
// grade < 1 : before grade 1
// grade > 16 : grade 16+

// #include <ctype.h>
// isalpha - check whether a character is alphabetical
//  isdigit - check whether a character is a digit
// islower - check whether a character is lowercase
//  isspace - check whether a character is whitespace
// isupper - check whether a character is uppercase
// strlen - calculate the length of a string

int letter(string s);
int world(string s);
int sentence(string s);




int main(void)
{
    string s = get_string("enter the phrase to verify your grade : ");

    int W = world(s);
    int L = letter(s)  ;
    int S = sentence(s) ;

    float index =  0.0588 * L * 100 / W - 0.296 * S * 100 / W - 15.8;

    int grade = (int)round(index) ;

    if (grade < 1)
    {
        printf("Before Grade 1\n");

    }
    else
    {

        if (grade > 16)
        {
            printf("Grade 16+\n");
        }
        else
        {
            if (grade > 1 | grade < 16)
            {
                printf("Grade %i\n", grade);
            }
        }
    }

//printf("let : %i , sent: %i , wor : %i", L,S,W);
}


// nbr of world

int world(string s)
{
    int count = 1;

    for (int i = 0, n = strlen(s); i < n ; i++)
    {
        if (isspace(s[i]))
        {
            count ++;
        }
    }
    return count;
}


// nbr of letter

int letter(string s)
{
    int count = 0  ;
    for (int i = 0, n = strlen(s); i < n ; i++)
    {
        if (s[i] == '.')
        {
            continue;
        }
        if (islower(s[i]) || isupper(s[i]))
        {
            count ++;
        }
    }

    return count ;

}

// nbr of sentence

int sentence(string s)
{
    int count = 0  ;

    for (int i = 0, n = strlen(s); i < n ; i++)
    {
        if (s[i] == '!' || s[i] == '?' || s[i] == '.')
        {
            count ++ ;
        }
    }
    return count ;
}