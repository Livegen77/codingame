#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N; // the number of points used to draw the surface of Mars.
    scanf("%d", &N); fgetc(stdin);
    for (int i = 0; i < N; i++) {
        int LAND_X; // X coordinate of a surface point. (0 to 6999)
        int LAND_Y; // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
        scanf("%d%d", &LAND_X, &LAND_Y); fgetc(stdin);
        fprintf(stderr, "Debug messages...\n");
    }
    int plop = 0;
    // game loop
    while (1) {
        int X;
        int Y;
        int HS; // the horizontal speed (in m/s), can be negative.
        int VS; // the vertical speed (in m/s), can be negative.
        int F; // the quantity of remaining fuel in liters.
        int R; // the rotation angle in degrees (-90 to 90).
        int P; // the thrust power (0 to 4).
        scanf("%d%d%d%d%d%d%d", &X, &Y, &HS, &VS, &F, &R, &P); fgetc(stdin);

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
        if(Y < 1000)
        {
            if(VS < 35)
                printf("0 4\n"); // R P. R is the desired rotation angle. P is the desired thrust power.
            else
                printf("0 3\n"); // R P. R is the desired rotation angle. P is the desired thrust power.
        }
        else
            printf("0 3\n"); // R P. R is the desired rotation angle. P is the desired thrust power.
    }
}
