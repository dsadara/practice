// ������ ǥ�����#2 : 0 �� �ƴ� �׸� ǥ�� 
// 0�� �ƴ� �׸�  ���� ���� ���� (��, ��, ��) �� ���
/* ex)  �� �� ��                 ���#1 : 3X3 ���
    0    0  0  2                 2  3  0
    1    0  1  3                 8  9  1
    2    1  0  8     =>          7  0  5
    3    1  1  9
    4    1  2  1
    5    2  0  7
    6    2  2  5

���#2�� ������ ��ġ��� �˰���(3.1)
���ο� ����ü b�� ����
����ü a�� ����� ��� ��ҿ� ���Ͽ� ������ �ݺ�
{
    b.data[bindex].row = a.data[i].col;
    b.data[bindex].col = a.data[i].row;
    b.data[bindex].value = a.data[i].value;
    bindex++
}
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100
typedef struct {
    int row;
    int col;
    int value;
} element;

typedef struct SparseMatrix {
    element data[MAX_TERMS];
    int rows;   // ���� ����
    int cols;   // ���� ����
    int terms;  // ���� ����
} SparseMatrix;

SparseMatrix matrix_transpose2(SparseMatrix a);
SparseMatrix matrix_transpose2_simple(SparseMatrix a);
void matrix_print(SparseMatrix a);

int main(void)
{
    SparseMatrix m = {
        {{0, 3, 7}, {1, 0, 9}, {1, 5, 8}, {3, 0, 6}, {3, 1, 5}, {4, 5, 1}, {5, 2, 2}},
        6,      //���� ����
        6,      //���� ����
        7,      //���� ����
    };
    SparseMatrix result, result2;

    result = matrix_transpose2(m);
    printf("������ �ݺ������� ��� : \n");
    matrix_print(result);
    result2 = matrix_transpose2_simple(m);
    printf("���ܽ��� �ݺ������� ��� : \n");
    matrix_print(result2);
    return 0;
}

SparseMatrix matrix_transpose2(SparseMatrix a)
{
    SparseMatrix b;

    int bindex;     // ��� b���� ���� ���� ��ġ
    b.rows = a.rows;
    b.cols = a.cols;    // ��� ���� ũ�Ⱑ �ٸ� ��ĵ� ��ġ�� �ɱ�?
    b.terms = a.terms;

    if(a.terms > 0) {
        bindex = 0;
        for (int c = 0; c < a.cols ; c++) {            //���#2�� ��Ÿ�� ����� �� �߿��� ��(col)�� �������� ������ ���� ������� SWAP
            for (int i = 0 ; i < a.terms ; i++) {
                if(a.data[i].col == c) {
                    b.data[bindex].row = a.data[i].col;
                    b.data[bindex].col = a.data[i].row;
                    b.data[bindex].value = a.data[i].value;
                    bindex++;
                }
            }
        }
    }
    return b;
}

void matrix_print(SparseMatrix a)
{
    printf("===================\n");
    for( int i = 0 ; i < a.terms ; i++) {
        printf("(%d, %d, %d) \n", a.data[i].row, a.data[i].col, a.data[i].value);
    }
    printf("===================\n");
}

SparseMatrix matrix_transpose2_simple(SparseMatrix a)
{
    SparseMatrix b;

    int bindex;     // ��� b���� ���� ���� ��ġ
    b.rows = a.rows;
    b.cols = a.cols;    // ��� ���� ũ�Ⱑ �ٸ� ��ĵ� ��ġ�� �ɱ�? -> �ȴ� SparseMatrix m �� ��� ���� ũ�Ⱑ �ٸ� �����
    b.terms = a.terms;

    if(a.terms > 0) {
        bindex = 0;
            for (int i = 0 ; i < a.terms ; i++) {
                    b.data[bindex].row = a.data[i].col;
                    b.data[bindex].col = a.data[i].row;
                    b.data[bindex].value = a.data[i].value;
                    bindex++;
            }
    }
    return b;
}