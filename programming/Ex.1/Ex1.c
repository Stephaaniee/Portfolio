#include <stdio.h>

int main()
{
    int x = 1234;
    int TH = x /1000;
    int H = x/ 100%10;
    int T = x /10%10;
    int U = x %10;

    printf("%d \n", TH);
    printf("%d \n", H);
    printf("%d \n", T);
    printf("%d \n", U);
    printf("%d\n", 1+2+3+4);
}