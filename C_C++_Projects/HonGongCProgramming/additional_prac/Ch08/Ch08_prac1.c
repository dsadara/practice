#include <stdio.h>

int main(void)
{
    double ary[5] = {1.0, 2.1, 3.2, 4.3, 5.4};
    int i;
    for(i = 0 ; i < 5 ; i++)
        printf("%.1lf  ", ary[4-i]);
    return 0;
}