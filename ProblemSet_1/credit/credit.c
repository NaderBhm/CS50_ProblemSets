#include <cs50.h>
#include <math.h>
#include <stdio.h>

int getLength(long number);
int formula(long number, unsigned len);
string cardType(long number, unsigned len);

int main()
{
    long number = get_long("Number: ");
    unsigned len = getLength(number);
    if (formula(number, len) == 0)
        printf("INVALID\n");
    else
        printf("%s", cardType(number, len));
}

int getLength(long number)
{
    int count = 0;
    while (number != 0)
    {
        number /= 10;
        count++;
    }
    return count;
}

int formula(long number, unsigned len)
{
    int sum = 0;
    bool MULTIPLY = false;
    for (int i = 0; i < len; i++)
    {
        int digit = number % 10;
        if (MULTIPLY)
        {
            int doubled = digit * 2;
            sum += (doubled > 9) ? (doubled % 10 + doubled / 10) : doubled;
        }
        else
        {
            sum += digit;
        }

        MULTIPLY = !MULTIPLY;
        number /= 10;
    }

    return sum % 10 == 0;
}

string cardType(long number, unsigned len)
{
    int firstN = number / (long) pow(10, len - 1);
    int secondN = (number / (long) pow(10, len - 2)) % 10;
    if ((firstN == 3 && (secondN == 4 || secondN == 7) && len == 15))
        return "AMEX\n";
    else if ((firstN == 5 && (secondN >= 1 && secondN <= 5) && len == 16))
        return "MASTERCARD\n";
    else if (firstN == 4 && (len == 13 || len == 16))
        return "VISA\n";
    else
        return "INVALID\n";
}
