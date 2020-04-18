// ���� �迭 ���� ���α׷� -> ������ ���������� �����ϴ� ���
// ���� : �����ϰ� �����ϱ⽱�� ���� : �ϳ��� ���α׷����� �������� ������ ���ÿ� ����ϱⰡ �����
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100  // ������ �ִ� ũ��
typedef int element;        // �������� �ڷ���
element stack[MAX_STACK_SIZE];  // 1���� �迭
int top = -1;       // ������ ��������� top�� -1���� �ʱ�ȭ

// ���� ���� ���� �Լ�
int is_empty()
{
    return (top == -1); 
}
// ��ȭ ���� ���� �Լ�
int is_full()
{
    return (top == (MAX_STACK_SIZE - 1));  //������ �ε����� 0���� �����ϹǷ�
}
// ���� �Լ�
void push(element item)
{
    if (is_full()) {
        fprintf(stderr, "stack overflow\n");
        return;
    }
    else stack[++top] = item;   // top�� ���� ������Ű�� top��ġ�� item�� ����
}
// ���� �Լ�
element pop()
{
    if (is_empty()) {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    else return stack[top--];
}
// ��ũ �Լ�
element peek()
{
    if (is_empty())
    {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    else return stack[top];
}

int main (void)
{
    push(1);
    push(2);
    push(3);
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    return 0;
}