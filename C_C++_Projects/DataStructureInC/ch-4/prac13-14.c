/* utf-8, 주어진 정수에서 반복되는 숫자를 제거하는 프로그램
*/
#include <stdio.h>
#include <string.h>
#include "normal_stack_charVer.h"



int size(Stacktype *stack)
{
    return (stack->top) + 1;
}

void remove_int_duplicate(char *exp, Stacktype *s)
{
    int len = strlen(exp), i;
    element char_integer;   //char char_integer; 로 바꿔서 컴파일해보기 
    init_stack(s);
    push(s, *exp); // 첫번쨰 정수 push 후 출력
    printf("%c", *exp);
    for ( i = 1 ; i < len ; i++ )
    {
        char_integer = *(exp + i);
        if ( char_integer == peek(s) )
            continue;
        else
        {
            push(s, char_integer);
            printf("%c", char_integer);
        }
    }
}

int main(void)
{
    Stacktype s;
    char integers[20] = "122233";
    printf("<exercise13> 정수 문자열 중복제거 결과 : ");
    remove_int_duplicate(integers, &s);
    puts("");
    printf("<exercise14> 스택크기를 반환하는 size 연산 구현 결과 : ");
    printf("%d", size(&s));
    return 0;
}