#ifndef BANK_H
#define BANK_H

struct Account
{
    char username[20];
    char password[20];
    double balance;
};

void createAccount(struct Account *account);
int loginAccount(struct Account *account);
void depositFunds(struct Account *account);
void withdrawFunds(struct Account *account);
void checkBalance(struct Account *account);

#endif