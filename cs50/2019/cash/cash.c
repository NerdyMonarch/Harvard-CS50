#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void) {
    float cash = get_float("Change: ");
    int change = round(cash * 100);
        int quarters = change / 25;
            change = change % 25;
        int dimes = change / 10;
            change = change % 10;
        int nickels = change / 5;
            change = change % 5;
        int coins = quarters + dimes + nickels + change;
    printf("coins: %i", coins);
}