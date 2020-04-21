//  배열에 들어 있는 정수의 순서를 거꾸로 하는 프로그램
#include <stdio.h>
#include <string.h>
#include "normal_stack_int_ver.h"
typedef int element;

int main(void)
{
    int num, tmp;
    Stacktype s;
    printf("정수 배열의 크기 : ");
    scanf("%d", &num);
    init_stack(&s);
    printf("정수를 입력하시오 : ");
    for(int i = 0 ; i < num ; i++ )
    {
        scanf("%d", &tmp);
        push(&s, tmp);
    }
    printf("반전된 정수 배열 : ");
    for(int i = 0 ; i < num ; i++)
    {
        printf("%d ", pop(&s));
    }
    return 0;
}