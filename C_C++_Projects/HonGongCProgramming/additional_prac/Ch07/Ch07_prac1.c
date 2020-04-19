#include <stdio.h>

int my_power(int a, int b);

int main(void)
{
    int a, b, result;
    printf("밑수와 지수를 입력하시오 : ");
    scanf("%d%d", &a, &b);
    result = my_power(a, b);
    printf("%d", result);
    return 0;
}

int my_power(int a, int b)
{
    int result = 1;
    for(int i = 0 ; i < b ; i++)
    {
        result *= a;
    }
    return result;
}