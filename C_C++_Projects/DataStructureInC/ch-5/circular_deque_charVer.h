/* ���� �� ���α׷�
���Ӱ� �߰��� ���꿡�� delete_rear(), add_front(), get_rear()�� �ִ�. ������ ������� ���� ť���� �״�� ����� �� �ִ�
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 20
typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} DequeType;

// ���� �Լ�
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// �ʱ�ȭ
void init_deque(DequeType *q)
{
    q->front = q->rear = 0; //front�� rear�� 0���� �ʱ�ȭ�ؼ� ���� ���·� ����
}

// ���� ���� ���� �Լ� 
int is_empty(DequeType *q)
{
    return (q->front == q->rear);   // front �� rear �� ������ �������
}

// ��ȭ ���� ���� �Լ�
int is_full(DequeType *q)
{
    return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE );   // rear + 1 �� front �̸� ��ȭ �����̴�
}

// ���� ť ����Լ� 
void deque_print(DequeType *q)
{
    printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
    if(!is_empty(q))    // ť�� ������� �ʴٸ�
    {
        int i = q->front;
        do {
                i = (i + 1) % (MAX_QUEUE_SIZE);
                printf("%d | ", q->data[i]);
                if(i == q->rear)
                    break;
        } while (i != q->front);    // while ���� ������ �� �ǹ��ϴ��� �𸣰��� -> q�� front �� �ɶ� ���� �ݺ��̴ϱ� ���� ť �ѹ��� ���θ� ���ٴ� ���ΰ� 
    }
    printf("\n");
}

// ť�� �Ĵ�(rear)�� �ִ� ���� �Լ� -> ���� ���� ť �Լ��� ����
void add_rear(DequeType *q, element item)
{
    if(is_full(q))
        error("ť�� ��ȭ �����Դϴ�");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;   // rear �� 4�϶� 1�� ���ؼ� 0���� ������� (��ȯť�� ������ rear, front�� 0 1 2 3 4 0)
    q->data[q->rear] = item;   
}

// ť�� �մ�(front)���� �����ϰ� ������ ���Ҹ� ��ȯ�ϴ� �Լ� -> ���� ���� ť �Լ��� ����
element delete_front(DequeType *q)
{
    if (is_empty(q))
        error("ť�� ��������Դϴ�");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE; // front�� �׻� �����Ͱ� �ִ� �ε��� - 1 �� ��ġ�Ѵ� -> �����Ͱ� �ϳ� �پ����Ƿ� + 1, ���� ���� ť �Լ��� ���� 
    return q->data[q->front];
}

// ť�� �մ�(front)���� peek �ϴ� �Լ� -> ���� ���� ť �Լ��� ���� 
element get_front(DequeType *q)
{
    if (is_empty(q))
        error("ť�� ��������Դϴ�");
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

// ----------- ���⼭���� Dequeue ���� ���Ӱ� �߰��� ���� ---------------

void add_front(DequeType *q, element val)   // ť�� �մ�(front)�� �ִ� �����Լ�
{
    if(is_full(q))
        error("ť�� ��ȭ �����Դϴ�");
    q->data[q->front] = val;
    q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;    // front�� ������ �Ǵ� ���� ���� 
}

element delete_rear(DequeType *q)       // ť�� �Ĵ�(rear) ���� �����ϴ� �Լ� 
{
    int prev = q->rear; // ��ȯ�� �������� ��ġ�� ���� �س���
    if (is_empty(q))
        error("ť�� ���� �����Դϴ�");
    q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;    // rear �� ������ �Ǵ� ���� ����
    return q->data[prev];   // ������ �Լ��� ��ȯ
}

element get_rear(DequeType *q)          // ť�� �Ĵ�(rear) ���� �����ϴ� �Լ� 
{
    if (is_empty(q))
        error("ť�� ���� �����Դϴ�");
    return q->data[q->rear];
}

element get_count(DequeType *q)
{
    if(is_empty(q))
        error("ť�� ��������Դϴ�");
    return ( q->rear - q->front + MAX_QUEUE_SIZE ) % MAX_QUEUE_SIZE;
}