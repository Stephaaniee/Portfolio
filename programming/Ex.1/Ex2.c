#include <stdio.h>
 int main()
 {
    /* //task 1
    int quantity;
    double price;

    printf("Enter the number of item \n");
    scanf(" %d", &quantity); 
    
    printf("Enter the price of item \n");
    scanf("%lf", &price);

    printf("Quantity: %d\t", quantity);
    printf("Price: %.2f\t", price);
    printf("Total: %.2f\n", quantity * price);
    */

    //Task 2
    double quantityo, quantityt;
    double amounto, amountt; 
    double TD, TWD, discount = 0.2;
    

    
    //TW is total with discount and TWD is without discount

    printf("First Item \t");
    scanf(" %d", &quantityo);
    printf("First Item, price in euro \t");
    scanf(" %lf", &amounto);

    printf("Second Item \t");
    scanf(" %d", &quantityt);
    printf("second Item, price in euro \t");
    scanf(" %lf", &amountt);

    TWD = quantityo *amounto + quantityt * amountt;
    TD = TWD * (1-discount);
    printf("TWD %.2f euro\n", TWD);
    printf("TD %.2f euro\n", TD);
    
    return 0;
 }