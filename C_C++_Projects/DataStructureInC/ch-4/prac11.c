// 수식에 있는 괄호의 번호를 출력하는 프로그램
// 왼쪽 괄호가 나올 때마다 괄호 번호는 하나씩 증가
#include <stdio.h>
#include <string.h>
#include "prac11_stack.h"

void print_parenthesis(char *exp)
{
    int i = 0, left_parenthesis_label = 0, len = strlen(exp);
    char ch;
    Stacktype left_p, right_p;
    element tmp;
    init_stack(&left_p); init_stack(&right_p);
    
    for( i = 0 ; i < len ; i++ )
    {
        ch = *(exp + i);
        if (ch == '(')
        {
            tmp.parenthesis = '('; tmp.p_num = ++left_parenthesis_label;
            push(&left_p, tmp);
            printf("%d ", tmp.p_num);

        }
        else if (ch == ')')
        {
            tmp.parenthesis = ')'; tmp.p_num = (pop(&left_p)).p_num;
            push(&right_p, tmp);
            printf("%d ", tmp.p_num);
        }
    }
}

int main(void)
{
    char exp[50];
    printf("수식 : ");
    gets(exp);
    printf("괄호 수 : ");
    print_parenthesis(exp);
    return 0;
}