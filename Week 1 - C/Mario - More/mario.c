#include <cs50.h>
#include <stdio.h>

void PrintRow(int rowN);
void PrintSpaces(int spaces);

int main(void)
{
    int n = 0;
    int spaces = 0;

    while (n <= 0 || n >= 9)
    {
        n = get_int("Height: ");
    }

    spaces = n;
    spaces--;

    for (int column = 0; column < n; column++)
    {
        PrintSpaces(spaces);
        PrintRow(column);
        spaces--;
        printf("  ");
        PrintRow(column);
        printf("\n");
    }
}

void PrintRow(int rowN)
{
    rowN++;

    for (int i = 0; i < rowN; i++)
    {
        printf("#");
    }
}

void PrintSpaces(int spaces) // cs50.ai gave me the idea but i've coded the function
{
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
}
