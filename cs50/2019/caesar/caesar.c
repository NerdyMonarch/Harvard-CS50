#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)  //Checks if two arguements are received (No more/ No less)
    {
        printf("Usage: ./caesar key\n");  //If two arguements aren't given, error message is printed
        return 1;
    }
    for (int i = 0, h = strlen(argv[1]); i < h; i++) //Checks if every char in the second arguement is a number
    {
        if (isdigit(argv[1][i]) == false)
        {
            printf("Usage: ./caesar key\n"); //Prints error if char isn't a number
            return 1;
        }
    }
    int key = atoi(argv[1]); //Changes second arguement from string to int
    string plainText = get_string("plaintext: "); //Gets plaintext from user
    printf("encryptedtext: ");
    for (int i = 0, h = strlen(plainText); i < h; i++)
    {
        int alphaChar = plainText[i]; //Turns character into acsii value
        int betaChar;
        char charlieChar;
        if (isupper(plainText[i])) //If uppercase
        {
            alphaChar -= 65; //Turns acsii value into alphabetical index
            betaChar = (alphaChar + key) % 26; //Encrypts
            charlieChar = betaChar + 65; //Turns alphabetical index into acsii value
        }
        else //If lowercase
        {
            alphaChar -= 97; //Turns acsii value into alphabetical index
            betaChar = (alphaChar + key) % 26; // Encrypts
            charlieChar = betaChar + 97; //Turns alphabetical index into acsii value
        }
        if (isspace(plainText[i])) //Preserves spaces written by user
        {
            charlieChar = 32; //Acsii 32 = space
        }
        printf("%c", charlieChar); //Prints Encrypted character
    }
    printf("\n");
}