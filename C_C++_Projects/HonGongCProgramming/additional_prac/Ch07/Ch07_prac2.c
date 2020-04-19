#include <stdio.h>

int prime_check(int a);

int main(void)
{
    int num = 23767, prime;
    prime = prime_check(num);
    if(prime == 1)
        printf("소수입니다.");
    else 
        printf("소수가 아닙니다.");
        
    return 0;
}

int prime_check(int a)
{
    int i;
    for(i = 0 ; a / 2 ; i++)
    {
        if((a % (i + 2)) == 0)
            return 0;
    }
    return 1;
}