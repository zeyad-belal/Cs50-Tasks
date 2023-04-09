#include <stdio.h>
#include <cs50.h>

int main (void)
{
   int n ;

    do
{
     n = get_int ("width: ");
}
    while (n < 1) ;



   for (int i=0 ; i < n ; i++)

 {
   for(int j=0 ; j <n ; j++)
   {
      printf("#");
   }
   printf("\n");
 }





for(int i=0 ; i<n ; i++)

  {

     for(int j=0 ; j<=i ; j++)

      {
        for(int k=0 ; k<=i ; k++)

        {
            printf(".");
        }

            printf("#");

      }

    printf("\n");
  }











}