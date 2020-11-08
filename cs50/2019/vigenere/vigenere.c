#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2) //Makes sure 2 arguements are provided
    {
        printf("./vigenere keyword\n");
        return 1;
    }
    for (int i = 0, h = strlen(argv[1]); i < h; i++) //Checks if every char is a letter
    {
        if (isalpha(argv[1][i]) == false)
        {
            printf("./vigenere keyword\n");
            return 1;
        }
    }
    int key[strlen(argv[1])]; //Declares an array to store the Keyword
    for (int i = 0, h = strlen(argv[1]); i < h; i++) //Loops for every letter in the keyword
    {
        int keyNumber = argv[1][i];
        if (isupper(argv[1][i] == true)) //Distinguishes uppercase to lowercase
        {
            key[i] = keyNumber - 65; //Converts keyword char into alphabetical code
        }
        else
        {
            key[i] = keyNumber - 97; //Converts keyword char into alphabetical code
        }
    }
    string printText = get_string("printtext: "); //Prompts user for printtext
    printf("encryptedtext: ");
    for (int i = 0, h = strlen(printText); i < h; i++) //Loops for every letter in the string
    {
        int processingChar = printText[i];
        if (processingChar != 32) //Checks if the char is a space to save processing power
        {
            if (isupper(printText[i]) == true) //Checks if the letter is uppercase
            {
                processingChar -= 65; //Turns letter to alpha code
                processingChar += key[i % strlen(argv[1])]; //Encrypts using keyword
                processingChar += 65; //Returns to ascii
                printf("%c", processingChar); //Prints Letter
               
            }
            else //If Lowercase
            {
                processingChar -= 97; //Repeat of uppercase process
                processingChar += key[i % strlen(argv[1])];
                processingChar += 97;
                printf("%c", processingChar);
            }
        }
        else
        {
            printf(" "); //If the value was a space, then a space is printed.
        }
    }
    printf("\n");
}