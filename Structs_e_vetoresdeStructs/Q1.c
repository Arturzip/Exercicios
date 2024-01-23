#include <stdio.h>
#include <locale.h>

struct funcionario
{
    char nome[50];
    int salario;
    int identificador;
    char cargo[50];
};

void mostrardados(struct funcionario most)
{
    printf("Mostrando dados do funcionário:\n ");
    printf("%s\n", most.nome);
    printf("%d\n", most.salario);
    printf("%d\n", most.identificador);
    printf("%s\n", most.cargo);
}

void receberdados(struct funcionario *func)
{
    printf("Nome: \n");
    scanf("%s", func->nome);

    printf("Salário: \n");
    scanf("%d", &(func->salario));

    printf("indentificador: \n");
    scanf("%d", &(func->identificador));

    printf("Cargo: \n");
    scanf("%s", func->cargo);
}

void alterardados(struct funcionario *alt)
{
    printf("Altere o nome: \n");
    scanf("%s", alt->nome);

    printf("Altere o salário: \n");
    scanf("%d", &(alt->salario));

    printf("Altere o identificador: \n");
    scanf("%d", &(alt->identificador));

    printf("Altere o cargo: ");
    scanf("%s", alt->cargo);
}

void comparar(struct funcionario funcio[], int tamanho)
{
    if (tamanho <= 0)
    {
        printf("Vetor vazio ou tamanho inválido.\n");
        return;
    }

    int iMaiorSalario = 0;
    int iMenorSalario = 0;

    for (int i = 1; i < tamanho; i++)
    {
        if (funcio[i].salario > funcio[iMaiorSalario].salario)
        {
            iMaiorSalario = i;
        }

        if (funcio[i].salario < funcio[iMenorSalario].salario)
        {
            iMenorSalario = i;
        }
    }

    printf("Funcionário com maior salário:\n");
    printf("Cargo: %s\n", funcio[iMaiorSalario].cargo);
    printf("Salário: %d\n", funcio[iMaiorSalario].salario);

    printf("\nFuncionário com menor salário:\n");
    printf("Cargo: %s\n", funcio[iMenorSalario].cargo);
    printf("Salário: %d\n", funcio[iMenorSalario].salario);
}

int main(void)
{
    int m;
    setlocale(LC_ALL, "Portuguese_Brazil");
    struct funcionario funcio[3];

    for (int i = 0; i < 3; i++)
    {
        printf("Digite os dados para o funcionário %d:\n", i + 1);
        receberdados(&funcio[i]);
    }

    printf("Digite de que funcionário quer alterar os dados [1 à 3]: \n");
    scanf("%d", &m);
    m--;
    alterardados(&funcio[m]);

    printf("\nApós a alteração:\n");
    mostrardados(funcio[m]);

    comparar(funcio, 3);

    return 0;
}
