// #if #ifdef #else #endif�� ����� ���Ǻ� ������

#include <stdio.h>
#define VER 7   // ġȯ�� �κ��� �ִ� ��ũ�θ� ����
#define BIT16   // ġȯ�� �κ��� ���� ��ũ�θ� ����

int main(void)
{
    int max;

#if VER >= 6    // ��ũ�θ� VER�� 6�̻��̸�
        printf("���� %d �Դϴ�\n", VER);    // �� ���� ������
        printf("���� %d �Դϴ�\n", 7);
#endif          // if �� ��

#ifdef BIT16    // ��ũ�θ� BIT16�� ���ǵǾ� ������
    max = 32767;    // �� ���� ������
#else
    max = 2147483647;
#endif
    printf("int�� ������ �ִ� : %d\n", max);  // max ���
    return 0;
}