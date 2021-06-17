#include<stdio.h>
int main()
{
    float A, B, C, media;
    scanf("%f\n%f\n%f", &A, &B, &C);
    media = (A * 0.2 + B * 0.3 + C * 0.5);
    printf("MEDIA = %.1f\n", media);
    return 0;
}