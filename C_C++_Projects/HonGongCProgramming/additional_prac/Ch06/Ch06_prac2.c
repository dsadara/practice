#include <stdio.h>

int main(void)
{
    int sum = 0, i;
    for(i = 1 ; i < 101 ; i++)
        sum = sum + i;
    printf("%d", sum);
    return 0;
}