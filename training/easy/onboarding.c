#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * The code below will read all the game information for you.
 * On each game turn, information will be available on the standard input, you will be sent:
 * -> the total number of visible enemies
 * -> for each enemy, its name and distance from you
 * The system will wait for you to write an enemy name on the standard output.
 * Once you have designated a target:
 * -> the cannon will shoot
 * -> the enemies will move
 * -> new info will be available for you to read on the standard input.
 **/
int main()
{
    char enemy[50]; // The name of this enem
    char enemyCible[50];
   
    int tour = 0;
    // game loop
    while (1) {
        int count; // The number of current enemy ships within range
        int distCloseTarget = 1000;
        scanf("%d", &count); fgetc(stdin);
        for (int i = 0; i < count; i++) {
            int dist; // The distance to your cannon of this enemy
            scanf("%s%d", &enemy, &dist); fgetc(stdin);
            if(dist < distCloseTarget)
            {
                distCloseTarget = dist;
                memcpy(enemyCible, enemy, 50);
            }
        }

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
        printf("%s\n", enemyCible); // The name of the most threatening enemy (HotDroid is just one example)
        fprintf(stderr, "tour : %i\n", tour);
        fprintf(stderr, "dist : %i\n", distCloseTarget);
        tour ++;
    }
}
