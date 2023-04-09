
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Ask for the name
    string name = get_string("What's your name? ");

    // Say hello to the user
    printf("Hello, %s!\n", name);
}