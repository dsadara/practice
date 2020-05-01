// ���� ����Ʈ�� ������ ���׽� ���� ���α׷�
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode // ��� Ÿ��
{
    int coef;   // ���
    int expon;  // ����
    struct ListNode *link;
} ListNode;

// ���� ����Ʈ ���
typedef struct ListType // ����Ʈ ��� Ÿ��
{
    int size;
    ListNode *head; // ���� ����Ʈ�� ù��° ��带 ����Ŵ
    ListNode *tail; // ���� ����Ʈ�� ������ ��带 ����Ŵ
} ListType;

// ���� �Լ�
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// ����Ʈ ��� ���� �Լ�
ListType *create_header()
{
    ListType *plist = (ListType *)malloc(sizeof(ListType));
    plist -> size = 0;
    plist->head = plist->tail = NULL;   // tail , head �Ѵ� NULL ����
    return plist;
}

// plist�� ���� ����Ʈ�� ����� ����Ű�� ������, coef�� ���, expon�� ����
void insert_last(ListType* plist, int coef, int expon);
{
    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
    if (temp == NULL) error("�޸� �Ҵ� ����");
    temp->coef = coef;
    temp->expon = expon;
    temp->link = NULL;
    if(plist->tail == NULL) // ����� ���������
        plist->head = plist->tail = temp;   // ��� tail, head �� temp ����
    else    // ����� ������� ������ 
    {
        plist->tail->link = temp;   // tail ��尡 ���� �Ҵ� �� �����temp�� ����Ű�� ��
        plist->tail = temp; // tail �����Ϳ� ������ ����� temp �� ���� 
    }
    plist->size++;
}