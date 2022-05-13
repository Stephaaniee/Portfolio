#include <stdio.h>
#include <math.h>
#include <float.h>
 
 int main()
 {
    //Task1. To calculate the distance between two points
     double x1, y1, x2, y2;
     double Formula;

    //Declare variables
     printf("Enter value of x1\t");
     scanf("%lf", &x1);
     printf("Enter value of x2\t");
     scanf("%lf", &x2);
     printf("Enter value of y1\t");
     scanf("%lf", &y1);
     printf("Enter value of y2\t");
     scanf("%lf", &y2);

    //Calculation
     Formula = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));

     printf("The distance between the two points = %.2f", Formula);


 }
