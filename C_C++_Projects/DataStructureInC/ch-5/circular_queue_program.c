#include <stdio.h>
#include <stdlib.h>
#include "circular_queue.h"

int main(void)
{
    QueueType queue;
    int element;

    init_queue(&queue);
    srand(time(NULL));

    for(int i = 0 ; i < 100 ; i++)
    {
        if (rand() % 5 == 0)    // 5�� ������ ��������(20�� Ȯ��)
        {
            enqueue(&queue, rand()%100);
        }
        queue_print(&queue);
        if (rand() % 10 == 0)   // 10�� ������ ��������(10�� Ȯ��)
        {
            int data = dequeue(&queue);
        }
        queue_print(&queue);
    }
    return 0;
}
