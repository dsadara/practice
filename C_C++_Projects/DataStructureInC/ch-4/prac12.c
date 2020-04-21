// �� ���� ����
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
    // ù ���� push
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
    printf("%d%c", peek(&s).a_num, peek(&s).alpabet);    // ������ ���ڿ� ���ົ ��� 

}

int main(void)
{
    char exp[20];
    printf("���ڿ��� �Է��Ͻÿ� : ");
    scanf("%s", exp);
    printf("����� ���ڿ� : ");
    run_length_compress(exp);
    return 0;
}