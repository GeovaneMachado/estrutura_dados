#include<stdio.h>
int main()
{
    double A, B, media;
    scanf("%lf\n%lf", &A, &B);
    media = (A * 0.35 + B * 0.75)/1.1;
    printf("MEDIA = %.5lf\n", media);
    return 0;
}