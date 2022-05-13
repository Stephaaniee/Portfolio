#include <stdio.h>

    /*Task 1
    A while loop executes the operation only when the condition is true.
    A do while loop is an example of an exit condition loop that evaluates the condition after it has been executed.

    Task2
    An if Statement helps to execute an operation for a true or false condition. It can evaluate all kinds of data.
    An else if statement executes an operation for a false codition of an if statement when there are multiple conditions.
    An else statement executes an operation for a false condition of an if statement for the last condition.
    A switch statement if a faster means of executing an operation for an if statement especially whe theres a long list. It executes this for intergers and characters.*/

    /*Task 3*/

    int main (double x, double y, char operator)
    {
        printf("Enter value of x\t");
        scanf("%lf", &x);
        printf("Enter value of y\t");
        scanf("%lf", &y);        
        printf("Enter value of operator\t");
        scanf("%s", &operator);

        if (operator == '+')
        {
            printf("%f", x+y);
        }
        else if (operator == '-')
        {
            printf("%f", x-y);
        }
        else if (operator == '*')
        {
             printf("%f", x*y);
        }
        else
        {
             printf("%f", x/y);
        }

/*Task4*/
        int month;
        printf("Enter value\t");
        scanf("%d", &month);

    switch(month)
    {
        case 1: 
        case 2: 
        case 12: 
            printf("winter");
            break;
        case 3: 
        case 4: 
        case 5: 
            printf("spring");
            break;
        case 9: 
        case 10: 
        case 11: 
            printf("autumn");
            break;
        default :
            printf("unknown month");
    }
    return 0;
}
