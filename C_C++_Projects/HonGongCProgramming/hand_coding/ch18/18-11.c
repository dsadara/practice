// fread, fwrite �Լ��� ������� �������� ũ��� ������ �μ��� �� ������ -> ����ü�� �迭�� ���� �����;��� ���� ��쵵 ���Ͽ� ���� ������� �� �ִ�.
// ���� ���ڿ� ���� ������ ��ȯ������ �������� �����Ƿ� ����� ȿ���� ���� �� �ִ�.
// *fprintf �� fread �� ����!!
#include <stdio.h>

int main(void)
{
    FILE *afp, *bfp;
    int num = 10;
    int res;

    afp = fopen("data\\a.txt", "wt");        // �ؽ�Ʈ ���� ��� ���� ����
    fprintf(afp, "%d", num);                // num�� ���� ���ڷ� ��ȯ�Ͽ� ���
    bfp = fopen("data\\b.txt", "wb");       // ���̳ʸ� ���� ��� ���� ���� 
    fwrite(&num, sizeof(num), 1, bfp);      // num �� ���� �״�� ���Ͽ� ��� 

    fclose(afp);
    fclose(bfp);

    bfp = fopen("data\\b.txt", "rb"); // ���̳ʸ� ���� �Է����� ����
    fread(&res, sizeof(res), 1, bfp);
    printf("%d", res);

    fclose(bfp);
    return 0;
}
