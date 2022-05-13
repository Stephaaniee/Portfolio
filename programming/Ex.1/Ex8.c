#include <stdio.h>

int main()
{
    double quantity = rand() %10;
    do 
    {
        printf("Enter value\t");
        scanf("%lf", &quantity);
        printf("Wrong value\n");
    }
    while (quantity < 1 || quantity > 100);

     do
    {
        printf("Enter value\t");
        scanf("%lf", &quantity);
        printf("correct price %.2f\n", quantity);
    }
    while (quantity >1 || quantity <= 10);

    return 0;
}