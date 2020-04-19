#include <stdio.h>
#include <string.h>

void swap(char type[], void *a, void *b);

int main()
{
    int p1_age, p2_age;
    double p1_height, p2_height;

    printf("첫 번째 사람의 나이와 키 입력 : ");
    scanf("%d%ls", &p1_age, &p1_height);
    printf("두 번쨰 사람의 나이와 키 입력 : ");
    scanf("%d%ld", &p2_age, &p2_height);
    swap("int", &p1_age, &p2_age);
    swap("double", &p1_height, &p2_height);
    printf("첫 번째 사람의 나이와 키  : %d, %.1lf\n", p1_age, p1_height);
    printf("두 번째 사람의 나이와 키  : %d, %.1lf\n", p2_age, p2_height);
    return 0;
}

void swap(char type[], void *a, void *b)
{
    if(strcmp(type, "int") == 0)
    {
        int tmp;
        tmp = *(int *)a;
        *(int *)a = *(int *)b;
        *(int *)b = tmp;
    }
    else if (strcmp(type, "double") == 0)
    {
        double tmp;
        tmp = *(double *)a;
        *(double *)a = *(double *)b;
        *(double *)b = tmp;
    };

}
