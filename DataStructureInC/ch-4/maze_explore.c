// 미로 탐색 프로그램
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAZE_SIZE 6

// 스택 코드 추가
#define MAX_STACK_SIZE 100

typedef struct
{                   // 교체!
    short r;
    short c;
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
// 스택 코드 끝

element here = {1, 0}, entry = {1, 0};

char maze[MAZE_SIZE][MAZE_SIZE] = {
    {'1', '1', '1', '1', '1', '1'},
    {'e', '0', '1', '0', '0', '1'},
    {'1', '0', '0', '0', '1', '1'},
    {'1', '0', '1', '0', '1', '1'},
    {'1', '0', '1', '0', '0', 'x'},
    {'1', '1', '1', '1', '1', '1'},
};
//위치를 스택에 삽입
void push_loc(Stacktype *s, int r, int c)
{
    if (r < 0 || c < 0) return;
    if (maze[r][c])
}