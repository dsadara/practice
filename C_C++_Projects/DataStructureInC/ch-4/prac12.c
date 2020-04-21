// 런 길이 압축
#include <stdio.h>
#include <string.h>
#include "prac12_stack.h"

void run_length_compress(char *exp)
{
    element tmp;
    int i, len = strlen(exp), alpabet_num = 0;
    char ch;
    Stacktype s;
    init_stack(&s);
    // 첫 문자 push
    tmp.alpabet = *exp; tmp.a_num = (++alpabet_num);
    push(&s, tmp);
    for( i = 1 ; i < len ; i++)
    {
        ch = *(exp + i);
        if( ch == 'a' || ch == 'A')
        {
            if(peek(&s).alpabet != 'a' && peek(&s).alpabet != 'A')
            {
                alpabet_num = 0;
                printf("%d%c", peek(&s).a_num, peek(&s).alpabet);
            }
            tmp.alpabet = 'a'; tmp.a_num = (++alpabet_num);
            push(&s, tmp);
        }
        else if (ch == 'b' || ch == 'B')
        {
            if(peek(&s).alpabet != 'b' && peek(&s).alpabet != 'B')
            {
                alpabet_num = 0;
                printf("%d%c", peek(&s).a_num, peek(&s).alpabet);
            }
            tmp.alpabet = 'b'; tmp.a_num = (++alpabet_num);
            push(&s, tmp);
        }
    }
    printf("%d%c", peek(&s).a_num, peek(&s).alpabet);    // 마지막 문자열 압축본 출력 

}

int main(void)
{
    char exp[20];
    printf("문자열을 입력하시오 : ");
    scanf("%s", exp);
    printf("압축된 문자열 : ");
    run_length_compress(exp);
    return 0;
}