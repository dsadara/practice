// chapter 17 도전 실전예제

#include <stdio.h>
#include <stdlib.h>

struct student
{
    int stunum;
    char name[20];
    int Kor;
    int Eng;
    int Math;
    int total;
    double avg;
    char grade;
};


void print_data(struct student *a);
void sort_by_total(struct student *b);
void swap_struct(struct student *A, struct student *B);


int main()
{
    int i;
    struct student s[5] = { 0 };
    for ( i = 0 ; i < 5 ; i++)
    {
        printf("stud num : "); scanf("%d", &s[i].stunum);
        printf("stud name : "); scanf("%s", s[i].name);
        printf("Kor, Eng, Math scores : "); scanf("%d%d%d", &s[i].Kor, &s[i].Eng, &s[i].Math);
        s[i].total = s[i].Kor + s[i].Eng + s[i].Math;
        s[i].avg = (double)(s[i].total) / 3.0;
        if(s[i].avg >= 90)
            s[i].grade = 'A';
        else if(s[i].avg >= 80)
            s[i].grade = 'B';
        else if(s[i].avg >= 70)
            s[i].grade = 'C';
        else 
            s[i].grade = 'F';
    }
    printf("#Raw data...");
    print_data(s);
    sort_by_total(s);
    printf("Sorted data...");
    print_data(s);

    return 0;
}

void sort_by_total(struct student *b)
{
    int i, j;

    for( i = 0 ; i < 5 ; i++)
    {
        for( j = i + 1 ; j < 5 ; j++)
        {
            if(b[i].total < b[j].total)
                swap_struct(b+i, b+j);
        }
    }

}

void swap_struct(struct student *A, struct student *B)
{
    struct student tmp = { 0 };
    tmp = *A;
    *A = *B;
    *B = tmp;
}

void print_data(struct student *a)
{
    for(int i = 0 ; i < 5 ; i++)
    {
        printf("%5d%5s%5d%5d%5d%5.1lf%5c", a[i].stunum, a[i].name, a[i].Kor, a[i].Eng, a[i].Math, a[i].avg, a[i].grade);
        printf("\n");
    }
}