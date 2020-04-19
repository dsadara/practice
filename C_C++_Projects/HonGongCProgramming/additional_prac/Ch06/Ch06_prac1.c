#include <stdio.h>

int main(void)
{
    int count = 0, i;
    for(i = 0; i < 15 ; i++)
    {
        printf("*");
        count++;
        if((count % 5) == 0)
            printf("\n");
    }
    return 0;
}