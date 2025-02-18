#include <cs50.h>
#include <stdio.h>

bool IsCardValid(long cardNumber);
int GetDigitCount(long number);
string GetCardType(long cardNumber);

int main(void)
{
    long cardNumber;

    // Prompt user for credit card number
    do
    {
        cardNumber = get_long("Number: ");
    }
    while (cardNumber < 1);

    // Check validity and print the card type
    if (IsCardValid(cardNumber))
    {
        printf("%s\n", GetCardType(cardNumber));
    }
    else
    {
        printf("INVALID\n");
    }
}

// Function to check if the card number is valid using Luhn's Algorithm
bool IsCardValid(long cardNumber)
{
    int sum = 0;
    bool alternate = false;

    long tempNumber = cardNumber;
    while (tempNumber > 0)
    {
        int digit = tempNumber % 10;

        if (alternate)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit = (digit % 10) + (digit / 10);
            }
        }

        sum += digit;
        alternate = !alternate;
        tempNumber /= 10;
    }

    return (sum % 10 == 0);
}

// Function to count the number of digits in a number
int GetDigitCount(long number)
{
    int count = 0;
    while (number > 0)
    {
        number /= 10;
        count++;
    }
    return count;
}

// Function to determine the card type based on its starting digits and length
string GetCardType(long cardNumber)
{
    int length = GetDigitCount(cardNumber);
    long tempNumber = cardNumber;

    while (tempNumber >= 10)
    {
        tempNumber /= 10;
    }

    if ((cardNumber >= 340000000000000 && cardNumber < 350000000000000) ||
        (cardNumber >= 370000000000000 && cardNumber < 380000000000000))
    {
        if (length == 15)
        {
            return "AMEX";
        }
    }
    else if (cardNumber >= 5100000000000000 && cardNumber < 5600000000000000 && length == 16)
    {
        return "MASTERCARD";
    }
    else if ((tempNumber == 4) && (length == 13 || length == 16))
    {
        return "VISA";
    }

    return "INVALID";
}
