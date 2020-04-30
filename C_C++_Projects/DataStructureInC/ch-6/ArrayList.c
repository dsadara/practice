// �迭�� ������ ����Ʈ
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    if(L->size == 0)
        printf("List is empty");
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

// ù��° ��ġ�� ���Ҹ� �����ϴ� �Լ� 
void insert_first(ArrayListType *L, element item)
{
    if (L->size >= MAX_LIST_SIZE)
        error("����Ʈ �����÷ο�");
    for (int i = (L->size - 1) ; i >= 0 ; i-- ) // ù��° ���Һ��� ������ ���ұ��� ���������� �� ĭ�� �̵�
    {   
        L->array[i + 1] = L -> array[i];
    }
    L->array[0] = item; L->size++;
}

void clear(ArrayListType *l)
{
    int i, size = l->size;
    if(is_empty(l) == 1)
    {
        error("������ ����Ʈ�� �����ϴ�");
        return;
    }
    /*
    for( int i = 0 ; i < size - 1 ; i++)
    {
        l->array[i] = NULL;    // int �� NULL �������ϸ� ������ �ּҰ� 0 �� �ִ°Ͱ� ���ٰ� �Ѵ�
    }
    */
   //memset(l->array, 0, sizeof(int) * size); �׳� size �� 0�� ���� ����Ʈ�� ����ִ� ���°� �ȴ� 
    l->size = 0;    // ����Ʈ�� ���Ұ� �����Ƿ� size�� 0�� ����
}

void replace(ArrayListType *l, int pos, element item)
{
    if(pos < 0 || pos > l->size - 1)
    {
        error("��ġ ����");
        return;
    }
    l->array[pos] = item;
}

int get_length(ArrayListType *l)
{
    return l->size;
}

int main(void)
{
    ArrayListType list;

    init(&list);
    printf("����Ʈ 0 ���� ��ġ�� 10 �߰� \n");
    insert_first(&list, 10); print_list(&list); // 0���� ��ġ�� 10 �߰��ϰ� ���
    printf("����Ʈ 0 ���� ��ġ�� 20 �߰� \n");
    insert_first(&list, 20); print_list(&list); // 0���� ��ġ�� 20 �߰��ϰ� ���
    printf("����Ʈ 0 ���� ��ġ�� 30 �߰� \n");
    insert_first(&list, 30); print_list(&list); // 0���� ��ġ�� 30 �߰��ϰ� ���
    printf("����Ʈ �� ���� 40 �߰� \n");
    insert_last(&list, 40); print_list(&list);  // �� ���� 40�� �߰��ϰ� ���
    printf("0��° �׸� ����\n");
    delete(&list, 0);   print_list(&list);  // 0���� �׸� �����ϰ� ���
    printf("0��° ���Ҹ� 30���� ��ü \n");
    replace(&list, 0, 30);  print_list(&list);  // 0 ��° ���Ҹ� 30���� ��ü
    printf("����Ʈ ���� : %d\n", get_length(&list));
    printf("����Ʈ ���� \n");
    clear(&list);   print_list(&list);
    return 0;
}