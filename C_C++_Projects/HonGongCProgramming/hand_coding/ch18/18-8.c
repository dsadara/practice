// ���� ���� ������ �Է��Ͽ� �� �ٷ� ���, fgets fputs �� �پ� �����

#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *ifp, *ofp;        // ���� ������ ���� 
    char str[80];           // �Է��� ���ڿ��� ������ ���迭
    char *res;              // fgets �Լ��� ��ȯ���� ������ ����

    ifp = fopen("a.txt", "r");      // �Է� ������ �б� �������� ����
    if (ifp == NULL)
    {
        printf("�Է� ������ ���� ���߽��ϴ�...\n");
        return 1;
    }

    ofp = fopen("b.txt", "w");      // ��� ������ ���� �������� ����
    if (ofp == NULL)        // ���� ���� Ȯ��
    {
        printf("��� ������ ���� ���߽��ϴ�\n");
        return 1; 
    }

    while(1)        // ���ڿ��� �Է��ϰ� ����ϴ� ���� �ݺ�
    {
        res = fgets(str, sizeof(str), ifp);
        if(res == NULL)     // ��ȯ���� �� �����͸� �ݺ� ����, End Of File �ƴϸ� error �ϋ� fgets �Լ��� NULL�� ��ȯ�Ѵ� 
        {
            break;
        }
        str[strlen(str) - 1] = '\0';    // ���� ���� ���� 
        fputs(str, ofp);
        fputs(" ", ofp); 
    }

    fclose(ifp);
    fclose(ofp);

    return 0; 
}