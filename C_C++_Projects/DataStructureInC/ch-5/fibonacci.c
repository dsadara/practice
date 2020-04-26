// ť�� ����� �Ǻ���ġ fibonacci using queue
#include <stdio.h>
#include <stdlib.h>
#include "circular_queue.h"

int fibonacci(QueueType *q, int n)
{
    int i, res, tmp1, tmp2;
    if(n == 0)
        return 0;
    if (n == 1)
        return 1;

    enqueue(q, 0);    // f(0) = 0 push
    enqueue(q, 1);    // f(1) = 1 push
    queue_print(q);
    for(i = 1 ; i < n ; i++)
    {
        tmp1 = dequeue(q); tmp2 = dequeue(q);
        res = tmp1 + tmp2;
        enqueue(q, tmp2);
        enqueue(q, res);
        queue_print(q);
    }
    return res;
}

int main(void)
{
    QueueType q;
    int n, res;
    init_queue(&q);
    printf("�Ǻ���ġ ������ n �� �Է��Ͻÿ� : ");
    scanf("%d", &n);
    res = fibonacci(&q, n);    
    printf("f(%d)�� �� : %d", n , res);
    return 0;
}