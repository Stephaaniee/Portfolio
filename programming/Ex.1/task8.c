#include <stdio.h>
#include <math.h>
#include <float.h>

int main()
{
    int month;
    printf("Select an integer between between 1 and 12:  ");
    scanf("%d", &month);

        if (month == 1)
        printf("January");
        else if (month == 2)
        printf("February");
        else if  (month == 3)
        printf("March");
        else if (month == 4)
        printf("April");
        else if (month == 5)
        printf("May");
        else if (month == 6)
        printf("June");
        else if (month == 7)
        printf("July");
        else if (month == 8)
        printf("August");
        else if (month == 9)
        printf("September");
        else if (month == 10)
        printf("October");
        else if (month == 11)
        printf("November");
        else if (month == 12)
        printf("December");
       
        else 
        printf("ERROR!!! Between 1 and 12\t");   //I am not able to repeat the procedure when this happens


    
    /*  
    switch (month)
    {
        case 1: printf("January\n");
        break;
        case 2: printf("February\n");
        break;
        case 3: printf("March\n");
        break;
        case 4: printf("April\n");
        break;
        case 5: printf("May\n");
        break;
        case 6: printf("June\n");
        break;
        case 7: printf("July\n");
        break;
        case 8: printf("August\n");
        break;
        case 9: printf("September\n");
        break;
        case 10: printf("October\n");
        break;
        case 11: printf("November\n");
        break;
        case 12: printf("December\n");
        break;
        default: printf("ERROR...");
        break;
        
    }
    */
}


