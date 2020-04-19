// ������ �ð��� �ʿ��� ������ ũ�⸦ �˾Ƴ���� ��ƴ�
// c������ malloc()�� ȣ���Ͽ��� ����ð��� �޸𸮸� �Ҵ� ���� �� �ִ�

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
    element *data;  // data�� �����ͷ� ���ǵ�(�����Ҵ������ؼ�)
    int capacity;   // ���� ũ��
    int top;
} stacktype;

// ���� ���� �Լ�
void init_stack(stacktype *s)
{
    s->top = -1;
    s->capacity = 1;    // �ϴ� ũ�� 1�� �迭�� ����
    s->data = (element *)malloc(s->capacity * sizeof(element));
}

// ���� ���� ���� �Լ�
int is_empty(stacktype *s)
{
    return (s->top == -1);
}

// ��ȭ ���� ���� �Լ�
int is_full(stacktype *s)
{
    return (s->top == (s->capacity -1));
}
//�����Լ�
void push(stacktype *s, element item)
{
    if(is_full(s)) 
    {
        s->capacity *= 2;       // ��ȭ �����̸� ���� ũ�⸦ �ι�� �ø���
        s->data = 
            (element *)realloc(s->data, s->capacity * sizeof(element));
    }
    s->data[++(s->top)] = item;     // top�� 1�� �ø� �� item�� �����Ѵ�
}
// �����Լ�
element pop(stacktype *s)
{
    if(is_empty(s))
    {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

int main(void)
{
    stacktype s;
    init_stack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 4);
    push(&s, 5);
    push(&s, 6);
    push(&s, 7);
    push(&s, 8);
    push(&s, 9);
    push(&s, 10);
    push(&s, 11);
    push(&s, 12);
    push(&s, 13);
    push(&s, 14);
    push(&s, 15);
    push(&s, 16);
    push(&s, 17);
    printf("%d \n", pop(&s));
    printf("%d \n", pop(&s));
    printf("%d \n", pop(&s));
        printf("%d \n", pop(&s));
    printf("%d \n", pop(&s));
    printf("%d \n", pop(&s));
        printf("%d \n", pop(&s));
    printf("%d \n", pop(&s));
    printf("%d \n", pop(&s));
        printf("%d \n", pop(&s));
    printf("%d \n", pop(&s));
    printf("%d \n", pop(&s));
    free(s.data);
    return 0;

}