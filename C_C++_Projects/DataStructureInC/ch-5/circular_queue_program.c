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
        if (rand() % 5 == 0)    // 5로 나누어 떨어지면(20퍼 확률)
        {
            enqueue(&queue, rand()%100);
        }
        queue_print(&queue);
        if (rand() % 10 == 0)   // 10로 나누어 떨어지면(10퍼 확률)
        {
            int data = dequeue(&queue);
        }
        queue_print(&queue);
    }
    return 0;
}
