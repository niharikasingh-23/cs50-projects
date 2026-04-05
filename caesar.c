#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string digits);
char rotate(char c, int key);

int main(int argc, string argv[])
{
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", rotate(plaintext[i], key)); // prints all chars side by side
    }

    printf("\n"); // newline after full ciphertext
    return 0;
}

// checking the key for all digits and no alphabets
bool only_digits(string digits)
{
    for (int i = 0, n = strlen(digits); i < n; i++)
    {
        if (!isdigit(digits[i])) // if any char is not a digit
        {
            return false; // returns false immediately
        }
    }
    return true; // all chars are digits
}

// function to rotate a char by key positions (shifting forward)
char rotate(char c, int key) // takes a single char from plaintext, rotates it by key, returns the rotated char
{
    if (isupper(c))
    {
        return (c - 'A' + key) % 26 + 'A'; // converts c to a number bw 0-25, adds key, % 26 ensures
                                           // it stays within 0-25, + 'A' converts back to ASCII
    }
    else if (islower(c))
    {
        return (c - 'a' + key) % 26 + 'a';
    }
    else // if not a letter
    {
        return c;
    }
}
