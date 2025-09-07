
#include<stdio.h>
#include<stdlib.h>

#define PIN 1234

int balance =0, transaction =0;
int checkPIN();
void deposit();
void withdraw();
void checkBalance();
int checkPIN(){
    int pin,attemps=0;
    while(attemps<3){

        printf("Enter the pin: ");
        scanf("%d",&pin);
        if(pin==PIN){
            return 1;
}else{
            attemps++;
            printf("Wrong PIN! Attemps: %d\n:",3-attemps);
        }
}
        printf("Card Blocked!\n");
        exit(0);
    }
void deposit(){
    int amount;
    printf("Enter deposit amount: ");
    scanf("%d",&amount);
    if(amount<=0){
        printf("Invalid amount!\n:");
        return;
    }
    balance+=amount;
    transaction++;
    printf("Deposit successful! New Balance=%d\n",balance);
}
    void withdraw(){
        int amount;
        checkPIN();
        printf("Enter withdraw amount: ");
        scanf("%d",&amount);
        if(amount<=0){
            printf("Invalid amount!\n:");
            return;
        }
        if(balance<amount){
            printf("Insufficient funds!\n:");
            return;
        }
        balance-=amount;
        transaction++;
        printf("Withdraw successful! New Balance=%d\n",balance);
    }

    void checkBalance(){
        printf("Balance=%d | Transaction =%d\n ",balance,transaction);
        transaction++;
    }
    int main(){
        int choice;
        printf("\n---Welcome to SITEC Bank System---\n\n");

        checkPIN();
        while(1){
            if(transaction>0&&transaction%5==0){
                printf("\nRE-authentication required!\n ");
                checkPIN();
            }
            printf("\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit\nChoose: ");
            scanf("%d",&choice);
            switch(choice){
               case 1: deposit();
                    break;
                case 2:withdraw();
                    break;
                case 3:checkBalance();
                    break;
                case 4:
                    printf("\nThank you for using ATM project!\n");
                    exit(0);
                default:printf("Wrong choice!\n:");
            }
        }
    }