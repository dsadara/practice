// 2개의 스택을 사용하여 큐를 구현하느 프로그램
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
    printf("정수 입력 \n");
    push(&(q->s1), item);
}

int dequeue(Queuetype *q)   // 두개의 스택을 이용해서 FIFO(First In First Out)이 되도록 설계 
{
    printf("정수 삭제 \n");
    int res, i, ele_num;
    ele_num = q->s1.top + 1;
    for(i = 0 ; i < ele_num ; i++)    // s1에있는 원소의 수만큼 반복
    {
        push(&(q->s2), pop(&(q->s1)));  // s1에 있는 원소들을 s2에다가 push하여 저장(s1과 순서가 반대로 저장된다)
    }
    res = pop(&(q->s2));
    ele_num = q->s2.top + 1;
    for(i = 0 ; i < ele_num ; i++)    // s2 에 남아있는 원소의 수만큼 반복
    {
        push(&(q->s1), pop(&(q->s2)));  // s2에 남아있는 원소를 원래의 순서대로 s1에 저장
    }
    return res;
}

void print_queue(Queuetype *q)
{
    int tmp, i, ele_num;
    ele_num = q->s1.top + 1;
    printf("큐의 원소 출력");
    for(i = 0 ; i < ele_num ; i++)
    {
        tmp = pop(&(q->s1));
       printf(" %d |   ", tmp);
       push(&(q->s2), tmp);
    }
    puts("");
    ele_num = q->s2.top + 1;
    for(i = 0 ; i < ele_num ; i++)    // 원래대로 원소들을 s1에 저장
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
