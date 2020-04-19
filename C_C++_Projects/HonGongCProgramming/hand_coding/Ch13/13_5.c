#include <stdio.h>

int main(void)
{
    register int i;
    auto int sum = 0;
    
    for (i = 1 ; i <= 10000 ; i++)
    {
        sum += i;
    }
    
    printf("%d\n", sum);
    
    return 0;
}

//register 변수에다가 저장하면 일반 메모리보다 빠른 레지스터 메모리에 변수가 저장된다. -> 반복문에 사용하는 등 사용횟수가 많은 변수에 사용하면 좋다 