// 배열로 구현한 리스트
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    if(L->size == 0)
        printf("List is empty");
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

// 첫번째 위치에 원소를 삽입하는 함수 
void insert_first(ArrayListType *L, element item)
{
    if (L->size >= MAX_LIST_SIZE)
        error("리스트 오버플로우");
    for (int i = (L->size - 1) ; i >= 0 ; i-- ) // 첫번째 원소부터 마지막 원소까지 오른쪽으로 한 칸씩 이동
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
        error("삭제할 리스트가 없습니다");
        return;
    }
    /*
    for( int i = 0 ; i < size - 1 ; i++)
    {
        l->array[i] = NULL;    // int 에 NULL 을대입하면 변수에 주소값 0 을 넣는것과 같다고 한다
    }
    */
   //memset(l->array, 0, sizeof(int) * size); 그냥 size 만 0을 만들어도 리스트는 비어있는 상태가 된다 
    l->size = 0;    // 리스트에 원소가 없으므로 size에 0을 저장
}

void replace(ArrayListType *l, int pos, element item)
{
    if(pos < 0 || pos > l->size - 1)
    {
        error("위치 오류");
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
    printf("리스트 0 번쨰 위치에 10 추가 \n");
    insert_first(&list, 10); print_list(&list); // 0번쨰 위치에 10 추가하고 출력
    printf("리스트 0 번쨰 위치에 20 추가 \n");
    insert_first(&list, 20); print_list(&list); // 0번쨰 위치에 20 추가하고 출력
    printf("리스트 0 번쨰 위치에 30 추가 \n");
    insert_first(&list, 30); print_list(&list); // 0번쨰 위치에 30 추가하고 출력
    printf("리스트 맨 끝에 40 추가 \n");
    insert_last(&list, 40); print_list(&list);  // 맨 끝에 40을 추가하고 출력
    printf("0번째 항목 삭제\n");
    delete(&list, 0);   print_list(&list);  // 0번쨰 항목 삭제하고 출력
    printf("0번째 원소를 30으로 대체 \n");
    replace(&list, 0, 30);  print_list(&list);  // 0 번째 원소를 30으로 대체
    printf("리스트 길이 : %d\n", get_length(&list));
    printf("리스트 비우기 \n");
    clear(&list);   print_list(&list);
    return 0;
}