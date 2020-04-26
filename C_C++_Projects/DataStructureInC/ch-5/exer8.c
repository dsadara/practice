// 원형 큐 프로그램
// 연습문제 8 : 원형큐에 큐에 존재하는 요소의 개수를 반환하는 연산 get_count 구현 
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

// 오류 함수
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType *q)
{
    q->front = q->rear = 0; //front와 rear을 0으로 초기화해서 공백 상태로 만듦
}

int is_empty(QueueType *q)
{
    return (q->front == q->rear);   // front 와 rear 가 같으면 공백상태
}

int is_full(QueueType *q)
{
    return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE );
}

// 원형 큐 출력함수 
void queue_print(QueueType *q)
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
        } while (i != q->front);    // while 문의 조건이 뭘 의미하는지 모르겠음
    }
    printf("\n");
}

// 삽입 함수
void enqueue(QueueType *q, element item)
{
    if(is_full(q))
        error("큐가 포화 상태입니다");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;   // rear 가 4일때 1을 더해서 0으로 만들어줌 (순환큐의 가능한 rear, front값 0 1 2 3 4 0)
    q->data[q->rear] = item;   
}

// 삭제 함수 
element dequeue(QueueType *q)
{
    if (is_empty(q))
        error("큐가 공백상태입니다");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}
// peek 함수 
element peek(QueueType *q)
{
    if (is_empty(q))
        error("큐가 공백상태입니다");
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int get_count(QueueType *q)
{
    if(is_empty(q))
        error("큐가 공백상태입니다");
    return ( q->rear - q->front + MAX_QUEUE_SIZE ) % MAX_QUEUE_SIZE;
}

int main(void)
{
    QueueType queue;
    int element;
    init_queue(&queue);
    printf("--데이터 추가 단계--\n");
    while(!is_full(&queue)) // 포화상태까지 데이터를 추가
    {
        printf("정수를 입력하세요 : ");
        scanf("%d", &element);
        enqueue(&queue, element);
        queue_print(&queue);
        printf("요소의 개수 : %d\n", get_count(&queue));
    }
    printf("큐는 이제 포화상태입니다.\n\n");

    printf("--데이터 삭제 단계--\n");
    while(!is_empty(&queue))
    {
        element = dequeue(&queue);
        printf("꺼내진 정수 : %d \n", element);
        queue_print(&queue);
        printf("요소의 개수 : %d\n", get_count(&queue));
    }
    printf("큐는 공백상태입니다.\n");
    return 0;
}