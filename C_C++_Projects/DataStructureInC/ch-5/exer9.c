// 2���� ������ ����Ͽ� ť�� �����ϴ� ���α׷�
#include <stdio.h>
#include <stdlib.h>
#include "..\ch-4\normal_stack_int_ver.h"

typedef struct {
    Stacktype s1;
    Stacktype s2;
} Queuetype;

void init_queue(Queuetype *q)
{
    q->s1.top = -1;
    q->s2.top = -1;
}

void enqueue(Queuetype *q, element item)
{
    printf("���� �Է� \n");
    push(&(q->s1), item);
}

int dequeue(Queuetype *q)   // �ΰ��� ������ �̿��ؼ� FIFO(First In First Out)�� �ǵ��� ���� 
{
    printf("���� ���� \n");
    int res, i, ele_num;
    ele_num = q->s1.top + 1;
    for(i = 0 ; i < ele_num ; i++)    // s1���ִ� ������ ����ŭ �ݺ�
    {
        push(&(q->s2), pop(&(q->s1)));  // s1�� �ִ� ���ҵ��� s2���ٰ� push�Ͽ� ����(s1�� ������ �ݴ�� ����ȴ�)
    }
    res = pop(&(q->s2));
    ele_num = q->s2.top + 1;
    for(i = 0 ; i < ele_num ; i++)    // s2 �� �����ִ� ������ ����ŭ �ݺ�
    {
        push(&(q->s1), pop(&(q->s2)));  // s2�� �����ִ� ���Ҹ� ������ ������� s1�� ����
    }
    return res;
}

void print_queue(Queuetype *q)
{
    int tmp, i, ele_num;
    ele_num = q->s1.top + 1;
    printf("ť�� ���� ���");
    for(i = 0 ; i < ele_num ; i++)
    {
        tmp = pop(&(q->s1));
       printf(" %d |   ", tmp);
       push(&(q->s2), tmp);
    }
    puts("");
    ele_num = q->s2.top + 1;
    for(i = 0 ; i < ele_num ; i++)    // ������� ���ҵ��� s1�� ����
    {
        tmp = pop(&(q->s2));
        push(&(q->s1), tmp);
    }
}

int main(void)
{
    int i;
    Queuetype q;
    init_queue(&q);
    for(i = 0 ; i < 4 ; i++)
    {
        enqueue(&q, i);
        print_queue(&q);
    }
    
    for(i = 0 ; i < 4 ; i++)
    {
        dequeue(&q);
        print_queue(&q);
    }
    
    return 0; 
}
