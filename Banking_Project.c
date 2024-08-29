#include <stdio.h>
#include <math.h>

int main(){
    int pin;
    int attempts;
    int balance;
    double deposit;
    double withdrawal;
    int userNumber;


    printf("Welcome to the RUFARO BANK!\n");
    printf("Please enter your user number");
    scanf("%d", &userNumber);
    userNumber = userNumber;
    if(userNumber != userNumber){
        printf("Unfamilar with that user number. Try Again");
        return 1; /* terminates the program if the cpu is unfamilair with the user number*/
    }

    printf("PLEASE ENTER PIN TO ACCESS ACCOUNT\n");
    scanf("%d", &pin);
    attempts++;

    while(pin != 8888 && attempts < 3){
        printf("ENTER PIN\n");
        scanf("%d", &pin);
        attempts++;
    }
    if(pin == 0000){
        printf("Access Granted\n");
        printf("Welcome to your account");
    }
    printf("Select:\n");
    printf("Balance\n");
    printf("Deposit\n");
    printf("Withdrawal\n");
    printf("Exit");
    scanf("%c", balance, deposit, withdrawal);
    
    return 0;
}