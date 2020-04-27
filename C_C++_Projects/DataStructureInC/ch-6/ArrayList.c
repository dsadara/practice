// 배열로 구현한 리스트
#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element;    // 항목의 정의
typedef struct {
    element array[MAX_LIST_SIZE];
    int size;
} ArrayListType;

// 오류 처리 함수
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 리스트 초기화 함수
void init(ArrayListType *L)
{
    L->size = 0;
}

//리스트가 비어있으면 1을 반환, 그렇지 않으면 0을 반환
int is_empty(ArrayListType *L)
{
    return L->size == 0;
}

//리스트가 가득 차있으면 1을 반환, 그렇지 않으면 1을 반환
int is_full(ArrayListType *L)
{
    return L->size == MAX_LIST_SIZE;
}

// pos 위치에 있는 원소를 반환하는 함수
element_get_entry(ArrayListType *L, int pos)    
{
    if(pos < 0 || pos >= L->size)   // pos 가 0과 size 사이 밖에 있으면
        error("위치 오류");
    return L->array[pos];
}

// 리스트 출력
void print_list(ArrayListType *L)
{
    int i;
    for(i = 0 ; i < L->size ; i++)
        printf("%d->", L->array[i]);
    printf("\n");
}

// 리스트의 맨끝에 항목을 추가하는 함수
void insert_last(ArrayListType *L, element item)    
{
    if(L->size >= MAX_LIST_SIZE)    // size가 MAX_LIST_SIZE 보다 크면 오버플로우
        error("리스트 오버플로우");
    L->array[L->size++] = item; // size 위치에 item을 저장하고 size 에 1을 더함
}

// pos 위치에 삽입하는 함수
void insert(ArrayListType *L, int pos, element item)    
{
    if (!is_full(L) && (pos >= 0) && (pos <= L->size))   // 리스트가 꽉찻거나 위치를 벗어나지 않으면
    {
        for (int i = (L->size -1) ; i >= pos ; i--) // 맨끝에 원소부터 pos 까지 오른쪽으로 한칸씩 이동
            L->array[i+1] = L->array[i];
        L->array[pos] = item;   // 원소들이 한칸 씩 이동하여 비어진 pos 에 item 대입
        L->size++;  // size + 1 
    }   
}

// pos 위치에 항목을 삭제하는 함수
element delete(ArrayListType *L, int pos)
{
    element item;

    if (pos < 0 || pos >= L->size)
        error("위치 오류");
    item = L->array[pos];   // 삭제할 원소를 반환하기위해 저장
    for (int i = pos ; i < (L->size -1) ; i++)  // pos 부터 맨 끝에 원소까지 한칸씩 왼쪽으로 이동
        L->array[i] = L->array[i+1];
    L->size--;
    return item;    // 삭제한 원소 반환
}

int main(void)
{
    ArrayListType list;

    init(&list);
    insert(&list, 0, 10); print_list(&list); // 0번쨰 위치에 10 추가하고 출력
    insert(&list, 0, 20); print_list(&list); // 0번쨰 위치에 20 추가하고 출력
    insert(&list, 0, 30); print_list(&list); // 0번쨰 위치에 30 추가하고 출력
    insert_last(&list, 40); print_list(&list);  // 맨 끝에 40을 추가하고 출력
    delete(&list, 0);   print_list(&list);  // 0번쨰 항목 삭제하고 출력
    return 0;
}