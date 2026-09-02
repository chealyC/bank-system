#include <stdio.h>
#include "bank.h"

int main(void)
{
    int input = -1;
    int loggedIn = 0;
    int accountCreated = 0;

    struct Account account = {0};

    printf("Welcome to Christian's Bank Management System!\n");

    while (input != 5)
    {
        if (!loggedIn)
        {
            printf("\n0. Create an Account\n");
            printf("1. Login\n");
            printf("5. Exit\n");

            scanf("%d", &input);

            switch (input)
            {
                case 0:
                    if (!accountCreated)
                    {
                        createAccount(&account);
                        accountCreated = 1;
                    }
                    else
                    {
                        printf("An account already exists.\n");
                    }
                    break;

                case 1:
                    if (accountCreated)
                    {
                        loggedIn = loginAccount(&account);
                    }
                    else
                    {
                        printf("Please create an account first.\n");
                    }
                    break;

                case 5:
                    return 0;

                default:
                    printf("Invalid option.\n");
            }
        }
        else
        {
            printf("\n1. Deposit Funds\n");
            printf("2. Withdraw Funds\n");
            printf("3. Check Balance\n");
            printf("4. Logout\n");
            printf("5. Exit\n");

            scanf("%d", &input);

            switch (input)
            {
                case 1:
                    depositFunds(&account);
                    break;

                case 2:
                    withdrawFunds(&account);
                    break;

                case 3:
                    checkBalance(&account);
                    break;

                case 4:
                    loggedIn = 0;
                    printf("Logged out.\n");
                    break;

                case 5:
                    return 0;

                default:
                    printf("Invalid option.\n");
            }
        }
    }

    return 0;
}