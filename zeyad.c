#include <stdio.h>
#include <cs50.h>

void sort(int numbers[], int size);

void sort(int numbers[], int size);

int main(void)
{

    // int n;
    // do {
    //     n = get_int("how many numbers? ");
    // }
    // while (n<2);

    // int numbers[n];

    // for (int i=0 ; i<n ; i++)
    // {
    //     numbers[i]= get_int("");
    // }

    // int big=0;
    // for (int i=0 ;i<n ; i++)
    // {
    //     if (big < numbers[i])
    //     {
    //         big = numbers[i];
    //     }
    // }
    // printf("biggest numbers is: %i \n" , big);

    int numbers[] = {2, 4, 6, 9, 3, 5, 1, 8, 7};

    int numbers[] = {2, 4, 6, 9, 3, 5, 1, 8, 7};

    int numbers3[18];

    

    int size1 = sizeof(numbers1);
    int size2 = sizeof(numbers2);
    int size3



    sort(numbers, size);
}

void sort(int numbers[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; i++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                int tmp = numbers[j];
                numbers[j] = numbers[j - 1];
                numbers[j - 1] = tmp;
            }
        }
    }



}
