// 컴파일 시간에 필요한 스택의 크기를 알아내기는 어렵다
// c언어에서는 malloc()을 호출하여서 실행시간에 메모리를 할당 받을 수 있다

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
    element *data;  // data는 포인터로 정의됨(동적할당을위해서)
    int capacity;   // 현재 크기
    int top;
} stacktype;

// 스택 생성 함수
void init_stack(stacktype *s)
{
    s->top = -1;
    s->capacity = 1;    // 일단 크기 1의 배열로 생성
    s->data = (element *)malloc(s->capacity * sizeof(element));
}

// 공백 상태 검출 함수
int is_empty(stacktype *s)
{
    return (s->top == -1);
}

// 포화 상태 검출 함수
int is_full(stacktype *s)
{
    return (s->top == (s->capacity -1));
}
//삽입함수
void push(stacktype *s, element item)
{
    if(is_full(s)) 
    {
        s->capacity *= 2;       // 포화 상태이면 현재 크기를 두배로 늘린다
        s->data = 
            (element *)realloc(s->data, s->capacity * sizeof(element));
    }
    s->data[++(s->top)] = item;     // top을 1을 늘린 후 item을 대입한다
}
// 삭제함수
element pop(stacktype *s)
{
    if(is_empty(s))
    {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

int main(void)
{
    stacktype s;
    init_stack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 4);
    push(&s, 5);
    push(&s, 6);
    push(&s, 7);
    push(&s, 8);
    push(&s, 9);
    push(&s, 10);
    push(&s, 11);
    push(&s, 12);
    push(&s, 13);
    push(&s, 14);
    push(&s, 15);
    push(&s, 16);
    push(&s, 17);
    printf("%d \n", pop(&s));
    printf("%d \n", pop(&s));
    printf("%d \n", pop(&s));
        printf("%d \n", pop(&s));
    printf("%d \n", pop(&s));
    printf("%d \n", pop(&s));
        printf("%d \n", pop(&s));
    printf("%d \n", pop(&s));
    printf("%d \n", pop(&s));
        printf("%d \n", pop(&s));
    printf("%d \n", pop(&s));
    printf("%d \n", pop(&s));
    free(s.data);
    return 0;

}