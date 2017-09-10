// Read inputs from stdin. Write outputs to stdout.

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n); fgetc(stdin);
    int valeurZeroTop = 5526;
    int valeurZeroNegative = -273;
    int valeurlu;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &valeurlu);
        //printf("Test sur valeur %d : %d \n", i,valeurlu);
    
        if(valeurlu >= 0 && valeurlu < valeurZeroTop)
        {
            valeurZeroTop = valeurlu;
        }
        
        if(valeurlu < 0 && valeurlu > valeurZeroNegative)
        {
            valeurZeroNegative = valeurlu;
        }
    }
    
       //printf("valeur positive min : %d \n", valeurZeroTop);
   // printf("valeur negative max : %d \n", valeurZeroNegative);
    
    if(n == 0)
    {
        printf("0\n");
    }
    else if(n == 1)
    {
        printf("%d\n", valeurlu);
    }
    else
    {
        if(valeurZeroTop <= abs(valeurZeroNegative) )
        {
            printf("%d\n", valeurZeroTop);
        }
        else
        {
            printf("%d\n", valeurZeroNegative);
        }
    }
    

    
    return 0;
}
