#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 100

typedef struct {
    int account_number;
    char account_holder[50];
    float balance;
    float transactions[MAX_TRANSACTIONS];
    int transaction_count;
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

// Function declarations
void create_account();
void delete_account();
void deposit();
void withdraw();
void show_transactions();
void display_menu();
Account* find_account(int account_number);

int main() {
    int choice;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                delete_account();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                show_transactions();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    return 0;
}

void display_menu() {
    printf("\nBanking System Menu:\n");
    printf("1. Create Account\n");
    printf("2. Delete Account\n");
    printf("3. Deposit\n");
    printf("4. Withdraw\n");
    printf("5. Show Transactions\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

void create_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts, limit reached.\n");
        return;
    }
    Account new_account;
    printf("Enter account number: ");
    scanf("%d", &new_account.account_number);
    printf("Enter account holder name: ");
    scanf("%s", new_account.account_holder);
    new_account.balance = 0.0;
    new_account.transaction_count = 0;
    accounts[account_count++] = new_account;
    printf("Account created successfully.\n");
}

void delete_account() {
    int account_number;
    printf("Enter account number to delete: ");
    scanf("%d", &account_number);
    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == account_number) {
            for (int j = i; j < account_count - 1; j++) {
                accounts[j] = accounts[j + 1];
            }
            account_count--;
            printf("Account deleted successfully.\n");
            return;
        }
    }
    printf("Account not found.\n");
}

void deposit() {
    int account_number;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    Account* account = find_account(account_number);
    if (account != NULL) {
        printf("Enter amount to deposit: ");
        scanf("%f", &amount);
        account->balance += amount;
        account->transactions[account->transaction_count++] = amount;
        printf("Deposit successful. New balance: $%.2f\n", account->balance);
    } else {
        printf("Account not found.\n");
    }
}

void withdraw() {
    int account_number;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    Account* account = find_account(account_number);
    if (account != NULL) {
        printf("Enter amount to withdraw: ");
        scanf("%f", &amount);
        if (amount > account->balance) {
            printf("Insufficient balance.\n");
        } else {
            account->balance -= amount;
            account->transactions[account->transaction_count++] = -amount;
            printf("Withdrawal successful. New balance: $%.2f\n", account->balance);
        }
    } else {
        printf("Account not found.\n");
    }
}

void show_transactions() {
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    Account* account = find_account(account_number);
    if (account != NULL) {
        printf("Transaction history for account %d:\n", account_number);
        for (int i = 0; i < account->transaction_count; i++) {
            printf("%.2f\n", account->transactions[i]);
        }
    } else {
        printf("Account not found.\n");
    }
}

Account* find_account(int account_number) {
    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == account_number) {
            return &accounts[i];
        }
    }
    return NULL;
}
