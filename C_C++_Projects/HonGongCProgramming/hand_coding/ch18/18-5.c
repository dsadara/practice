// stdin�� stdout�� ����� ���� �����

#include <stdio.h>

int main(void)
{
    int ch; // �Է��� ���ڸ� ������ ����
    while(1)
    {
        ch = fgetc(stdin);
        if (ch == EOF)
        {
            break;
        }
        fputc(ch, stdout);
    }

    return 0;
}