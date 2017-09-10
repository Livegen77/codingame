#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void asciitobinary(char character, char *pBinaryResult)
{
    int powerValue = 64;
    int index = 6;
    
    pBinaryResult[7] = '\0';
    
    fprintf(stderr, "%c (%d) : ", character, character);
    
    for(index = 0; index < 7; index++)
    {
        if(character >= powerValue)
        {
            character -= powerValue;
            pBinaryResult[index] = '1';
        }
        else
            pBinaryResult[index] = '0';
            
        fprintf(stderr, "%c", pBinaryResult[index]);
        powerValue = powerValue >> 1;
    }
     
    fprintf(stderr, "\n");   
}

void binarytochuck(char *pTotalBinary, char *pBinarychuck)
{
    int TotalBinaryIndex =   0;
    int ChuckIndex       =   0;
    char previousBinary  = '\0';
    
    fprintf(stderr, "Message en binaire : %s\n", pTotalBinary);
    
    while(pTotalBinary[TotalBinaryIndex] != '\0')
    {
        fprintf(stderr, "binaire %d : %c\n", TotalBinaryIndex, pTotalBinary[TotalBinaryIndex]);
        if(pTotalBinary[TotalBinaryIndex] == previousBinary)
        {
            fprintf(stderr, "ancien binaire\n");
            //Just add the zero
            fprintf(stderr, "DEBUTZ \n");
            pBinarychuck[ChuckIndex] = '0';
            fprintf(stderr, "%c", pBinarychuck[ChuckIndex]);
            ChuckIndex++;
            fprintf(stderr, "FINZ \n");
        }
        else
        {
            fprintf(stderr, "nouveau binaire\n");
            if(pTotalBinary[TotalBinaryIndex] == '1')
            {
                if(previousBinary != '\0')
                {
                    pBinarychuck[ChuckIndex] = ' ';
                    fprintf(stderr, "%c", pBinarychuck[ChuckIndex]);
                    ChuckIndex++;
                }
                fprintf(stderr, "DEBUTY \n");
                pBinarychuck[ChuckIndex] = '0';
                fprintf(stderr, "%c", pBinarychuck[ChuckIndex]);
                ChuckIndex++;
                pBinarychuck[ChuckIndex] = ' ';
                fprintf(stderr, "%c", pBinarychuck[ChuckIndex]);
                ChuckIndex++;
                pBinarychuck[ChuckIndex] = '0';
                fprintf(stderr, "%c", pBinarychuck[ChuckIndex]);
                ChuckIndex++;
                fprintf(stderr, "FINY \n");
            }
            else if(pTotalBinary[TotalBinaryIndex] == '0')
            {
                fprintf(stderr, "DEBUTX \n");
                if(previousBinary != '\0')
                {
                    pBinarychuck[ChuckIndex] = ' ';
                    fprintf(stderr, "%c", pBinarychuck[ChuckIndex]);
                    ChuckIndex++;
                }
                pBinarychuck[ChuckIndex] = '0';
                fprintf(stderr, "%c", pBinarychuck[ChuckIndex]);
                ChuckIndex++;
                pBinarychuck[ChuckIndex] = '0';
                fprintf(stderr, "%c", pBinarychuck[ChuckIndex]);
                ChuckIndex++;
                pBinarychuck[ChuckIndex] = ' ';
                fprintf(stderr, "%c", pBinarychuck[ChuckIndex]);
                ChuckIndex++;
                pBinarychuck[ChuckIndex] = '0';
                fprintf(stderr, "%c", pBinarychuck[ChuckIndex]);
                ChuckIndex++;
                fprintf(stderr, "FINX\n");
            }
            previousBinary = pTotalBinary[TotalBinaryIndex];
        }
        TotalBinaryIndex++;
    }
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int letter = 0;
    char MESSAGE[100];
    gets(MESSAGE);
    char CHARINBINARY[8];
    char *TOTALBINARY = NULL;
    char *BINCHUCK    = NULL;
    
    int LengthMessage = strlen(MESSAGE);
    fprintf(stderr, "Longueur Message : %d\n", LengthMessage);
    
    TOTALBINARY = (char*)malloc((7*LengthMessage)+1);
    BINCHUCK    = (char*)malloc((7*LengthMessage)+1);
    
    memcpy(TOTALBINARY, "\0", 7*LengthMessage);
    memcpy(BINCHUCK,    "\0", 7*LengthMessage);
    
    for( letter = 0; letter < LengthMessage; letter++)
    {
        asciitobinary(MESSAGE[letter], CHARINBINARY);
        memcpy(&TOTALBINARY[letter*7], CHARINBINARY, 7);
    }
    
    TOTALBINARY[7*LengthMessage] = '\0';
    
    
    fprintf(stderr, "Message en binaire : %s\n", TOTALBINARY);
    
    binarytochuck(TOTALBINARY, BINCHUCK);
    
    printf("%s\n", BINCHUCK);
    
    free(TOTALBINARY);
    free(BINCHUCK);
    
    // Write an action using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");
}
