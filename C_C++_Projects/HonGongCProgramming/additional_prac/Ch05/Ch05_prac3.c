#include <stdio.h>

int main(void)
{
    int a, b, res = 1;
    printf("a와 b 입력 : ");
    scanf("%d%d", &a, &b);
    if(a >= 10)
        res = a;
    else
        if (b != 0)
            res = a / b;
    printf("결과 : %d", res);
    return 0;
}