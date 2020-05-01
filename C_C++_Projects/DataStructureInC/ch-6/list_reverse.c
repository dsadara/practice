// ����Ʈ�� �������� ����� ����
#include <stdio.h>
#include <stdlib.h>
#include "SinglyLinkedList_int.h"

ListNode *reverse(ListNode *head)
{
    // ��ȸ �����ͷ� p, q, r ���
    ListNode *p, *q, *r;

    p = head; // p�� �������� ���� ����Ʈ
    q = NULL; // q�� �������� ���� ���
    while (p != NULL)   // p�� ��� ��� ���� ����Ű�� NULL �� ����ų �� ����
    {
        r = q; // r�� �������� �� ����Ʈ    |  �������ε� ����Ʈ�� q�� ������ ��
        q = p; // r�� q, q�� p�� ���ʷ� ���󰣴�    |    q�� ù��° ����� �ּҸ� �����Ѵ�
        p = p->link;    // q �� p�� ���������� p �� ���� ��带 ���� Ű�� �Ѵ�      |    q�� ù��° ����� �ּҸ� ���������� p �� �ι��� ��带 ����Ű�� �Ѵ�
        q->link = r;    // q�� ��ũ ������ �ٲ۴� (r�� ���ϰ�)      | q->link�� r�� �����Ѵ� �׷��ϱ� q �� NULL�� ����Ű�� �Ѵ�
    }
    return q;
}

int main(void)
{
    ListNode *head1 = NULL;
    ListNode *head2 = NULL;

    head1 = insert_first(head1, 10);
    head1 = insert_first(head1, 20);
    head1 = insert_first(head1, 30);
    print_list(head1);

    head2 = reverse(head1);
    print_list(head2);
    return 0;

}