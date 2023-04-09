#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


 int main(int argc, string argv[])

{
    if(argc != 2)

    {
        printf("usage: ./caesar key \n");

        return 1;
    }


    for ( int i= 0 ; i < strlen(argv[1]) ; i++  )
    {

        if (! isdigit (argv[1][i] ) )
        {
           printf("usage: ./caesar key \n");

           return 1;
        }

    }

     int k = atoi( argv[1] );

     string plaintext =get_string("text:  ") ;

    printf("ciphertext:");


    for (int j=0 ; j < strlen(plaintext) ; j++ )

    {
        if(isupper(plaintext[j]))
        {

          printf("%c" ,  (plaintext[j]-65 +k )%26 +65 );

        }


        else if(islower(plaintext[j]))

        {

         printf("%c" ,  (plaintext[j]-97 +k )%26 +97 );

        }

      else
      {

                 printf("%c" ,   plaintext[j]  );


      }



    }

     printf("\n ");


}








// get key code in one command line (./caesar key)
//make sure the key isdigit and if(argc===2)  else return 1 (exit program) with for loop
// Convert argv[1] from a `string` to an `int`
//get plain text from the user
//make sure every c in the plaintext is an alpha by for loop .. for (int i=0 ; i<strlen(plaintext) ; i++) with if plain text isalpha
