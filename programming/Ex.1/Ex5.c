#include <stdio.h>
#include <math.h>


int main()
{
    //task 1
    double A;
    double B;
    printf("Enter value for A");
    scanf("%lf", &A);
    printf("Enter value for B");
    scanf("%lf", &B);

    printf("Area of rectangle = %.2f", A*B);
    printf("Perimeter of rectangle = %.2f", 2*(A+B));

    //Task2
    double r;
    double pi;
    printf("Enter value for A");
    scanf("%lf", &r);

    printf("Area of circle = %.2f", pi * r*r);
    printf("Perimeter of circle = %.2f", 2*pi * r);

    //Task3#
    int days;
    int month;
    double year;

    printf("Enter value of days");
    scanf("%lf", &days);
    printf("Enter value of month");
    scanf("%lf", &month);
    printf("Enter value of year");
    scanf("%lf", &year);
    printf("Day: %d", days);
    printf("month: %d", days/month);


}