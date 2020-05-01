// �ΰ��� ����Ʈ�� �ϳ��� ��ġ�� �Լ� 
#include <stdio.h>
#include <stdlib.h>
#include "SinglyLinkedList_int.h"

ListNode *concat_list(ListNode *head1, ListNode *head2)
{
    if (head1 == NULL) return head2;    // ���� head1, head2 �� ������� ���
    else if (head2 == NULL) return head1;
    else {  // ���� ������ ������� ������ ��ġ�� ����
        ListNode *p;
        p = head1;
        while(p->link != NULL)  // p�� head1 �� ��������带 ����ų ������ �ݺ�
            p = p->link;
        p->link = head2;    // p->link �� head2�� ����Ű�� ��
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