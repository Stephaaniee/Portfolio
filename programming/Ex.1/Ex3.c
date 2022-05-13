#include <stdio.h>
#include <float.h>

int main()
{
    float height;
    float width;
    float perimeter;

    printf("Enter height of rectangle(cm)\n");
    scanf("%f", &height);
    printf("Enter width of rectangle(cm)\n");
    scanf("%f", &width);

    perimeter = 2*(height + width);
    printf("Perimeter = %.2f\n", perimeter);
    printf("Area %.2f", height*width);
    return 0;
}