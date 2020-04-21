/* 일반적인 스택 프로그램
    stack 배열과 top을 하나의 구조체로 결합시키고
    이 구조체의 포인터를 각 함수로 전달한다
*/
#include <stdio.h>
#include <stdlib.h>

//사후에 스택이 필요하면 여기만 복사하여 붙인다
//========= 스택 코드의 시작 ========
#define MAX_STACK_SIZE 100

typedef struct {
    char alpabet;
    int a_num;
} element;

typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} Stacktype;

// 스택 초기화 함수
void init_stack(Stacktype *s)
{
    s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(Stacktype *s)      // data 배열을 반환할때는 함수의 반환값을 element로 하지만 그게 아니라면 int로 반환한다 
{
    return ((s->top) == -1);    // 연산자 우선순위로 따지면 -> 에 괄호를 안쳐도 되긴함
}

//포화 상태 검출 함수
int is_full(Stacktype *s)
{
    return (s->top == (MAX_STACK_SIZE - 1));    // (MAX_STACK_SIZE - 1)은 인덱스 상 마지막 위치
}

//삽입함수
void push(Stacktype *s, element item)
{
    if(is_full(s))
    {
        fprintf(stderr, "stack overflow\n");
        return;
    }
    else s->data[++(s->top)] = item;    // top을 먼저 증가시키고 item 대입
}

// 삭제함수
element pop(Stacktype *s)
{
    if(is_empty(s))
    {
        fprintf(stderr, "stack empty error\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}
// 피크함수
element peek(Stacktype *s)
{
    if(is_empty(s))
    {
        fprintf(stderr, "stack empty error\n");
        exit(1);
    }
    else return s->data[s->top];
}