#include <cs50.h>
#include <stdio.h>

int get_mario_int(string prompt);

int main(void)
{   
    int height = get_mario_int("Height: ");
    for (int i = height; i > 0; i--)
        {
        int space = i - 1;
            for (int s = space; s > 0; s--) {
                printf(" ");
            }
            for (int x = height - i; x > -1; x--) {
                printf("#");
            }
            printf("  ");
            for (int y = height - i; y > -1; y--) {
                printf("#");
            }
            printf("\n");       
        }  
}

int get_mario_int(string prompt)
{
    int n;
    do
    {
        n = get_int("%s", prompt);
    }
    while (8 < n || n < 1);
    return n;
}