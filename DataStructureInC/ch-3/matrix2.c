// 희소행렬 표현방법#2 : 0 이 아닌 항만 표현 
// 0이 아닌 항만  열의 값이 각각 (행, 열, 값) 인 행렬
/* ex)  행 열 값                 방법#1 : 3X3 행렬
    0    0  0  2                 2  3  0
    1    0  1  3                 8  9  1
    2    1  0  8     =>          7  0  5
    3    1  1  9
    4    1  2  1
    5    2  0  7
    6    2  2  5

방법#2로 구현한 전치행렬 알고리즘(3.1)
새로운 구조체 b를 생성
구조체 a에 저장된 모든 요소에 대하여 다음을 반복
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
    int rows;   // 행의 개수
    int cols;   // 열의 개수
    int terms;  // 항의 개수
} SparseMatrix;

SparseMatrix matrix_transpose2(SparseMatrix a);
SparseMatrix matrix_transpose2_simple(SparseMatrix a);
void matrix_print(SparseMatrix a);

int main(void)
{
    SparseMatrix m = {
        {{0, 3, 7}, {1, 0, 9}, {1, 5, 8}, {3, 0, 6}, {3, 1, 5}, {4, 5, 1}, {5, 2, 2}},
        6,      //행의 개수
        6,      //열의 개수
        7,      //항의 개수
    };
    SparseMatrix result, result2;

    result = matrix_transpose2(m);
    printf("예제의 반복문으로 출력 : \n");
    matrix_print(result);
    result2 = matrix_transpose2_simple(m);
    printf("간단스한 반복문으로 출력 : \n");
    matrix_print(result2);
    return 0;
}

SparseMatrix matrix_transpose2(SparseMatrix a)
{
    SparseMatrix b;

    int bindex;     // 행렬 b에서 현재 저장 위치
    b.rows = a.rows;
    b.cols = a.cols;    // 행과 열의 크기가 다른 행렬도 전치가 될까?
    b.terms = a.terms;

    if(a.terms > 0) {
        bindex = 0;
        for (int c = 0; c < a.cols ; c++) {            //방법#2로 나타넨 행렬의 항 중에서 열(col)의 오름차순 순으로 각각 행과열을 SWAP
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

    int bindex;     // 행렬 b에서 현재 저장 위치
    b.rows = a.rows;
    b.cols = a.cols;    // 행과 열의 크기가 다른 행렬도 전치가 될까? -> 된다 SparseMatrix m 도 행과 열의 크기가 다른 행렬임
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