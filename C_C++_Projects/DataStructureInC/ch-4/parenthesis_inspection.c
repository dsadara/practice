/* 괄호 검사 프로그램 : 스택을 이용 -> 왼쪽 괄호들을 만나면 계속 삽입하다가 오른쪽 괄호들이
나오면 스택에서 가장 최근의 왼쪽괄호를 꺼내여 타입을 맞추어 보면 괄호의 오류를 검사할 수 있음
(스택은 항상 최근에 삽입한 것이 먼저 필요한 경우에 유용함)
※ 괄호의 조건
1. 왼쪽 괄호의 개수와 오른쪽 괄호의 개수가 같아야 한다
2. 같은 종류의 괄호에서 왼쪽 괄호는 오른쪽 괄호보다 먼저 나와야 한다
3. 서로 다른 종류의 왼쪽 괄호와 오른쪽 괄호 쌍은 서로 교차하면 안된다
ex) ( { ) }
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "normal_stack_charVer.h"   
// 현재 소스 파일과 같은 경로에 있는 normal_stack.c 파일을 포함한다
// ""../normal_stack.c" 현재 소스 파일의 경로에서 상위 디렉토리에 있는 normal_stack.c파일을 포함한다
#define Max_STACK_SIZE 100

int check_matching(const char *in);

int main(void)
{
    char *p = "{ A[(i+1)]=0; }";
    if (check_matching(p) == 1)
        printf("%s 괄호검사성공\n", p);
    else
        printf("%s 괄호검사실패\n", p);
    return 0;
    
}

int check_matching(const char *in)  // const 가 붙여진 변수는 값과 주소값을 변경할 수 없다
{
    Stacktype s;
    char ch, open_ch;
    int i, n = strlen(in); // n 문자열의 길이 
    init_stack(&s); // 스택의 초기화

    for( i = 0 ; i < n ; i++)
    {
        ch = in[i]; // ch = 다음문자
        switch(ch) 
        {
        case '(': case '[': case '{':
            push(&s, ch);
            break;
        case ')': case ']': case '}':
            if (is_empty(&s)) return 0;     // 조건1, 조건2 위배
            else
            {
                open_ch = pop(&s);
                if ((open_ch == '(' && ch != ')') ||
                    (open_ch == '[' && ch != ']') ||
                    (open_ch == '{' && ch != '}'))
                    return 0;
                break;
            }
            

        }
    }
    if (!is_empty(&s)) return 0; // 스택에 남아있으면 오류
    return 1;
}