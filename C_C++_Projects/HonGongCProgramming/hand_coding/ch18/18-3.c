// ���ڿ��� �� ���ھ� ���Ϸ� ����ϱ� ���� ��� �Լ� fputc ��� 

#include <stdio.h>

int main(void)
{
    FILE *fp;               //���������ͼ���
    char str[] = "banana";    //����ҹ��ڿ�
    int i;

    fp = fopen("data\\b.txt", "w");     //��� ��Ʈ�� ����? 
    if(fp == NULL)
    {
        printf("������ ������ ���߽��ϴ�\n");
        return 1;
    }

    i = 0;
    while(str[i] != '\0')
    {
        fputc(str[i], fp);
        i++;
    }
    fputc('\n', fp);
    fclose(fp);                         //�� ���� �ݱ�

    return 0; 
}