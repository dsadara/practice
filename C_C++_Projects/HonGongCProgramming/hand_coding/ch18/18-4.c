// �⺻������ ����Ǵ� ǥ�� ����� ��Ʈ���� ����� ���ڿ� �Է�
#include <stdio.h>

int main(void)
{
    int ch;         // �Է��� ���ڸ� ������ ����

    while(1)
    {
        ch = getchar();     // Ű���忡��  �����Է�(ǥ���Է½�Ʈ�� stdin ��� -> Ű���忬��)
        if(ch == EOF)       // ctrl + z �� �Է�����
        {
            break;
        }
        putchar(ch);        // ȭ�鿡 ���� ���(ǥ����½�Ʈ�� stdout ��� -> ����Ϳ���)
    }

    return 0;
}
