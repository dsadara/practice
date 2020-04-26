#include <stdio.h>
#include <stdlib.h>
#include "bank_simulation_circular_queue.h"

int main(void)
{
    int minutes = 60;
    int total_wait = 0;
    int total_customers = 0;
    int service_time1 = 0, service_time2 = 0;
    int service_customer1, service_customer2;
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
        if (service_time1 > 0 )
        {
            printf("은행원1이 고객 %d 의 업무처리중입니다. \n", service_customer1);
            service_time1--;
        }
        else
        {
            if(!is_empty(&queue))   // 큐가 비어있지 않다면
            {
                element customer = dequeue(&queue);
                service_customer1 = customer.id;
                service_time1 = customer.service_time;
                printf("은행원1이 고객 %d의 업무를 %d분에 시작합니다. 대기시간은 %d분이었습니다. \n",
                customer.id, clock, clock - customer.arrival_time);
                total_wait += clock - customer.arrival_time;
            }
        }
        if (service_time2 > 0 )
        {
            printf("은행원2가 고객 %d의 업무처리중입니다. \n", service_customer2);
            service_time2--;
        }
        else
        {
            if(!is_empty(&queue))   // 큐가 비어있지 않다면
            {
                element customer = dequeue(&queue);
                service_customer2 = customer.id;
                service_time2 = customer.service_time;
                printf("은행원2가 고객 %d이 업무를 %d분에 시작합니다. 대기시간은 %d분이었습니다. \n",
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

