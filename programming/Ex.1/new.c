#include <stdio.h>
#include <math.h>

int main()
{
    char operator[3];
    operator[1] = '+';
    operator[2] = '-';
    operator[3] = '/';

    double  x,y;
    printf("Enter x value\t");
    scanf("%lf", &x);
    printf("Enter y value\t");
    scanf("%lf", &y);
    printf("\n Enter an operator: \t");
    scanf("%s", &operator);
    
    if(operator[1])
    {
        printf("%f", x+y);
    }
    else if(operator[2])
    {
        printf("%f", x-y);
    }
    else if(operator[3])
    {
        printf("%f", x/y);
    }
    else 
    {
        printf("%f", x*y);
    }
}