// ������ ��Ҹ� ����ü�� �ϱ� 
// ������ ���������� ���� -> ���� ���� ������ ���ÿ� ����� �� ���� 
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef struct {
    int student_no;
    char name[MAX_STRING];
    char address[MAX_STRING];
} element;

element stack[MAX_STACK_SIZE];
int top = -1; // ���ÿ� �ƹ� �͵� ������ top�� -1�� ����

//���� ���� ���� �Լ�
int is_empty()
{
    return (top == -1); // top�� -1�̸�(�����̸�) 1 ��ȯ
}

//��ȭ ���� ���� �Լ�
int is_full()
{
    return (top == (MAX_STACK_SIZE - 1));   // top�� ���� �ε��� �������� ������ 1��ȯ
}

//���� �Լ�
void push(element item)
{
    if (is_full())
    {
        fprintf(stderr, "stack overflow\n");
        return;
    }
    else stack[++top] = item; // top�� ���� ������Ű�� �� top�� ��ġ�� item ����
}

// ���� �Լ�
element pop()
{
    if (is_empty())
    {
        fprintf(stderr, "stack empty error\n");
        exit(1);
    }
    else return stack[top--];   // ������ ��� �ʿ� ���� top�� ���� �����ָ� �����Ȱɷ� ģ��
}

element peek()
{
    if (is_empty())
    {
        fprintf(stderr, "stack empty error\n");
        exit(1);
    }
    else return stack[top];
}

int main(void)
{
    element ie = {20190001, "Hong", "Seoul"};
    element oe;

    push(ie);
    oe = pop();


    printf("�й� : %d\n", oe.student_no);
    printf("�̸� : %s\n", oe.name);
    printf("�ּ� : %s\n", oe.address);
    return 0;
}