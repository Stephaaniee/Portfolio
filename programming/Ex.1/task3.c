#include <stdio.h>

int main()
{
    long int number;
    printf("Enter non-negative number\n");
    scanf("%d", &number); 
    if(!( number >= 0))
    printf("ERROR!!\n");
    else
    printf("%x\n", number);/*printing in hexadecimal*/
    printf("%o\n", number);/*printing in octal*/
    printf("%u\n", number);/*unsigned numbers*/
    
}