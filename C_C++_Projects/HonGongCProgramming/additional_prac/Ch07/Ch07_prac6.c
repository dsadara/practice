#include <stdio.h>


int prime_check(int n);

int main(void)
{
    int num, i, prime, count = 0;
    printf("양수입력 : ");
    scanf("%d", &num);
    for(i = 2 ; i <= num ; i++)
    {
        prime = prime_check(i);
        if(prime == 1)
        {
            printf("%5d", i);
            count++;
        }
        if(count == 5)
        {
            printf("\n");
            count = 0;
        }
    }
    return 0;
}

int prime_check(int n)
{
    if(n == 2)
        return  1;
    int i;
    for(i = 2 ; i < n ; i++)
    {
        if((n % i) == 0)
            return 0;
    }
    return 1;
}