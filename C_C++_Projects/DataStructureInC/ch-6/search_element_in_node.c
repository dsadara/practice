// Ư���� ���� Ž���ϴ� �Լ�

#include <stdio.h>
#include <stdlib.h>
#include "SinglyLinkedList_int.h"

ListNode *search_list(ListNode *head, element x)
{
    ListNode *p = head;

    while(p != NULL) 
    {
        if (p->data == x) return p; // Ž������ ������ �ִ� ����� �ּҸ� ��ȯ
        p = p->link;
    }
    return NULL;    // Ž�� ���� �ϸ� NULL ��ȯ 
}

int main(void)
{
    ListNode *head = NULL;

    head = insert_first(head, 10);
    print_list(head);
    head = insert_first(head, 20);
    print_list(head);
    head = insert_first(head, 30);
    print_list(head);
    if(search_list(head, 30) != NULL)
        printf("����Ʈ���� 30�� ã�ҽ��ϴ� \n");
    else 
        printf("����Ʈ���� 30�� ã�� ���߽��ϴ�");
    return 0;
}