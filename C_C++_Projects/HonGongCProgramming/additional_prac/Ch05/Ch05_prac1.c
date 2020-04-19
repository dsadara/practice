#include <stdio.h>

int main(void)
{
    int a = 10, b = 3, result;
    if(a > b)
        result = a / b;
    if(a <= b)
        result = a % b;
    printf("결과 : %d", result);
    return 0;
}