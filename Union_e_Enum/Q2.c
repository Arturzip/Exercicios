#include <stdio.h>
#include <string.h>

union tipo
{
    char alimento[30];
    char bebida[30];
    char eletronico[30];
};

struct Produto
{
    char Nome[20];
    float Preco;
    union tipo Tipo;
    int tipod;
};

void preenche(struct Produto *p)
{
    int op;
    printf("Qual o nome do produto? \n");
    scanf("%[^\n]", p->Nome);
    printf("E qual o preço? \n");
    scanf(" %f", &(p->Preco));
    printf("Por último o tipo do produto: \n");
    scanf(" %d", &op);
    switch (op)
    {
    case 1:
        printf("Tipo escolhido: Alimento.\n");
        strcpy(p->Tipo.alimento, "Alimento");
        p->tipod = 1;
        break;
    case 2:
        printf("Tipo escolhido: Bebida.\n");
        strcpy(p->Tipo.bebida, "Bebida");
        p->tipod = 2;
        break;
    case 3:
        printf("Tipo escolhido: Eletrônico.\n");
        strcpy(p->Tipo.eletronico, "Eletrônico");
        p->tipod = 3;
        break;
    default:
        break;
    }
    printf("Produto registrado!!\n");
}

void mostra(struct Produto p)
{
    printf("Nome: %s \n", p.Nome);
    printf("Preço: %f", p.Preco);
    switch (p.tipod)
    {
    case 1:
        printf("%s", p.Tipo.alimento);
        break;
    case 2:
        printf("%s", p.Tipo.bebida);
        break;
    case 3:
        printf("%s", p.Tipo.eletronico);
        break;
    default:
        printf("Erro na tipagem, tipo desconhecido. \n");
    }
}

int main(void)
{
    struct Produto pp;
    preenche(&pp);
    mostra(pp);
    return 0;
}