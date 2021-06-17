#include <stdio.h>
 
int main()
{
    int A, B, C, D, DIFERENCA;
    scanf("%i\n%i\n%i\n%i", &A,&B,&C,&D);
    DIFERENCA = A * B - C * D;
    printf("DIFERENCA = %i\n", DIFERENCA);
    return 0;
}