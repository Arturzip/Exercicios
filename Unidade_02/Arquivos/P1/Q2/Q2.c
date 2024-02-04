#include <stdio.h>

int main(void)
{
    FILE *entrada, *saida;
    int vetor[10];
    int i, maior, menor;
    float media;
    printf("Abrindo arquivos...\n");

    entrada = fopen("entrada_q2.txt", "r");
    saida = fopen("saida_q2.txt", "w");

    printf("Lendo arquivo...\n");
    for (i = 0; i < 10; i++)
    {
        fscanf(entrada, "%d\n", &vetor[i]);
    }

    printf("Processando...\n");
    menor = vetor[0];
    maior = vetor[0];

    for (i = 0; i < 10; i++)
    {
        if (vetor[i] < menor)
        {
            menor = vetor[i];
        }
        if (vetor[i] > maior)
        {
            maior = vetor[i];
        }
    }
    media = 0;
    for (i = 0; i < 10; i++)
    {
        media = media + vetor[i];
    }
    media = media / 10;

    printf("Escrevendo...\n");

    fprintf(saida, "Maior elemento: %d\n", maior);
    fprintf(saida, "Menor elemento: %d\n", menor);
    fprintf(saida, "Média: %.2f\n", media);

    printf("Fim!");
    fclose(entrada);
    fclose(saida);
    return 0;
}