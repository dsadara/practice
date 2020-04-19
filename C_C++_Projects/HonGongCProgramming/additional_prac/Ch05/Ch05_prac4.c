#include <stdio.h>

int main(void)
{
    int a, b;
    printf("a입력 : ");
    scanf("%d", &a);
    
    switch(a)
    {
    case 3: 
        b = 1;
        break;
    case 5:
        b = 2;
        break;
    case 7:
        b = 3;
        break;
    default:
        b = 0;
        break;
    }
    
    printf("b의 값 : %d", b);
    
    return 0;
}