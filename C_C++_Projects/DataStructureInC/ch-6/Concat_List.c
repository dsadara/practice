// 두개의 리스트를 하나로 합치는 함수 
#include <stdio.h>
#include <stdlib.h>
#include "SinglyLinkedList_int.h"

ListNode *concat_list(ListNode *head1, ListNode *head2)
{
    if (head1 == NULL) return head2;    // 각각 head1, head2 가 비어있을 경우
    else if (head2 == NULL) return head1;
    else {  // 각각 헤드들이 비어있지 않으면 합치기 시작
        ListNode *p;
        p = head1;
        while(p->link != NULL)  // p가 head1 의 마지막노드를 가리킬 때까지 반복
            p = p->link;
        p->link = head2;    // p->link 가 head2를 가리키게 함
        return head1;
    }
}

int main(void)
{
    ListNode* head1 = NULL;
    ListNode* head2 = NULL;

    head1 = insert_first(head1, 10);
    head1 = insert_first(head1, 20);
    head1 = insert_first(head1, 30);
    print_list(head1);

    head2 = insert_first(head2, 50);
    head2 = insert_first(head2, 40);
    print_list(head2);

    ListNode *total = concat_list(head1, head2);
    print_list(total);
    return 0;
}