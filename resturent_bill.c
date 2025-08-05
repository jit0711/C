#include <stdio.h>

int main()
{
    int codes[] = {01, 02, 03, 04, 05}; // Menu Items
    char items[][30] = {"Biriyani", "Chicken Kosa", "Pizza", "Roll", "Cold drink"};
    float prices[] = {190.0, 150.0, 225.0, 70.0, 50.0};
    int orderCodes[50], quantity[50];
    float total = 0, gst, grandTotal;
    int n, i, j;

    
    printf("======= WELCOME TO DADA BOUDI =======\n"); // Display Menu Card
    printf("--------------- MENU ------------------\n");
    printf("%-10s %-20s %-10s\n", "Code", "Item", "Price (RS)");
    for (i = 0; i < 5; i++)
    {
        printf("%-10d %-20s %-9.2f\n", codes[i], items[i], prices[i]);
    }
    printf("---------------------------------------\n");


    printf("How many items do you want to order? "); // Take order
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter item code for item %d: ", i + 1);
        scanf("%d", &orderCodes[i]);
        printf("Enter quantity: ");
        scanf("%d", &quantity[i]);
    }


    printf("\n============== BILL ==============\n"); // Print Bill
    printf("%-20s %-10s %-12s %-10s\n", "Item", "Qty", "Price", "Total");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (orderCodes[i] == codes[j])
            {
                float itemTotal = prices[j] * quantity[i];
                total += itemTotal;
                printf("%-20s %-10d RS:%-9.2f RS:%-9.2f\n", items[j], quantity[i], prices[j], itemTotal);
                break;
            }
        }
    }

    gst = total * 0.05;
    grandTotal = total + gst;

    printf("\nSubtotal      : RS:%.2f", total);
    printf("\nGST (5%%)      : RS:%.2f", gst);
    printf("\nGrand Total   : RS:%.2f", grandTotal);
    printf("\n==================================\n");
    printf("Thank you! Visit again.\n");

    return 0;
}
