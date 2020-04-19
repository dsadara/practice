#include <stdio.h>


int total(int kor, int eng, int mat);
double average(int tot);
void print_title(void);

int main(void)
{
    double avg;
    int Kor, Eng, Math, tot;
    printf("# 세 과목의 점수 입력 : ");
    scanf("%d%d%d", &Kor, &Eng, &Math);
    tot = total(Kor, Eng, Math);
    avg = average(tot);
    print_title();
    printf("%10d%10d%10d%10d%10.1lf", Kor, Eng, Math, tot, avg);
    return 0;
}

int total(int kor, int eng, int mat)
{
    return kor + eng + mat;
}

double average(int tot)
{
    return (double) tot / 3.0;
}

void print_title(void)
{
    
    printf("                   =====<성적표>=====                  \n\n"); 
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("      국어      영어      수학      총점      평균      \n"); 
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n"); 
}