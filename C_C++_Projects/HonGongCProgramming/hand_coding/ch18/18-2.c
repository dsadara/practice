// ������ ������ ȭ�鿡 ����ϱ� fgetc ���

#include <stdio.h>

int main(void)
{
    FILE *fp;
    int ch;

    fp = fopen("data\\a.txt", "r");
    if (fp == NULL)
    {
        printf("������ ������ �ʾҽ��ϴ�...\n");
        return 1;
    }

    while (1)
    {
        ch = fgetc(fp); // ������ ���Ͽ��� ���� �Է�
        if (ch == EOF)  // �Լ��� ��ȯ���� EOF�� �Է�����
        {
            break;
        }
        putchar(ch);    // �Է��� ���ڸ� ȭ�鿡 ���
    }

    fclose(fp);         // ���� ����

    return 0;
}