#include <stdio.h>

void func(int *mod, int *rem);

int main(void)
{
    int mod, rem;
    func(&mod, &rem);
    printf("몫 : %d, 나머지 : %d", mod, rem);
    
    return 0;
}

void func(int *mod, int *rem)
{
    int num;
    printf("양수 입력 : ");
    scanf("%d", &num);
    *mod = num / 4;
    *rem = num % 4;
    return; 
}