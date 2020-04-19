// 개별적으로 할당된 구조체 변수들을 포인터로 연결, 자기 참조 구조체

#include <stdio.h>

struct list // 자기 참조 구조체
{
    int num;
    struct list *next;      // 구조체 자신을 가리키는 포인터 멤버
};

int main(void)
{
    struct list a ={10, 0}, b = {20, 0}, c = {30, 0};
    struct list *head = &a, *current;

    a.next = &b;
    b.next = &c;

    printf("head->num, : %d\n", head -> num);
    printf("head->next->num : %d\n", head -> next -> num);

    printf("list all : ");
    current = head;
    while(current != NULL) //마지막 구조체 변수까지 출력하면 반복종료
    {
        printf("%d  ", current->num);
        current = current -> next;
    }
    printf("\n");

    return 0;
}