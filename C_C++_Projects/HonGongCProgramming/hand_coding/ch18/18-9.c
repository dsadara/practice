// 다양한 자료형을 형식에 맞게 출력, fscanf fprintf : 다양한 형태를 입출력 할 수 있다 (문자열 -> 숫자변환등등)

#include <stdio.h>

int main(void)
{
    FILE *ifp, *ofp;
    char name[20];
    int kor, eng, math;
    int total;
    double avg;
    int res;        // fscanf 함수의 반환 값 저장

    ifp = fopen("data\\Stud_grade.txt", "r");      // 입력 파일을 읽기 전용으로 개방 
    if (ifp == NULL)
    {
        printf("입력 파일을 열지 못했습닌다...\n");
        return 1;
    }

    ofp = fopen("data\\Stud_grade_avg.txt", "w");
    if (ofp == NULL)
    {
        printf("출력 파일을 열지 못했습니다...\n");
        return 1;
    }

    while(1)
    {
        res = fscanf(ifp, "%s%d%d%d", name, &kor, &eng, &math);         // format is exhuasted 될떄 EOF 반환 -> 각 변수에 모두 대입하면 반환 한다는 뜻? 
        if (res == EOF)         // 파일의 데이터를 모두 읽으면 EOF 반환
        {
            break;
        }
        total = kor + eng + math;
        avg = total / 3.0;   // 평균 계산
        fprintf(ofp, "%s%5d%7.1lf\n", name, total, avg);     // 이름 총점 평균 출력
    }

    fclose(ifp);
    fclose(ofp);

    return 0;
}