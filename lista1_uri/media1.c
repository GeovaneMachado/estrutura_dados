#include<stdio.h>
int main()
{
    double A, B, media;
    scanf("%lf\n%lf", &A, &B);
    media = (A * 0.3 + B * 0.7);
    printf("MEDIA = %.5lf\n", media);
    return 0;
}