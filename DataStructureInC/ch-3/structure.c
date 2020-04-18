#include <stdio.h>
#include <math.h>
typedef struct Point {
    int x;
    int y;
} point;

double get_distance(point p1, point p2)
{
    double res;
    int a = (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
    printf("%d\n", a);
    res = sqrt(a);
    return res;
}

int main(void)
{
    point p1;
    point p2;
    double distance;
    printf("p1의 좌표 입력 : ");
    scanf("%d%d", &p1.x, &p1.y);
    printf("p2의 좌표 입력 : ");
    scanf("%d%d", &p2.x, &p2.y);
    distance = get_distance(p1, p2);
    printf("%.9lf", distance);
    return 0;
}