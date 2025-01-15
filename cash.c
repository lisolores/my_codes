#include <cs50.h>
#include <stdio.h>

int calculate_coins(const int q, const int d, const int n, int cents);

int main(void)
{
    // Prompt the user for change owed, in cents
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    const int q = 25;
    const int d = 10;
    const int n = 5;
    int coins = calculate_coins(q, d, n, cents);
    printf("%i\n", coins);
}

int calculate_coins(const int q, const int d, const int n, int cents)
{
    int quarters = cents / q;
    cents = cents - (quarters * q);

    int dimes = cents / d;
    cents = cents - (dimes * d);

    int nickels = cents / n;
    cents = cents - (nickels * n);

    int coin = quarters + dimes + nickels + cents;

    return coin;
}
