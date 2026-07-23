#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int player1Score = 0;
    int player2Score = 0;
    int dice;
    char roll;

    srand(time(NULL));

    printf("=========================================\n");
    printf("      TWO PLAYER DICE ROLLING GAME\n");
    printf("=========================================\n\n");

    /* ---------- Player 1 ---------- */
    printf("Player 1's Turn\n");

    while (1)
    {
        printf("Press Enter to roll the dice...");
        scanf("%c", &roll);

        dice = rand() % 6 + 1;

        printf("Player 1 rolled: %d\n", dice);

        if (dice == 1)
        {
            printf("Player 1 rolled 1. Turn Over!\n");
            break;
        }

        player1Score = player1Score + dice;

        printf("Current Score = %d\n\n", player1Score);
    }

    printf("\nPlayer 1 Total Score = %d\n\n", player1Score);

    /* ---------- Player 2 ---------- */
    printf("Player 2's Turn\n");

    while (1)
    {
        printf("Press Enter to roll the dice...");
        scanf("%c", &roll);

        dice = rand() % 6 + 1;

        printf("Player 2 rolled: %d\n", dice);

        if (dice == 1)
        {
            printf("Player 2 rolled 1. Turn Over!\n");
            break;
        }

        player2Score = player2Score + dice;

        printf("Current Score = %d\n\n", player2Score);
    }

    printf("\n=========================================\n");
    printf("           FINAL RESULT\n");
    printf("=========================================\n");

    printf("Player 1 Total Score = %d\n", player1Score);
    printf("Player 2 Total Score = %d\n\n", player2Score);

    if (player1Score > player2Score)
    {
        printf("Winner: Player 1\n");
    }
    else if (player2Score > player1Score)
    {
        printf("Winner: Player 2\n");
    }
    else
    {
        printf("The Match is a Draw!\n");
    }

    return 0;
}
