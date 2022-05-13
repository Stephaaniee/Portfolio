#include <stdio.h>

int main()
{
    /* Declaration of variables*/
    float quantityA, quantityB;
    float priceA, priceB;
    float total;
    float average;
    float diff;

    /*First item*/
    printf("Enter first Item\t");
    scanf("%f", &quantityA);
    printf("Enter price\t");
    scanf("%f", &priceA);
    
    /*Second Item*/
    printf("Enter second Item\t");
    scanf("%f", &quantityB);
    printf("Enter price\t");
    scanf("%f", &priceB);

    /*calculations*/

    total = quantityA * priceA + quantityB * priceB;
    average = total/2;
    diff = quantityB * priceB - quantityA * priceA;

    /*result*/
    printf("Total: %.2f\n", total);
    printf("Average: %.2f\n", average);
    printf("Difference: %.2f\n", diff);
    
    return 0;
}