#include <stdio.h>
#include <stdlib.h>

int main(void)
{   
    //criando ponteiros para os arquivos do comando da questao:
    FILE *entrada, *saida;
    //crianndo as variaveis que armazenarao os valores dos alunos:
    char nome[50];
    float nota1, nota2, nota3, media;

    printf("Iniciando leitura...\n");

    //Abrindo os arquivos e especificando a açao:
    entrada = fopen("entrada_q3.txt", "r");
    saida = fopen("saida_q3.txt", "w");

    // fscanf = uma dad funçoes usadas para ler arquivos
    //nota: fcansf tem a capacidade de ler dados de uma linha separadamente (desde que especificada a estrutura do arquivo)
    //enquando fgets le a linha completa como uma so
    while (fscanf(entrada, "%s\t%f\t%f\t%f", nome, &nota1, &nota2, &nota3) != EOF)
    {
        media = (nota1 + nota2 + nota3) / 3.0;
        fprintf(saida, "%s\t%.2f\t%s\n", nome, media, media >= 7.0 ? "Aprovado" : "Reprovado");
        //o ponteiro de leitura continua "estacionado" de onde a leitura parou, ent nao faz sentido criar um struct 
        //para cada aluno, levando em consideraçao a reduçao da carga de processamento da maquina.
    }

    // Fechando os arquivos.
    fclose(entrada);
    fclose(saida);

    printf("Leitura concluída!\n");
    printf("Resultados lançados.\n");

    return 0;
}
