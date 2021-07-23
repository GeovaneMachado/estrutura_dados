#include<stdio.h>

int exp(int b, int e)
{
    if(e == 0)
        return 1;
    else
        return b*exp(b, e-1);
}
/*
int main()
{
    int e, b, res;
    scanf("%i %i", &b, &e);
    res = exp(b, e);
    printf("%i", res);
    return 0;
}*/

int mdc(int m, int n)
{
    if(n == 0) return m;
    else return mdc(n, m%n);
}
int main()
{
    int n, m;
    scanf("%i %i", &n, &m);
    printf("%i\n", mdc(m, n));
    return 0;
}