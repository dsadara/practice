#include <stdio.h>

int main(void)
{
    int i, j, num;
    
    for(i = 0; i<5 ; i++)
    {
        for(j = 0 ; j < 4 - i ; j++)
        {
            printf(" ");
        }
        num = 1;
        for(j = 0 ; j < (2*i) + 1 ; j++)
        {
            printf("%d", num);
            num++;
        }
        printf("\n");
    }
    return 0;
}