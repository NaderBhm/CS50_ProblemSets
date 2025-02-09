#include <cs50.h>
#include <stdio.h>

int getLength();
void pyramid(int len);

int main()
{
    int length = getLength();
    pyramid(length);
}

int getLength()
{
    int x;
    do
    {
        x = get_int("Height: ");
    }
    while (x > 8 || x < 1);
    return x;
}

void pyramid(int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 1; j < len + 1; j++)
        {
            if (j > len - i - 1)
                printf("#");
            else
                printf(" ");
        }
        printf("  ");
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
