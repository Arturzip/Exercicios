#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct fruta
{
    float preco;
    char nome[20];
};
void coletardados(struct fruta *p)
{
    FILE * f;
    f = fopen("Frutas.txt", "w");
    int k;
    while (k != 1)
    {
        printf("Digite o nome da fruta: \n");
        scanf("%s", p->nome);
        printf("Digite o preço: \n");
        scanf("%f", &p->preco);
        printf("Registrando fruta...\n");
    fprintf(f, "Nome: %s, Preço: %.2fR$ \n", p->nome, p->preco);
    fprintf(f, "-----------------------\n");
        printf("Deseja adicionar mais alguma fruta? \n 0 - Sim \n 1 - Não \n");
        scanf(" %d", &k);
    }
    printf("Fechando arquivo...\n");
    fclose(f);
};

int main(void)
{
    setlocale(LC_ALL, "Portuguese"); //Adiconei o locale para que os valores flutuantes pudessem ser lidos utilizando a virgula como separador decimal.
    struct fruta produto;
    coletardados(&produto);
    return 0;
}