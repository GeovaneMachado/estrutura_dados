#include<stdio.h>
#define LINHAS 4
#define COLUNAS 4
int main()
{
    int matriz[LINHAS][COLUNAS];
	int i,j, maior = 0, linha, coluna, posicaoL, posicaoC;
	for (i=0; i<LINHAS; i++)
    { //linhas
        linha = i;
		for (j=0; j<COLUNAS; j++)
        { //colunas
            coluna = j;
			scanf("%d", &matriz[i][j]);
            if(matriz[i][j] > maior)
            {
                maior = matriz[i][j];
                posicaoL = linha;
                posicaoC = coluna;
            }
        }
	}
    printf("%i esta na linha %i e coluna %i", maior, posicaoL, posicaoC);
    return 0;
}