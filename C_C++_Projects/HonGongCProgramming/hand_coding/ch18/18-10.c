// ��Ʈ�� ������ ���� ���� ������ fflush �Լ� -> ����� �Լ����� ���۸� �����ϸ� ������ �߻� 
// fscanf �Լ��� ���� ���ڸ� ���ۿ� ���� ���Ƽ� ����� ���� -> fgets �Լ��� ���� ���ڰ� ���Ë����� ���ڿ��� �Է� 

#include <stdio.h>

int main(void)
{
    FILE *fp;       // ���� ������
    int age;        // ���� ���� ����
    char name[20];  // �̸� ���� �迭

    fp = fopen("data\\b.txt", "r");

    fscanf(fp, "%d", &age);     // ���� �Է�
    while(fgetc(fp) != '\n'){}            
    fgets(name, sizeof(name), fp);  // �̸� �Է�

    printf("���� : %d, �̸� : %s", age, name);      // �Է� ������ ���
    fclose(fp);     // ���� ����

    return 0;
}