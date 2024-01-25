#include <stdio.h>
#include <locale.h>

struct Pessoa
{
    char nome[100];
    long int numeroDocumento;
    int idade;
};
void modificarDados(struct Pessoa *p, int ind)
{
    int cnt = 0;
    for (cnt = 0; cnt < ind; cnt++)
    {
        printf("Dados para a pessoa %d \n", cnt + 1);
        printf("Nome:\n");
        scanf(" %[^\n]", p[cnt].nome);
        printf("Digite o número do documento: \n");
        scanf("%ld", &p[cnt].numeroDocumento);
        printf("Digite a idade: \n");
        scanf("%d", &p[cnt].idade);
    }
}
void mostrarDados(struct Pessoa *p)
{
    printf("Nome: %s \n", p->nome);
    printf("Documento: %ld \n", p->numeroDocumento);
    printf("Idade: %d \n", p->idade);
}
void alterarIdade(struct Pessoa *p)
{
    printf("Altere a idade: ");
    scanf("%d", &p->idade);
}
void compararIdade(struct Pessoa p[], int tamanho)
{
    int i, maisVelha = 0, maisNova = 0;
    for (i = 1; i < tamanho; i++)
    {
        if (p[i].idade > p[maisVelha].idade)
        {
            maisVelha = i;
        }
        if (p[i].idade < p[maisNova].idade)
        {
            maisNova = i;
        }
    }
    printf("A pessoa mais velha é: %s\n", p[maisVelha].nome);
    printf("A pessoa mais nova é: %s\n", p[maisNova].nome);
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    int nm, user;
    struct Pessoa p[2];
    modificarDados(p, 2);
    compararIdade(p, 2);
    printf("O que deseja fazer? \n 1 - Alterar idade \n 2 - Mostrar Dados \n");
    nm = 0;
    scanf("%d", &nm);
    switch (nm)
    {
    case 1:
        printf("De qual usuário? (1, 2)\n");
        scanf("%d", &user);
        if (user == 1)
        {
            alterarIdade(&p[0]);
        }
        else if (user == 2)
        {
            alterarIdade(&p[1]);
        }
        break;
    case 2:
        printf("Qual usuário deseja ver os dados? (1, 2) \n");
        scanf("%d", &user);
        if (user == 1)
        {
            mostrarDados(&p[0]);
        }
        else if (user == 2)
        {
            mostrarDados(&p[1]);
        }
        break;
    default:
        printf("Inserção inválida, tente novamente!");
        break;
    }
}