// ���Ŀ� �ִ� ��ȣ�� ��ȣ�� ����ϴ� ���α׷�
// ���� ��ȣ�� ���� ������ ��ȣ ��ȣ�� �ϳ��� ����
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
    printf("���� : ");
    gets(exp);
    printf("��ȣ �� : ");
    print_parenthesis(exp);
    return 0;
}