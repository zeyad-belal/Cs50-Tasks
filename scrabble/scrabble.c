#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    if (score1 > score2) // check for the winner
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int score = 0;
    int alphabet[26];
    for (int i = 0 ; i < 26 ; i++) //create an array to store all uppercase letters "ABCD...Z"
    {
        alphabet[i] = (i + 65);
    }
    for (int i = 0 ; i < strlen(word) ; i++)
    {
        for (int j = 0 ; j < 26 ; j++)
        {
            if (alphabet[j] == word[i] || alphabet[j] == (word[i] - 32)) //cycles through to find a, b and so on
            {
                score += POINTS[j];
                break;
            }
        }
    }
    return score;
}