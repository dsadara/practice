// �迭�� ������ ����Ʈ
#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element;    // �׸��� ����
typedef struct {
    element array[MAX_LIST_SIZE];
    int size;
} ArrayListType;

// ���� ó�� �Լ�
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// ����Ʈ �ʱ�ȭ �Լ�
void init(ArrayListType *L)
{
    L->size = 0;
}

//����Ʈ�� ��������� 1�� ��ȯ, �׷��� ������ 0�� ��ȯ
int is_empty(ArrayListType *L)
{
    return L->size == 0;
}

//����Ʈ�� ���� �������� 1�� ��ȯ, �׷��� ������ 1�� ��ȯ
int is_full(ArrayListType *L)
{
    return L->size == MAX_LIST_SIZE;
}

// pos ��ġ�� �ִ� ���Ҹ� ��ȯ�ϴ� �Լ�
element_get_entry(ArrayListType *L, int pos)    
{
    if(pos < 0 || pos >= L->size)   // pos �� 0�� size ���� �ۿ� ������
        error("��ġ ����");
    return L->array[pos];
}

// ����Ʈ ���
void print_list(ArrayListType *L)
{
    int i;
    for(i = 0 ; i < L->size ; i++)
        printf("%d->", L->array[i]);
    printf("\n");
}

// ����Ʈ�� �ǳ��� �׸��� �߰��ϴ� �Լ�
void insert_last(ArrayListType *L, element item)    
{
    if(L->size >= MAX_LIST_SIZE)    // size�� MAX_LIST_SIZE ���� ũ�� �����÷ο�
        error("����Ʈ �����÷ο�");
    L->array[L->size++] = item; // size ��ġ�� item�� �����ϰ� size �� 1�� ����
}

// pos ��ġ�� �����ϴ� �Լ�
void insert(ArrayListType *L, int pos, element item)    
{
    if (!is_full(L) && (pos >= 0) && (pos <= L->size))   // ����Ʈ�� �����ų� ��ġ�� ����� ������
    {
        for (int i = (L->size -1) ; i >= pos ; i--) // �ǳ��� ���Һ��� pos ���� ���������� ��ĭ�� �̵�
            L->array[i+1] = L->array[i];
        L->array[pos] = item;   // ���ҵ��� ��ĭ �� �̵��Ͽ� ����� pos �� item ����
        L->size++;  // size + 1 
    }   
}

// pos ��ġ�� �׸��� �����ϴ� �Լ�
element delete(ArrayListType *L, int pos)
{
    element item;

    if (pos < 0 || pos >= L->size)
        error("��ġ ����");
    item = L->array[pos];   // ������ ���Ҹ� ��ȯ�ϱ����� ����
    for (int i = pos ; i < (L->size -1) ; i++)  // pos ���� �� ���� ���ұ��� ��ĭ�� �������� �̵�
        L->array[i] = L->array[i+1];
    L->size--;
    return item;    // ������ ���� ��ȯ
}

int main(void)
{
    ArrayListType list;

    init(&list);
    insert(&list, 0, 10); print_list(&list); // 0���� ��ġ�� 10 �߰��ϰ� ���
    insert(&list, 0, 20); print_list(&list); // 0���� ��ġ�� 20 �߰��ϰ� ���
    insert(&list, 0, 30); print_list(&list); // 0���� ��ġ�� 30 �߰��ϰ� ���
    insert_last(&list, 40); print_list(&list);  // �� ���� 40�� �߰��ϰ� ���
    delete(&list, 0);   print_list(&list);  // 0���� �׸� �����ϰ� ���
    return 0;
}