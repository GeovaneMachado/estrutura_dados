#include<stdio.h>

//Define struct e tipo complexo 
struct Complexo         
{
    double real, imaginario;
};
typedef struct Complexo complexo;

//recebe 3 parametros, um ponteiro e dois doubles
complexo criaComplexo(double r, double imag) 
{
     //Atribui os valores da struct para o ponteiro retornando os valores diretos
    complexo ok;
    ok.real = r;              
    ok.imaginario = imag;    
    return ok;
}
void somaComplexos(complexo *soma, complexo valor1, complexo valor2)
{
    //variaveis para amarzenar os valores e fazer as expressoes
    double real1, imag1, real2, imag2; 
    real1 = valor1.real;
    imag1 = valor1.imaginario;
    real2 = valor2.real;
    imag2 = valor2.imaginario;
    //ponteiro recebe as expressoes
    soma->real = real1 + real2; 
    soma->imaginario = imag1 + imag2;
}
void imprimeComplexo(complexo *soma)
{
    //imprime os dois valores da struct, imaginario imprime co "i" junto
    printf("%.0lf + %.0lfi", soma->real, soma->imaginario); 
}
int main()
{
    //declarando variaveis e ponteiros
    double a=10, b=20;
    complexo cp, *soma, valor1, valor2;
    //chamando a função criaComplexo e imprimindo ela
    cp = criaComplexo(a, b);
    printf("****Cria complexo****\n");
    printf("real: %.2lf\nImaginario: %.2lf\n", cp.real, cp.imaginario);
    //obtendo os valores para aplicar na função somaComplexo
    printf("****Soma complexos****\n");
    printf("Digite primeiro o valor real e depois o valor imaginario: ");
    scanf("%lf %lf", &valor1.real, &valor1.imaginario);

    printf("Digite novamente primeiro o valor real e depois o valor imaginario: ");
    scanf("%lf %lf", &valor2.real, &valor2.imaginario);

    somaComplexos(&soma, valor1, valor2);
    //imprimindo a soma dos valores passados através da função imprimeComplexo
    printf("A soma dos valores sao: \n");
    imprimeComplexo(&soma);
    return 0;
}