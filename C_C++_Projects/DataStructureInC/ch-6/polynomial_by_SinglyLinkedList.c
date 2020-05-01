// 연결 리스트로 구현한 다항식 덧셈 프로그램
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode // 노드 타입
{
    int coef;   // 계수
    int expon;  // 지수
    struct ListNode *link;
} ListNode;

// 연결 리스트 헤더
typedef struct ListType // 리스트 헤더 타입
{
    int size;
    ListNode *head; // 연결 리스트의 첫번째 노드를 가리킴
    ListNode *tail; // 연결 리스트의 마지막 노드를 가리킴
} ListType;

// 오류 함수
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 리스트 헤더 생성 함수
ListType *create_header()
{
    ListType *plist = (ListType *)malloc(sizeof(ListType));
    plist -> size = 0;
    plist->head = plist->tail = NULL;   // tail , head 둘다 NULL 저장
    return plist;
}

// plist는 연결 리스트의 헤더를 가리키는 포인터, coef는 계수, expon은 지수
void insert_last(ListType* plist, int coef, int expon);
{
    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
    if (temp == NULL) error("메모리 할당 에러");
    temp->coef = coef;
    temp->expon = expon;
    temp->link = NULL;
    if(plist->tail == NULL) // 헤더가 비어있으면
        plist->head = plist->tail = temp;   // 헤더 tail, head 에 temp 대입
    else    // 헤더가 비어있지 않으면 
    {
        plist->tail->link = temp;   // tail 노드가 동적 할당 한 노드인temp를 가리키게 함
        plist->tail = temp; // tail 포인터에 마지막 노드인 temp 를 저장 
    }
    plist->size++;
}