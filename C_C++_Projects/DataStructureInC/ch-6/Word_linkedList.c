// 단어를 저장하는 연결 리스트 (과일이름)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
} element;

typedef struct ListNode 
{
    element data;
    struct ListNode *link;
} ListNode;

// 오류 처리 함수
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListNode* insert_first(ListNode *head, element value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head; // 헤드 포인터의 값을 복사
    head = p;   // 헤드 포인터 변경
    return head;
}

void print_list(ListNode *head)
{
    for (ListNode *p = head ; p != NULL ; p = p->link)
        printf("%s->", p->data.name);
    printf("NULL \n");
}

// 테스트 프로그램
int main(void)
{
    ListNode *head = NULL;
    element data;

    strcpy(data.name, "APPLE");
    head = insert_first(head, data);
    print_list(head);

    strcpy(data.name, "KIWI");
    head = insert_first(head, data);
    print_list(head);

    strcpy(data.name, "BANANA");
    head = insert_first(head, data);
    print_list(head);

    return 0;
}