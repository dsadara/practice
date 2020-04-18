// 스택의 요소를 구조체로 하기 
// 스택을 전역변수로 선언 -> 여러 개의 스택을 동시에 사용할 수 없다 
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef struct {
    int student_no;
    char name[MAX_STRING];
    char address[MAX_STRING];
} element;

element stack[MAX_STACK_SIZE];
int top = -1; // 스택에 아무 것도 업을때 top에 -1을 대입

//공백 상태 검출 함수
int is_empty()
{
    return (top == -1); // top이 -1이면(공백이면) 1 반환
}

//포화 상태 검출 함수
int is_full()
{
    return (top == (MAX_STACK_SIZE - 1));   // top이 스택 인덱스 마지막에 있을때 1반환
}

//삽입 함수
void push(element item)
{
    if (is_full())
    {
        fprintf(stderr, "stack overflow\n");
        return;
    }
    else stack[++top] = item; // top을 먼저 증가시키고 그 top의 위치에 item 대입
}

// 삭제 함수
element pop()
{
    if (is_empty())
    {
        fprintf(stderr, "stack empty error\n");
        exit(1);
    }
    else return stack[top--];   // 스택을 비울 필요 없이 top의 값만 내려주면 삭제된걸로 친다
}

element peek()
{
    if (is_empty())
    {
        fprintf(stderr, "stack empty error\n");
        exit(1);
    }
    else return stack[top];
}

int main(void)
{
    element ie = {20190001, "Hong", "Seoul"};
    element oe;

    push(ie);
    oe = pop();


    printf("학번 : %d\n", oe.student_no);
    printf("이름 : %s\n", oe.name);
    printf("주소 : %s\n", oe.address);
    return 0;
}