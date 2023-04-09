#include <stdio.h>
#include <cs50.h>
int main (void)
{
    long x = get_long ("x: ");
    long y = get_long ("y: ");
    printf("%li\n" , x+y );
    int points = get_int("how many points did you lose? ");
    const int MINE=x+y;
    if (points>MINE)
    {
        printf("you lost more points than me.\n");
    }
    else if (points<MINE)
    {
        printf("you lost less points than me.\n");
    }
    else
    {
        printf("you lost the same points as me !\n");
    }
}