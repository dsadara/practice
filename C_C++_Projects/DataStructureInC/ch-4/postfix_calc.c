// ����ǥ��� ���
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
#include "normal_stack_charVer.h"       // ���� �ڵ� �߰�

// ���� ǥ�� ���� ��� �Լ�
int eval(char exp[])
{
    int op1, op2, value, i = 0;
    int len = strlen(exp);
    char ch;
    Stacktype s;

    init_stack(&s);
    for ( i = 0 ; i < len ; i++)
    {
        ch = exp[i];
        if(ch != '+' && ch != '-' && ch != '*' && ch != '/')
        {
            value = ch - '0';   // �Է��� �ǿ������̸� ���� ���� ���ڰ��� �ƴ� ���ڷ� ����(ASCII to BINARY?)
            push(&s, value);
        }
        else    // �������̸� �ǿ����ڸ� ���ÿ��� ����
        {
            op2 = pop(&s);
            op1 = pop(&s);
            switch(ch) 
            {   // ������ �����ϰ� ���ÿ� ����
            case '+': push(&s, op1 + op2); break;
            case '-': push(&s, op1 - op2); break;
            case '*': push(&s, op1 * op2); break;
            case '/': push(&s, op1 / op2); break;  
            }
        }

    }
    return pop(&s);
}

int main(void)
{
    int result;
    printf("����ǥ����� 82/3-32*+\n");
    result = eval("82/3-32*+");
    printf("������� %d\n", result);
    return 0;
}
