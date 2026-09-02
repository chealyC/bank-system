#include <stdio.h>
#include <string.h>
#include "bank.h"

void createAccount(struct Account *account)
{
    int i;

    printf("Please enter a username: ");
    scanf("%19s", account->username);

    printf("Please enter a password: ");
    scanf("%19s", account->password);

    account->balance = 0.0;

    printf("Your username is %s\n", account->username);

    printf("Your password is ");

    for (i = 0; account->password[i] != '\0'; i++)
    {
        printf("*");
    }

    printf("\n");
}

int loginAccount(struct Account *account)
{
    char user[20];
    char pass[20];

    printf("Please enter your username: ");
    scanf("%19s", user);

    printf("Please enter your password: ");
    scanf("%19s", pass);

    if (strcmp(user, account->username) == 0 &&
        strcmp(pass, account->password) == 0)
    {
        printf("Login successful!\n");
        return 1;
    }

    printf("Incorrect username or password.\n");
    return 0;
}

void depositFunds(struct Account *account)
{
    int choice;

    printf("Please enter deposit amount:\n");
    printf("'0' for GBP 50\n");
    printf("'1' for GBP 20\n");
    printf("'2' for GBP 10\n");
    printf("'3' for GBP 5\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 0:
            account->balance += 50;
            break;

        case 1:
            account->balance += 20;
            break;

        case 2:
            account->balance += 10;
            break;

        case 3:
            account->balance += 5;
            break;

        default:
            printf("Invalid amount.\n");
            return;
    }

    printf("Deposit successful!\n");
    printf("New balance: GBP %.2f\n", account->balance);
}

void withdrawFunds(struct Account *account)
{
    int choice;

    printf("Please enter withdrawal amount:\n");
    printf("'0' for GBP 50\n");
    printf("'1' for GBP 20\n");
    printf("'2' for GBP 10\n");
    printf("'3' for GBP 5\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 0:
            if (account->balance >= 50)
            {
                account->balance -= 50;
                printf("GBP 50 withdrawn.\n");
            }
            else
            {
                printf("Insufficient funds.\n");
            }
            break;

        case 1:
            if (account->balance >= 20)
            {
                account->balance -= 20;
                printf("GBP 20 withdrawn.\n");
            }
            else
            {
                printf("Insufficient funds.\n");
            }
            break;

        case 2:
            if (account->balance >= 10)
            {
                account->balance -= 10;
                printf("GBP 10 withdrawn.\n");
            }
            else
            {
                printf("Insufficient funds.\n");
            }
            break;

        case 3:
            if (account->balance >= 5)
            {
                account->balance -= 5;
                printf("GBP 5 withdrawn.\n");
            }
            else
            {
                printf("Insufficient funds.\n");
            }
            break;

        default:
            printf("Invalid amount.\n");
            return;
    }

    printf("New balance: GBP %.2f\n", account->balance);
}

void checkBalance(struct Account *account)
{
    printf("Your balance is: GBP %.2f\n", account->balance);
}