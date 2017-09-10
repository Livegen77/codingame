#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
typedef enum
{
    UP=0,
    DOWN=1,
    VOK = 2
}tVertical;

typedef enum
{
    RIGHT = 0,
    LEFT  = 1,
    HOK = 2
}tHorizontal;

int main()
{
    int LX; // the X position of the light of power
    int LY; // the Y position of the light of power
    int TX; // Thor's starting X position
    int TY; // Thor's starting Y position
    scanf("%d%d%d%d", &LX, &LY, &TX, &TY); fgetc(stdin);
    fprintf(stderr, "Position de l'éclair X : %d, Y : %d\n", LX, LY);
    fprintf(stderr, "Position de Thor X : %d, Y : %d\n", TX, TY);

    // game loop
    while (1) {
        tVertical verticalDirection;
        tHorizontal horizontalDirect;
        int E; // The level of Thor's remaining energy, representing the number of moves he can still make.
        scanf("%d", &E); fgetc(stdin);
        fprintf(stderr, "Mouvement restant: %d\n", E);
        
        if((TX-LX) > 0)
        {
            horizontalDirect = LEFT;
            fprintf(stderr, "Has to go left\n");
            TX--;
        }
        else if((TX-LX) < 0)
        {
            horizontalDirect = RIGHT;
            fprintf(stderr, "Has to go RIGHT\n");
            TX++;
        }
        else
        { 
            horizontalDirect = HOK;
            fprintf(stderr, "X is OK \n");
        }
        
        if((TY-LY) > 0)
        {
            verticalDirection = UP;
            fprintf(stderr, "Has to go UP\n");
            TY--;
        }
        else if((TY-LY) < 0)
        {
            verticalDirection = DOWN;
            fprintf(stderr, "Has to go DOWN\n");
            TY++;
        }
        else
        { 
            verticalDirection = VOK;
            fprintf(stderr, "Y is OK \n");
        }
        
        if(horizontalDirect == LEFT && verticalDirection == UP)
            printf("NW\n");
        else if(horizontalDirect == LEFT && verticalDirection == DOWN)
            printf("SW\n");
        else if(horizontalDirect == LEFT && verticalDirection == VOK)
            printf("W\n");
        else if(horizontalDirect == RIGHT && verticalDirection == UP)
            printf("NE\n");
        else if(horizontalDirect == RIGHT && verticalDirection == DOWN)
            printf("SE\n");
        else if(horizontalDirect == RIGHT && verticalDirection == VOK)
            printf("E\n");
        else if(horizontalDirect == HOK && verticalDirection == UP)
            printf("N\n");
        else if(horizontalDirect == HOK && verticalDirection == DOWN)
            printf("S\n");
        else
            fprintf(stderr, "Debug messages...\n");

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");

        //printf("E\n"); // A single line providing the move to be made: N NE E SE S SW W or NW
    }
}
