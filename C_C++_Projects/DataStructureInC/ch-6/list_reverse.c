// 리스트를 역순으로 만드는 연산
#include <stdio.h>
#include <stdlib.h>
#include "SinglyLinkedList_int.h"

ListNode *reverse(ListNode *head)
{
    // 순회 포인터로 p, q, r 사용
    ListNode *p, *q, *r;

    p = head; // p는 역순으로 만들 리스트
    q = NULL; // q는 역순으로 만들 노드
    while (p != NULL)   // p의 모든 노드 들을 가리키고 NULL 을 가리킬 떄 까지
    {
        r = q; // r은 역순으로 된 리스트    |  역순으로된 리스트에 q를 저장한 후
        q = p; // r은 q, q는 p를 차례로 따라간다    |    q에 첫번째 노드의 주소를 저장한다
        p = p->link;    // q 에 p를 저장했으면 p 가 다음 노드를 가리 키게 한다      |    q에 첫번째 노드의 주소를 저장했으면 p 가 두번쨰 노드를 가리키게 한다
        q->link = r;    // q의 링크 방향을 바꾼다 (r로 향하게)      | q->link에 r을 저장한다 그러니까 q 가 NULL을 가리키게 한다
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