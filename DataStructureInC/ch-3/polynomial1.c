// ���׽� ���� ���α׷� #1

#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101

typedef struct {                                // ����ü �̸��� �����ص� �ǳ�����?
    int degree; // ���׽��� ����
    float coef[MAX_DEGREE];  // ���׽��� ����
} polynomial;

// C = A + B ���⼭ A�� B�� ���׽��̴�. ����ü�� ��ȯ��
polynomial poly_add1(polynomial A, polynomial B)
{
    polynomial C;       // ��� ���׽�
    int Apos = 0, Bpos = 0, Cpos = 0;   // �迭 �ε��� ����
    int degree_a = A.degree;            // ���׽� ����ü�� ������ �״�� �����ϱ����� �� �Լ� �ȿ��� ������ ���� ����
    int degree_b = B.degree;
    C.degree = MAX(A.degree, B.degree);

    while (Apos <= A.degree && Bpos <= B.degree) {
        if(degree_a > degree_b)     // a�� ������ b���� ũ��
        {
           C.coef[Cpos++] = A.coef[Apos++]; //C�� A�� ���� ��ġ(�迭�ε���)�� ������Ű�鼭 C���ٰ� A�� �ִ������� ����� ����(�ִ������� ����� 0�̾ C���ٰ� 0�� ������ ���� �ִ�)
           degree_a--;      // A�� �ִ� ����� C�� ����־����� a�� ������ �پ��
        }
        else if (degree_a == degree_b) {    // A�� == B��
            C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];  // A�װ� B���� ����� ���ؼ� C���� ����
            degree_a--; degree_b--; //A�� B�� ���� �پ��            
        }
        else {
            C.coef[Cpos++] = B.coef[Bpos++];
            degree_b--;
        }
    }
    return C; // ���׽� ����ü C ��ȯ
}

void print_poly(polynomial p)
{
    for (int i = p.degree ; i > 0 ; i--)
    {
        if(p.coef[p.degree - i] == 0)       // ����� 0�� �� ��¹���
            continue;
        printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
    }
    printf("%3.1f \n", p.coef[p.degree]);   // ����� ���
}

// ���Լ�
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