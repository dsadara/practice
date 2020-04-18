// 다항식 덧셈 프로그램 #1

#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101

typedef struct {                                // 구조체 이름은 생략해도 되나보지?
    int degree; // 다항식의 차수
    float coef[MAX_DEGREE];  // 다항식의 개수
} polynomial;

// C = A + B 여기서 A와 B는 다항식이다. 구조체가 반환됨
polynomial poly_add1(polynomial A, polynomial B)
{
    polynomial C;       // 결과 다항식
    int Apos = 0, Bpos = 0, Cpos = 0;   // 배열 인덱스 변수
    int degree_a = A.degree;            // 다항식 구조체에 차수는 그대로 보존하기위해 이 함수 안에서 차수를 따로 선언
    int degree_b = B.degree;
    C.degree = MAX(A.degree, B.degree);

    while (Apos <= A.degree && Bpos <= B.degree) {
        if(degree_a > degree_b)     // a의 차수가 b보다 크면
        {
           C.coef[Cpos++] = A.coef[Apos++]; //C와 A의 현재 위치(배열인덱스)를 증가시키면서 C에다가 A의 최대차수의 계수를 대입(최대차수의 계수가 0이어서 C에다가 0을 대입할 수도 있다)
           degree_a--;      // A의 최대 계수를 C에 집어넣었으니 a의 차수가 줄어듦
        }
        else if (degree_a == degree_b) {    // A항 == B항
            C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];  // A항과 B항의 계수를 더해서 C에다 대입
            degree_a--; degree_b--; //A와 B의 차수 줄어듦            
        }
        else {
            C.coef[Cpos++] = B.coef[Bpos++];
            degree_b--;
        }
    }
    return C; // 다항식 구조체 C 반환
}

void print_poly(polynomial p)
{
    for (int i = p.degree ; i > 0 ; i--)
    {
        if(p.coef[p.degree - i] == 0)       // 계수가 0인 항 출력방지
            continue;
        printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
    }
    printf("%3.1f \n", p.coef[p.degree]);   // 상수항 출력
}

// 주함수
int main(void)
{
    polynomial a = {3, {1, 0, 2, 3}};
    polynomial b = {3, {-1, 0, 4, -1}};
    polynomial c;

    print_poly(a);
    print_poly(b);
    c = poly_add1(a,b);
    printf("---------------------------------------------------------------\n");
    print_poly(c);
    return 0; 
}