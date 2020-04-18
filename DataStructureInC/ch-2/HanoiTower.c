#include <stdio.h>

void hanoi_tower(int n, char from, char tmp, char to)
{
    if (n==1) printf("���� 1�� %c ���� %c���� �ű��\n", from, to);
    else {
        hanoi_tower(n-1, from, to , tmp);                           // ���� n-1 ���� ������ 2�����뿡 �ű���
        printf("���� %d�� %c���� %c���� �ű��.\n", n, from, to);     // n �������� 3���������� �ű��
        hanoi_tower(n-1, tmp, from, to);                            // �״��� 2�����뿡 �ִ� n-1���� ������ 3���������� �ű��     
    }
}

int main(void)
{
    hanoi_tower(4, 'A', 'B', 'C');
    return 0; 
}