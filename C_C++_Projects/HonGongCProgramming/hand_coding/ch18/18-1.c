// ������ ���� �ݴ� ���α׷�
#include <stdio.h>

int main(void)
{
    FILE *fp;       // ���� ������

    fp = fopen("C:\\Users\\catnoir\\Desktop\\C_C++_Projects\\HongGongC\\hand_coding\\ch18\\data\\a.txt", "r");       // a.txt ������ �б� �������� ����
    printf("��ø�...");
    if (fp == NULL)
    {
        printf("������ ������ �ʾҽ��ϴ�\n");
        return 1; 
    }
    printf("������ ���Ƚ��ϴ�\n");
    fclose(fp);


    return 0;
}
