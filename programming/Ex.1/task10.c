#include <stdio.h>
#include <math.h>
#include <float.h>

int random()
{
    srand(time(NULL));

    int n =5;
    int i;

    for(i=0; i<n; i++){
    printf("%d\n", rand() % 5);
}
    return(0);
}

