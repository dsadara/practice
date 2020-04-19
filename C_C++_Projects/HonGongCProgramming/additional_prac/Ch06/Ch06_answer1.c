#include <stdio.h>

int main(void)
{
    int i;
    
    for(i = 1; i <= 15 ; i++)
    {
        printf("*");
        if(i % 5 == 0)
        {
            printf("\n");
        }
    }
    
    return 0;
}