#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
typedef struct aluno
{
    char nome[20];
    float nota[3];
} estudante;

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    int k, i;
    FILE *alunos;
    alunos = fopen("Alunos.txt", "w");
    printf("Quantos alunos deseja inserir dados?\n");
    scanf("%d", &k);

    estudante *aluno = (estudante *)malloc(k * sizeof(estudante));

    if (aluno == NULL)
    {
        printf("Erro na alocação.\n");
        return 1;
    }

    for (i = 0; i < k; i++)
    {
        printf("Digite o nome do aluno %d: \n", i + 1);
        scanf(" %[^\n]", aluno[i].nome);
        printf("Digite a nota 1: \n ");
        scanf("%f", &aluno[i].nota[0]);
        printf("Digite a nota 2: \n");
        scanf("%f", &aluno[i].nota[1]);
        printf("Digite a nota 3: \n");
        scanf("%f", &aluno[i].nota[2]);
    }
    for (i = 0; i < k; i++){
        fprintf(alunos, " \n Nome: %s \n Notas: %.1f\t %.1f\t %.1f", aluno[i].nome, aluno[i].nota[0], aluno[i].nota[1], aluno[i].nota[2]);
    }

    free(aluno);
    fclose(alunos);
    return 0;
}
