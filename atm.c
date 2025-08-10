#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void CheckBal(int Bal)
{
    printf("\nYour current Balance is: %d ", Bal);
}

int Withdraw(int bal)
{
    int withd;
    printf("\nEnter amount to Withdraw(multiple of 100): ");
    scanf("%d", &withd);
    if (withd <=0)

    {
        printf("\nWrong amount");
        return bal;
    }
    else if (withd % 100 != 0)
    {
        printf("\nEnter amount in multiplication of 100");
        return bal;
    }
    else if (bal < withd)
    {
        printf("\nInsufficient Balance");
        return bal;
    }

    else
    {
        return (bal - withd);
    }
}

int Deposit(int bal)
{
    int dep;
    printf("\nEnter amount to Deposit: ");
    scanf("%d", &dep);
    if (dep <= 0)
    {
        printf("\nWrong amount");
        return bal;
    }
    else
    {
        return bal + dep;
    }
}

int PinChange(int pin)
{
    int pinc;
    printf("\nEnter your old pin: ");
    scanf("%d", &pinc);
    if (pinc == pin)
    {
        int newpin, newpinx;
        printf("\nEnter new 4 digits pin: ");
        scanf("%d", &newpin);
        printf("\nConfirm new pin: ");
        scanf("%d", &newpinx);
        if (newpin == newpinx && newpin >= 1000 && newpin <= 9999)
        {
            printf("\n----Pin changed successfully----");
            return newpin;
        }
        else
        {
            printf("\nNot matched");
            return pin;
        }
    }
    else
    {
        printf("\nNot matched");
        return pin;
    }
}

void SetPin()
{
    printf("\nThis feature is not available at this moment.\nContact your home branch..");
}

void PrintReceipt(char type[], int amount, int balance)
{
    time_t t;
    time(&t);
    printf("\n\n=========== TRANSACTION RECEIPT ===========\n");
    printf("Transaction   : %s\n", type);
    if(amount!=-1)
    {
    printf("Amount        : %d\n", amount);
    printf("Remaining Bal : %d\n", balance);
    }
    printf("Date & Time   : %s", ctime(&t));

    printf("===========================================\n");
}


int main()
{
    printf("===============WELCOME===============\n");
    int Bal = 10000, pin = 9921, pinx, choice, attemp = 0;
    while (attemp < 3)
    {
        printf("Enter your 4 digit pin Pin:\n");
        scanf("%d", &pinx);
        if (pinx < 1000 || pinx > 9999 || pinx != pin)
        {
            printf("!!!!Wrong/Invalid pin entered!!!!!\n Access Denied");
            printf("\n\tPlease Try again...");
            attemp++;
            printf("\nAttempt remain: %d", 3 - attemp);
            if (attemp == 3)
            {
                printf("\nAttempt Exceed!! Your card has been blocked.Contact your branch");

                printf("\n===========================\n");
                exit(0);
            }
        }
        else
        {
            printf("\n----Pin is verified successfully----");
            break;
        }
    }
    while (1)
    {
        printf("\n\n1.Check Balance");
        printf("\n2.Withdraw Cash");
        printf("\n3.Deposit Cash");
        printf("\n4.Change Green Pin");
        printf("\n5.Generate Green Pin");
        printf("\n6.Exit");
        printf("\nEnter your choice...\n");
        scanf("%d", &choice);
        switch (choice)
        {
            int oldbal;
        case 1:

            CheckBal(Bal);
            printf("\n----Successful----");
            break;
        case 2:
            oldbal=Bal;
            Bal = Withdraw(Bal);
            if(oldbal!=Bal)
            {
            PrintReceipt("Withdraw",oldbal-Bal,Bal);
            }
            break;
        case 3:
             oldbal=Bal;
            Bal = Deposit(Bal);
            if(oldbal!=Bal)
            {
            PrintReceipt("Deposit",Bal-oldbal,Bal);
            }            
            break;
        case 4:
            int oldpin=pin;
            pin = PinChange(pin);
            if(pin!=oldpin)
            {
             PrintReceipt("Pin changed",-1,Bal);

            }
            break;
        case 5:
            SetPin();
            break;
        case 6:
            printf("\n===============THANK YOU===============");
            exit(0);
        default:
            printf("\n!!!!Invalid choice!!!!\n");
            break;
        }
    }
    printf("\n===============THANK YOU===============");
    return 0;
}
