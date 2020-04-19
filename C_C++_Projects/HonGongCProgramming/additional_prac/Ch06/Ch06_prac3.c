#include <stdio.h>

int main(void)
{
    int sum = 0, num= 0;
    do
    {
        sum += num;
        printf("양수입력 : ");
        scanf("%d", &num);
    } while(num > 0);
 /*   while(1)
    {
        printf("양수입력 : ");
        scanf("%d", &num);
        if( num <= 0)
            break;
        sum += num;
    } */
    printf("누적된 값 : %d", sum);
    return 0;
}