/* ��ȣ �˻� ���α׷� : ������ �̿� -> ���� ��ȣ���� ������ ��� �����ϴٰ� ������ ��ȣ����
������ ���ÿ��� ���� �ֱ��� ���ʰ�ȣ�� ������ Ÿ���� ���߾� ���� ��ȣ�� ������ �˻��� �� ����
(������ �׻� �ֱٿ� ������ ���� ���� �ʿ��� ��쿡 ������)
�� ��ȣ�� ����
1. ���� ��ȣ�� ������ ������ ��ȣ�� ������ ���ƾ� �Ѵ�
2. ���� ������ ��ȣ���� ���� ��ȣ�� ������ ��ȣ���� ���� ���;� �Ѵ�
3. ���� �ٸ� ������ ���� ��ȣ�� ������ ��ȣ ���� ���� �����ϸ� �ȵȴ�
ex) ( { ) }
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "normal_stack_charVer.h"   
// ���� �ҽ� ���ϰ� ���� ��ο� �ִ� normal_stack.c ������ �����Ѵ�
// ""../normal_stack.c" ���� �ҽ� ������ ��ο��� ���� ���丮�� �ִ� normal_stack.c������ �����Ѵ�
#define Max_STACK_SIZE 100

int check_matching(const char *in);

int main(void)
{
    char *p = "{ A[(i+1)]=0; }";
    if (check_matching(p) == 1)
        printf("%s ��ȣ�˻缺��\n", p);
    else
        printf("%s ��ȣ�˻����\n", p);
    return 0;
    
}

int check_matching(const char *in)  // const �� �ٿ��� ������ ���� �ּҰ��� ������ �� ����
{
    Stacktype s;
    char ch, open_ch;
    int i, n = strlen(in); // n ���ڿ��� ���� 
    init_stack(&s); // ������ �ʱ�ȭ

    for( i = 0 ; i < n ; i++)
    {
        ch = in[i]; // ch = ��������
        switch(ch) 
        {
        case '(': case '[': case '{':
            push(&s, ch);
            break;
        case ')': case ']': case '}':
            if (is_empty(&s)) return 0;     // ����1, ����2 ����
            else
            {
                open_ch = pop(&s);
                if ((open_ch == '(' && ch != ')') ||
                    (open_ch == '[' && ch != ']') ||
                    (open_ch == '{' && ch != '}'))
                    return 0;
                break;
            }
            

        }
    }
    if (!is_empty(&s)) return 0; // ���ÿ� ���������� ����
    return 1;
}