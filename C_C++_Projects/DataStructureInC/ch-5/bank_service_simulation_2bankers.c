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
        printf("����ð�=%d\n", clock);
        if((rand()%10) < 3)
        {
            element customer;
            customer.id = total_customers++;
            customer.arrival_time = clock;
            customer.service_time = rand() % 3 + 1; // ?? 
            enqueue(&queue, customer);
            printf("�� %d�� %d�п� ���ɴϴ�. ����ó���ð�= %d��\n",
            customer.id, customer.arrival_time, customer.service_time);
        }
        if (service_time1 > 0 )
        {
            printf("�����1�� �� %d �� ����ó�����Դϴ�. \n", service_customer1);
            service_time1--;
        }
        else
        {
            if(!is_empty(&queue))   // ť�� ������� �ʴٸ�
            {
                element customer = dequeue(&queue);
                service_customer1 = customer.id;
                service_time1 = customer.service_time;
                printf("�����1�� �� %d�� ������ %d�п� �����մϴ�. ���ð��� %d���̾����ϴ�. \n",
                customer.id, clock, clock - customer.arrival_time);
                total_wait += clock - customer.arrival_time;
            }
        }
        if (service_time2 > 0 )
        {
            printf("�����2�� �� %d�� ����ó�����Դϴ�. \n", service_customer2);
            service_time2--;
        }
        else
        {
            if(!is_empty(&queue))   // ť�� ������� �ʴٸ�
            {
                element customer = dequeue(&queue);
                service_customer2 = customer.id;
                service_time2 = customer.service_time;
                printf("�����2�� �� %d�� ������ %d�п� �����մϴ�. ���ð��� %d���̾����ϴ�. \n",
                customer.id, clock, clock - customer.arrival_time);
                total_wait += clock - customer.arrival_time;
            }
        }
    }
    printf("��ü ��� �ð�=%d�� \n", total_wait);
    printf("��ü �� ��=%d�� \n", total_customers);
    printf("��� ��� �ð�=%.2lf�� \n", (double) total_wait / total_customers);
    return 0; 
}

