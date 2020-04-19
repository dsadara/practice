// 다항식 덧셈 프로그램 #2
#include <stdio.h>
#include <Stdlib.h>

#define MAX_TERMS 101
typedef struct {
    float coef;             // 왜 float로 선언했는지 이해불가
    int expon;
} polynomial;
polynomial terms[MAX_TERMS] = {{8,3}, {7,1}, {1,0}, {10,3}, {3,2}, {1,0}};   //전역변수로 다항식 선언, terms가 뭐의 줄임말일까?
int avail = 6;      // term[6]부터 다항식 저장가능하다는 뜻

//두개의 정수를 비교
char compare(int a, int b)
{
    if (a>b) return '>';
    else if (a == b) return '=';
    else return '<';
}

//새로운 항을 다항식에 추가
void attach(float coef, int expon)
{
    if (avail > MAX_TERMS)
    {
        fprintf(stderr, "항의 개수가 너무 많음\n");
        exit(1);
    }
    terms[avail].coef = coef;       //
    terms[avail].expon = expon;
    avail++;        //계수와 차수 추가 한후 avail 1증가
}

//C = A + B
//As Ae는 다항식 A의 처음과 마지막을 가리킴(Cs Ce, Bs Be도 마찬가지)
void poly_add2(int As, int Ae, int Bs, int Be, int *Cs, int *Ce)
{
    float tempcoef;
    *Cs = avail;
    while (As <= Ae && Bs <= Be)    //switch 전체가 한문장이여서 중괄호 안해도 될듯
        switch (compare(terms[As].expon, terms[Bs].expon))
        {
        case '>':
            attach(terms[As].coef, terms[As].expon);
            As++; break;
        case '=':
            tempcoef = terms[As].coef - terms[Bs].coef;
            if(tempcoef)    // tempcoef 의 값이 0이 아니라면
            attach(tempcoef, terms[As].expon);
            As++; Bs++; break;
        case '<':
            attach(-(terms[Bs].coef), terms[Bs].expon);
            Bs++; break;
        }
    //A의 나머지 항들을 이동
    for(;As <= Ae; As++)
        attach(terms[As].coef, terms[As].expon);
    for(; Bs <= Be ; Bs++)
        attach(-(terms[Bs].coef), terms[Bs].expon);
    *Ce = avail -1; //avail보다 1만큼앞에 c의 마지막 항이 있다 
}

void print_poly(int s, int e)
{
    for (int i = s; i < e ; i++)
        printf("%4.1fx^%d + ", terms[i].coef, terms[i].expon);
    printf("%4.1fx^%d\n", terms[e].coef, terms[e].expon);   //반복문 안에서 출력을 할 수 있었지만 개행문자를 출력하기위해서 따로 출력
}

int main(void)
{
    int As = 0, Ae = 2, Bs = 3, Be = 5, Cs, Ce;
    poly_add2(As, Ae, Bs, Be, &Cs, &Ce);
    print_poly(As, Ae);
    print_poly(Bs, Be);
    printf("----------------------------------------------------------------------------\n");
    print_poly(Cs, Ce);
    return 0;
}