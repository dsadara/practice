#include <stdio.h>
#include <stdlib.h>
#include "bank_simulation_circular_queue.h"

int main(void)
{
    int minutes = 60;
    int total_wait = 0;
    int total_customers = 0;
    int service_time = 0;
    int service_customer;
    QueueType queue;
    init_queue(&queue);

    srand(time(NULL));
    for(int clock = 0 ; clock < minutes; clock++)
    {
        printf("현재시각=%d\n", clock);
        if((rand()%10) < 3)
        {
            element customer;
            customer.id = total_customers++;
            customer.arrival_time = clock;
            customer.service_time = rand() % 3 + 1; // ?? 
            enqueue(&queue, customer);
            printf("고객 %d이 %d분에 들어옵니다. 업무처리시간= %d분\n",
            customer.id, customer.arrival_time, customer.service_time);
        }
        if (service_time > 0 )
        {
            printf("고객 %d 업무처리중입니다. \n", service_customer);
            service_time--;
        }
        else
        {
            if(!is_empty(&queue))   // 큐가 비어있지 않다면
            {
                element customer = dequeue(&queue);
                service_customer = customer.id;
                service_time = customer.service_time;
                printf("고객 %d이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다. \n",
                customer.id, clock, clock - customer.arrival_time);
                total_wait += clock - customer.arrival_time;
            }
        }
    }
    printf("전체 대기 시간=%d분 \n", total_wait);
    printf("전체 고객 수=%d명 \n", total_customers);
    printf("평균 대기 시간=%.2lf분 \n", (double) total_wait / total_customers);
    return 0; 
}
