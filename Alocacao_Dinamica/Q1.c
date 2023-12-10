#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i, j, pessoas, mulheresg, homensn;
    float porcf, porcm;
    printf("Quantidade de pessoas a serem entrevistadas:\n");
    scanf("%d", &pessoas);
    printf("Oi, vamos iniciar a pesquisa \n");
    char **sexo = (char **)malloc(pessoas * sizeof(char*));
    if (sexo != NULL) {
        for (i = 0; i < pessoas; i++) {
            sexo[i] = (char *)malloc(2 * sizeof(char));
            printf("Digite o sexo do %d entrevistado F/M: \n", i);
            scanf(" %c", sexo[i]);
        }
    } else {
        exit(1);
    }
    int **opiniao = (int **)malloc(pessoas * sizeof(int*));
    if (opiniao != NULL) {
        for (j = 0; j < pessoas; j++) {
            opiniao[j] = (int *)malloc(15 * sizeof(int));
            printf("Pessoa %d: o que achou do produto? (gostei/não gostei)\n", j);
            printf("1 - Gostei \n2 - Não gostei \n");
            scanf(" %d", opiniao[j]);
        }
    } else {
        exit(1);
    }
        homensn = 0;
        mulheresg = 0;
    for (i = 0; i < pessoas; i++){
        if (sexo[i][0] == 'F' && opiniao[i][0] == 1){
            mulheresg++;
        } else if (sexo [i][0] == 'M' && opiniao[i][0] == 2){
            homensn++;
        }
    }
    porcf = (mulheresg * 100) / pessoas;
    porcm = (homensn * 100) / pessoas;
    printf ("Porcentagem de pessoas do sexo feminino que gostaram do produto: %2.f%% \n", porcf);
    printf ("Porcentagem de pessoas do sexo masculino que não gostaram do produto: %2.f%%  \n", porcm);
    for (i = 0; i < pessoas; i++) {
        free(sexo[i]);
        free(opiniao[i]);
    }
    free(sexo);
    free(opiniao);

    return 0;
}
