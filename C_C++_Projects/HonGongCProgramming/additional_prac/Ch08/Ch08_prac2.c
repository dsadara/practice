#include <stdio.h>

int main(void)
{
    int i, ary[10] = {1, 2};
    for(i = 0  ; i < 8 ; i++)
    {
        ary[i+2] = ary[i] + ary[i+1];
    }
    for(i = 0 ; i < 10 ; i++)
    {
        printf("%d  ", ary[i]);
    }
    return 0;
}