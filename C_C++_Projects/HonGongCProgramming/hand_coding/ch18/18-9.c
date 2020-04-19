// �پ��� �ڷ����� ���Ŀ� �°� ���, fscanf fprintf : �پ��� ���¸� ����� �� �� �ִ� (���ڿ� -> ���ں�ȯ���)

#include <stdio.h>

int main(void)
{
    FILE *ifp, *ofp;
    char name[20];
    int kor, eng, math;
    int total;
    double avg;
    int res;        // fscanf �Լ��� ��ȯ �� ����

    ifp = fopen("data\\Stud_grade.txt", "r");      // �Է� ������ �б� �������� ���� 
    if (ifp == NULL)
    {
        printf("�Է� ������ ���� ���߽��Ѵ�...\n");
        return 1;
    }

    ofp = fopen("data\\Stud_grade_avg.txt", "w");
    if (ofp == NULL)
    {
        printf("��� ������ ���� ���߽��ϴ�...\n");
        return 1;
    }

    while(1)
    {
        res = fscanf(ifp, "%s%d%d%d", name, &kor, &eng, &math);         // format is exhuasted �ɋ� EOF ��ȯ -> �� ������ ��� �����ϸ� ��ȯ �Ѵٴ� ��? 
        if (res == EOF)         // ������ �����͸� ��� ������ EOF ��ȯ
        {
            break;
        }
        total = kor + eng + math;
        avg = total / 3.0;   // ��� ���
        fprintf(ofp, "%s%5d%7.1lf\n", name, total, avg);     // �̸� ���� ��� ���
    }

    fclose(ifp);
    fclose(ofp);

    return 0;
}