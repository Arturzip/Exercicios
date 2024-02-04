#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j, aluno, numerodequestoes, total_alunos = 10, aprovados = 0;
    printf("Digite a quantidade de questões da prova: \n");
    scanf("%d", &numerodequestoes);
    char **prova = (char **)malloc(numerodequestoes * sizeof(char *));
    char **resposta = (char **)malloc(total_alunos * sizeof(char *));
    float *notas = (float *)malloc(total_alunos * sizeof(float));
    if (prova != NULL && resposta != NULL && notas != NULL)
    {
        for (i = 0; i < numerodequestoes; i++)
        {
            prova[i] = (char *)malloc(5 * sizeof(char));
            if (prova[i] != NULL)
            {
                printf("Digite o gabarito da %d questão (em letra maiúscula)\n", i + 1);
                scanf(" %c", prova[i]);
            }
            else
            {
                exit(1);
            }
        }
        for (aluno = 0; aluno < total_alunos; aluno++)
        {
            resposta[aluno] = (char *)malloc(2 * sizeof(char));
            if (resposta[aluno] == NULL)
            {
                exit(1);
            }
            printf("\nIniciando prova para o Aluno %d\n", aluno + 1);
            for (j = 0; j < numerodequestoes; j++)
            {
                printf("Digite sua resposta para a questão %d \n", j);
                scanf(" %c", &resposta[aluno][j]);
            }
            for (j = 0; j < numerodequestoes; j++)
            {
                if (resposta[aluno][j] == *prova[j])
                {
                    notas[aluno] += 10.0 / numerodequestoes;
                }
            }
            if (notas[aluno] >= 6)
            {
                aprovados++;
            }
        }
    }
    else
    {
        exit(1);
    }
    printf("\nNotas dos alunos:\n");
    for (aluno = 0; aluno < total_alunos; aluno++)
    {
        printf("Nota do aluno %d: %.2f\n", aluno + 1, notas[aluno]);
    }
    printf("Porcentagem de aprovação: %.2f%%\n", (aprovados / 10.0) * 100);
    for (i = 0; i < numerodequestoes; i++)
    {
        free(prova[i]);
    }
    for (aluno = 0; aluno < total_alunos; aluno++)
    {
        free(resposta[aluno]);
    }
    free(prova);
    free(resposta);
    free(notas);
    return 0;
}
