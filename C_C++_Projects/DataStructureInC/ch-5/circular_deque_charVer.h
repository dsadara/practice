/* 원형 덱 프로그램
새롭게 추가된 연산에는 delete_rear(), add_front(), get_rear()가 있다. 나머지 연산들은 원형 큐에서 그대로 사용할 수 있다
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 20
typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} DequeType;

// 오류 함수
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 초기화
void init_deque(DequeType *q)
{
    q->front = q->rear = 0; //front와 rear을 0으로 초기화해서 공백 상태로 만듦
}

// 공백 상태 검출 함수 
int is_empty(DequeType *q)
{
    return (q->front == q->rear);   // front 와 rear 가 같으면 공백상태
}

// 포화 상태 검출 함수
int is_full(DequeType *q)
{
    return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE );   // rear + 1 이 front 이면 포화 상태이다
}

// 원형 큐 출력함수 
void deque_print(DequeType *q)
{
    printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
    if(!is_empty(q))    // 큐가 비어있지 않다면
    {
        int i = q->front;
        do {
                i = (i + 1) % (MAX_QUEUE_SIZE);
                printf("%d | ", q->data[i]);
                if(i == q->rear)
                    break;
        } while (i != q->front);    // while 문의 조건이 뭘 의미하는지 모르겠음 -> q가 front 가 될때 까지 반복이니까 원형 큐 한바퀴 전부를 돈다는 것인가 
    }
    printf("\n");
}

// 큐의 후단(rear)에 넣는 삽입 함수 -> 기존 원형 큐 함수와 동일
void add_rear(DequeType *q, element item)
{
    if(is_full(q))
        error("큐가 포화 상태입니다");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;   // rear 가 4일때 1을 더해서 0으로 만들어줌 (순환큐의 가능한 rear, front값 0 1 2 3 4 0)
    q->data[q->rear] = item;   
}

// 큐의 앞단(front)에서 삭제하고 삭제한 원소를 반환하는 함수 -> 기존 원형 큐 함수와 동일
element delete_front(DequeType *q)
{
    if (is_empty(q))
        error("큐가 공백상태입니다");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE; // front는 항상 데이터가 있는 인덱스 - 1 에 위치한다 -> 데이터가 하나 줄었으므로 + 1, 기존 원형 큐 함수와 동일 
    return q->data[q->front];
}

// 큐의 앞단(front)에서 peek 하는 함수 -> 기존 원형 큐 함수와 동일 
element get_front(DequeType *q)
{
    if (is_empty(q))
        error("큐가 공백상태입니다");
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

// ----------- 여기서부터 Dequeue 에서 새롭게 추가된 연산 ---------------

void add_front(DequeType *q, element val)   // 큐의 앞단(front)에 넣는 삽입함수
{
    if(is_full(q))
        error("큐가 포화 상태입니다");
    q->data[q->front] = val;
    q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;    // front가 음수가 되는 것을 방지 
}

element delete_rear(DequeType *q)       // 큐의 후단(rear) 에서 삭제하는 함수 
{
    int prev = q->rear; // 반환할 데이터의 위치를 저장 해놓음
    if (is_empty(q))
        error("큐가 공백 상태입니다");
    q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;    // rear 가 음수가 되는 것을 방지
    return q->data[prev];   // 삭제한 함수를 반환
}

element get_rear(DequeType *q)          // 큐의 후단(rear) 에서 삭제하는 함수 
{
    if (is_empty(q))
        error("큐가 공백 상태입니다");
    return q->data[q->rear];
}

element get_count(DequeType *q)
{
    if(is_empty(q))
        error("큐가 공백상태입니다");
    return ( q->rear - q->front + MAX_QUEUE_SIZE ) % MAX_QUEUE_SIZE;
}