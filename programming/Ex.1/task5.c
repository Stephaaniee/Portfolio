#include <stdio.h>

int main()
{
  /*Declaration of variables*/
    int a, b, x, y;
    a = 5;
    b = 1;
    x = 10;
    y = 5;

  /*a) Output*/
    printf("a) f = %d\n", (a-b)*(x-y));

  /*b) Prompt for variables*/
    printf("Enter a:\t");           
    scanf("%d", &a);                
    printf("Enter b:\t");
    scanf("%d", &b);
    printf("Enter x:\t");
    scanf("%d", &x);
    printf("Enter y:\t");
    scanf("%d", &y);
    
  /*Output*/
    printf("b) f = %d\n", (a-b)*(x-y));

  /*c) prompt a user for character name*/
    char c[10];

    printf("Enter Name: ");
    scanf("%s", &c);
    printf("c) Welcome %s\n ", c);
  
  /*d) Shop revenue program*/
    float quantity;
    float price;
    float revenue;

    printf("Enter quantity:\t");
    scanf("%f", &quantity);
    printf("Enter price:\t");
    scanf("%f", &price);
    revenue = price*quantity;

    printf("d) Total Revenue: %.2f\n", revenue);

/*e)Shop commission program*/
    float rate;
    float cost;
    char N[19];
    float SalesPrice;
    float commision;

    printf("Enter Name of gear\t");
    scanf("%s", &N);
    printf("Number of gears per person\t");
    scanf("%f", &rate);
    printf("Cost per gear\t");
    scanf("%f", &cost);
    printf("Sales Price per gear\t");
    scanf("%f", &SalesPrice);

/*calculations*/
    commision = rate * (SalesPrice - cost);

    printf("e) Commission = %.2f", commision);
    return 0;
}