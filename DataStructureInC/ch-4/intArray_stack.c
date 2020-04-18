// 정수 배열 스택 프로그램 -> 스택을 전역변수로 구현하는 방법
// 장점 : 간단하고 이해하기쉽다 단점 : 하나의 프로그램에서 여러개의 스택을 동시에 사용하기가 어려움
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100  // 스택의 최대 크기
typedef int element;        // 데이터의 자료형
element stack[MAX_STACK_SIZE];  // 1차원 배열
int top = -1;       // 스택이 비어있을때 top은 -1으로 초기화

// 공백 상태 검출 함수
int is_empty()
{
    return (top == -1); 
}
// 포화 상태 검출 함수
int is_full()
{
    return (top == (MAX_STACK_SIZE - 1));  //스택의 인덱스는 0부터 시작하므로
}
// 삽입 함수
void push(element item)
{
    if (is_full()) {
        fprintf(stderr, "stack overflow\n");
        return;
    }
    else stack[++top] = item;   // top을 먼저 증감시키고 top위치에 item을 대입
}
// 삭제 함수
element pop()
{
    if (is_empty()) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return stack[top--];
}
// 피크 함수
element peek()
{
    if (is_empty())
    {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return stack[top];
}

int main (void)
{
    push(1);
    push(2);
    push(3);
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    return 0;
}