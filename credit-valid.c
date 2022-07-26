#include <cs50.h>
#include <stdio.h>

int length(long n); // Returns length of number
bool valid(long n); // Checks whether number follows Luhn's algo or not
void whichcard(long n); // Checks which card it is

int main(void)
{
    long num;
    do
    {
        num = get_long("Number: ");
    }
    while (num < 0);

    int len = length(num);
    if (len != 13 && len != 15 && len != 16)
    {
        // If len not equals any of the above number
        printf("INVALID\n");
    }
    else
    {
        // Check if follows Luhn's algo
        if (valid(num))
        {
            whichcard(num);
        }
        else
        {
            printf("INVALID\n");
        }
    }


}

int length(long n)
{
    int count = 0;
    while (n > 0)
    {
        count++;
        n = n / 10;
    }
    return count;
}

bool valid(long n)
{
    int sum1 = 0, sum2 = 0; // sum1 for second to digit operations
    // sum2 for digits that weren't multiplied by 2

    int mod1, mod2; // mod1 for digits not getting multiplied by 2
    do
    {
        /* Calculation for sum2 */
        mod2 = n % 10;
        n = n / 10;
        sum2 += mod2;

        /* Calculation for sum1 */
        mod1 = n % 10;
        n = n / 10;
        mod1 = mod1 * 2; // If mod1*=2 results in any two digit number from 10 to 18; e.g. 12
        int r1 = mod1 % 10; // r1 to store 2 from 12
        int r2 = mod1 / 10; // And r2 to store 1 from 12
        sum1 += r1 + r2;
    }
    while (n > 0);

    int total = sum1 + sum2;
    /* Condition for valid checksum */
    if (total % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void whichcard(long n)
{
    int l = length(n);
    int start2; // To calculate starting 2 no's of credit card

    /* Computing starting 2 no's */
    do
    {
        n = n / 10;
    }
    while (n > 100);
    start2 = n;

    /* Condtions for valid credit cards*/
    if (l == 16 && start2 / 10 == 5 && (0 < start2 % 10 && start2 % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
    else if (l == 15 && start2 / 10 == 3 && (start2 % 10 == 4 || start2 % 10 == 7))
    {
        printf("AMEX\n");
    }
    else if ((l == 13 || l == 16) && (start2 / 10 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
