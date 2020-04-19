// ���׽� ���� ���α׷� #2
#include <stdio.h>
#include <Stdlib.h>

#define MAX_TERMS 101
typedef struct {
    float coef;             // �� float�� �����ߴ��� ���غҰ�
    int expon;
} polynomial;
polynomial terms[MAX_TERMS] = {{8,3}, {7,1}, {1,0}, {10,3}, {3,2}, {1,0}};   //���������� ���׽� ����, terms�� ���� ���Ӹ��ϱ�?
int avail = 6;      // term[6]���� ���׽� ���尡���ϴٴ� ��

//�ΰ��� ������ ��
char compare(int a, int b)
{
    if (a>b) return '>';
    else if (a == b) return '=';
    else return '<';
}

//���ο� ���� ���׽Ŀ� �߰�
void attach(float coef, int expon)
{
    if (avail > MAX_TERMS)
    {
        fprintf(stderr, "���� ������ �ʹ� ����\n");
        exit(1);
    }
    terms[avail].coef = coef;       //
    terms[avail].expon = expon;
    avail++;        //����� ���� �߰� ���� avail 1����
}

//C = A + B
//As Ae�� ���׽� A�� ó���� �������� ����Ŵ(Cs Ce, Bs Be�� ��������)
void poly_add2(int As, int Ae, int Bs, int Be, int *Cs, int *Ce)
{
    float tempcoef;
    *Cs = avail;
    while (As <= Ae && Bs <= Be)    //switch ��ü�� �ѹ����̿��� �߰�ȣ ���ص� �ɵ�
        switch (compare(terms[As].expon, terms[Bs].expon))
        {
        case '>':
            attach(terms[As].coef, terms[As].expon);
            As++; break;
        case '=':
            tempcoef = terms[As].coef - terms[Bs].coef;
            if(tempcoef)    // tempcoef �� ���� 0�� �ƴ϶��
            attach(tempcoef, terms[As].expon);
            As++; Bs++; break;
        case '<':
            attach(-(terms[Bs].coef), terms[Bs].expon);
            Bs++; break;
        }
    //A�� ������ �׵��� �̵�
    for(;As <= Ae; As++)
        attach(terms[As].coef, terms[As].expon);
    for(; Bs <= Be ; Bs++)
        attach(-(terms[Bs].coef), terms[Bs].expon);
    *Ce = avail -1; //avail���� 1��ŭ�տ� c�� ������ ���� �ִ� 
}

void print_poly(int s, int e)
{
    for (int i = s; i < e ; i++)
        printf("%4.1fx^%d + ", terms[i].coef, terms[i].expon);
    printf("%4.1fx^%d\n", terms[e].coef, terms[e].expon);   //�ݺ��� �ȿ��� ����� �� �� �־����� ���๮�ڸ� ����ϱ����ؼ� ���� ���
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