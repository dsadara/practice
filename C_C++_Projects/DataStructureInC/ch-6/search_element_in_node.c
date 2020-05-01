// 특정한 값을 탐색하는 함수

#include <stdio.h>
#include <stdlib.h>
#include "SinglyLinkedList_int.h"

ListNode *search_list(ListNode *head, element x)
{
    ListNode *p = head;

    while(p != NULL) 
    {
        if (p->data == x) return p; // 탐색값을 가지고 있는 노드의 주소를 반환
        p = p->link;
    }
    return NULL;    // 탐색 실패 하면 NULL 반환 
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
        printf("리스트에서 30을 찾았습니다 \n");
    else 
        printf("리스트에서 30을 찾지 못했습니다");
    return 0;
}