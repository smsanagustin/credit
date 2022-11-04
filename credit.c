#include <stdio.h>
#include <cs50.h>
#include <math.h>

void invalid(void);
int main(void)
{
    long int cardNumber = get_long("Card number: ");
    long int y = cardNumber;
    int sum1 = 0;
    while (y > 0)
    {
        int remainder1 = y % 10;
        sum1 = sum1 + remainder1;
        y = y / 100;
    }
    long int u = cardNumber;
    int sum2 = 0;
    while (u > 0)
    {
        u = u / 10;
        int remainder2 = u % 10;
        u = u / 10;
        remainder2 *= 2;
        while (remainder2 > 0)
        {
            int remainder3 = remainder2 % 10;
            sum2 = sum2 + remainder3;
            remainder2 = remainder2 / 10;
        }
    }

    int totalSum = sum1 + sum2;
    if (totalSum % 10 == 0)
    {
        int digitCount = 0;
        long int x = cardNumber;
        while (x > 0)
        {
            x = x / 10;
            digitCount++;
        }

        if (digitCount == 15)
        {
            long int n = cardNumber / (pow(10, 13));
            if (n == 34 || n == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                invalid();
            }
        }
        else if (digitCount == 16)
        {
            long int a = cardNumber / (pow(10, 14));
            if (a > 50 && a < 56)
            {
                printf("MASTERCARD\n");
            }
            else if (a > 39 && a < 50)
            {
                printf("VISA\n");
            }
            else
            {
                invalid();
            }
        }
        else if (digitCount == 13)
        {
            long int b = cardNumber / (pow(10, 12));
            if (b == 4)
            {
                printf("VISA\n");
            }
            else
            {
                invalid();
            }
        }
        else
        {
            invalid();
        }
    }
    else
    {
        invalid();
    }
}

void invalid(void)
{
    printf("INVALID\n");
}