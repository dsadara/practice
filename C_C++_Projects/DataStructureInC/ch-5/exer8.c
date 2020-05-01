// ���� ť ���α׷�
// �������� 8 : ����ť�� ť�� �����ϴ� ����� ������ ��ȯ�ϴ� ���� get_count ���� 
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

// ���� �Լ�
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType *q)
{
    q->front = q->rear = 0; //front�� rear�� 0���� �ʱ�ȭ�ؼ� ���� ���·� ����
}

int is_empty(QueueType *q)
{
    return (q->front == q->rear);   // front �� rear �� ������ �������
}

int is_full(QueueType *q)
{
    return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE );
}

// ���� ť ����Լ� 
void queue_print(QueueType *q)
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
        } while (i != q->front);    // while ���� ������ �� �ǹ��ϴ��� �𸣰���
    }
    printf("\n");
}

// ���� �Լ�
void enqueue(QueueType *q, element item)
{
    if(is_full(q))
        error("ť�� ��ȭ �����Դϴ�");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;   // rear �� 4�϶� 1�� ���ؼ� 0���� ������� (��ȯť�� ������ rear, front�� 0 1 2 3 4 0)
    q->data[q->rear] = item;   
}

// ���� �Լ� 
element dequeue(QueueType *q)
{
    if (is_empty(q))
        error("ť�� ��������Դϴ�");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}
// peek �Լ� 
element peek(QueueType *q)
{
    if (is_empty(q))
        error("ť�� ��������Դϴ�");
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int get_count(QueueType *q)
{
    if(is_empty(q))
        error("ť�� ��������Դϴ�");
    return ( q->rear - q->front + MAX_QUEUE_SIZE ) % MAX_QUEUE_SIZE;
}

int main(void)
{
    QueueType queue;
    int element;
    init_queue(&queue);
    printf("--������ �߰� �ܰ�--\n");
    while(!is_full(&queue)) // ��ȭ���±��� �����͸� �߰�
    {
        printf("������ �Է��ϼ��� : ");
        scanf("%d", &element);
        enqueue(&queue, element);
        queue_print(&queue);
        printf("����� ���� : %d\n", get_count(&queue));
    }
    printf("ť�� ���� ��ȭ�����Դϴ�.\n\n");

    printf("--������ ���� �ܰ�--\n");
    while(!is_empty(&queue))
    {
        element = dequeue(&queue);
        printf("������ ���� : %d \n", element);
        queue_print(&queue);
        printf("����� ���� : %d\n", get_count(&queue));
    }
    printf("ť�� ��������Դϴ�.\n");
    return 0;
}