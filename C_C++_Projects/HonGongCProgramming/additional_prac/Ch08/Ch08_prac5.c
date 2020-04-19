#include <stdio.h>

int main(void)
{
    int a[5], i, max, min, b[3], j = 0;
    printf("5명 심사위원의 점수 입력 : ");
    for(i = 0 ; i < 5 ; i++)
    {
        scanf("%d", a + i);
    }
    max = a[0];
    for(i = 0 ; i < 4 ; i++)
    {
        if(max < a[i+1])
            max = a[i+1];
    }
    min = a[0];
    for(i = 0 ; i < 4 ; i++)
    {
        if(min > a[i+1])
            min = a[i+1];
    }
    for(i = 0 ; i < 5 ; i++)
    {
        if( (a[i] == max) || (a[i] == min) )
            continue;
        b[j] = a[i];
        j++;
    }
    printf("유효점수 :");
    for(i = 0 ; i < 3 ; i++)
    {
        printf("  %d", b[i]);
    }
    printf("\n");
    printf("평균 : %.1lf", (double)(b[0] + b[1] + b[2]) / 3.0);
    return 0;
}