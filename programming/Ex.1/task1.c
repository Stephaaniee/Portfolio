#include <stdio.h>


int main()
{/*
    //Task1: Create a program that prints a Diamond.

    printf("   *   \n");
    printf("  * *  \n");
    printf(" *   * \n");
    printf("*     *\n");
    printf(" *   * \n");
    printf("  * *  \n");
    printf("   *   \n");
    return 0;
    */
    {
      int PQRS=1;
      for (int i=0; i<=10; i++)
      {
            for (int j=10; j>i; j--)
            {
              printf(" ");
            }
            printf("*");
            if (i>0)
            {
                  for ( int k=1; k<=PQRS; k++)
                  {
                    printf(" ");
                  }
                  PQRS+=2;
                  printf("*");
            }
                  printf("\n");
      }
      PQRS-=4;
      for (int i=0; i<=10-1; i++)
      {
            for (int j=0; j<=i; j++)
            {
              printf(" ");
            }
            printf("*");
            for (int k=1; k<=PQRS; k++)
            {
              printf(" ");
            }
            PQRS-=2;
            if (i!=10-1)
            {
              printf("*");
            }
            printf("\n");
      }
    }
    return 0;
}