// �̷� Ž�� ���α׷�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAZE_SIZE 6

// ���� �ڵ� �߰�
#define MAX_STACK_SIZE 100

typedef struct
{                   // ��ü!
    short r;
    short c;
} element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} Stacktype;

// ���� �ʱ�ȭ �Լ�
void init_stack(Stacktype *s)
{
    s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(Stacktype *s)      // data �迭�� ��ȯ�Ҷ��� �Լ��� ��ȯ���� element�� ������ �װ� �ƴ϶�� int�� ��ȯ�Ѵ� 
{
    return ((s->top) == -1);    // ������ �켱������ ������ -> �� ��ȣ�� ���ĵ� �Ǳ���
}

//��ȭ ���� ���� �Լ�
int is_full(Stacktype *s)
{
    return (s->top == (MAX_STACK_SIZE - 1));    // (MAX_STACK_SIZE - 1)�� �ε��� �� ������ ��ġ
}

//�����Լ�
void push(Stacktype *s, element item)
{
    if(is_full(s))
    {
        fprintf(stderr, "stack overflow\n");
        return;
    }
    else s->data[++(s->top)] = item;    // top�� ���� ������Ű�� item ����
}

// �����Լ�
element pop(Stacktype *s)
{
    if(is_empty(s))
    {
        fprintf(stderr, "stack empty error\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}
// ��ũ�Լ�
element peek(Stacktype *s)
{
    if(is_empty(s))
    {
        fprintf(stderr, "stack empty error\n");
        exit(1);
    }
    else return s->data[s->top];
}
// ���� �ڵ� ��

element here = {1, 0}, entry = {1, 0};

char maze[MAZE_SIZE][MAZE_SIZE] = {
    {'1', '1', '1', '1', '1', '1'},
    {'e', '0', '1', '0', '0', '1'},
    {'1', '0', '0', '0', '1', '1'},
    {'1', '0', '1', '0', '1', '1'},
    {'1', '0', '1', '0', '0', 'x'},
    {'1', '1', '1', '1', '1', '1'},
};
//��ġ�� ���ÿ� ����
void push_loc(Stacktype *s, int r, int c)
{
    if (r < 0 || c < 0) return;
    if (maze[r][c])
}