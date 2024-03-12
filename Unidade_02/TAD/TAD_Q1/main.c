#include "contabancaria.h"

int main(void)
{
    int opcao, numc, dep, aux = 0;
    float valor;
    int numM = 2;
    conta *contas[numM];
    char nome[20];
    do
    {
        printf("-_-_-_-Conta-Bancaria-_-_-_-\n");
        printf("1 - Criar conta\n");
        printf("2 - Depositar\n");
        printf("3 - Sacar\n");
        printf("4 - Transferir\n");
        printf("5 - Ver saldo\n");
        printf("6 - Excluir conta\n");
        printf("Digite qualquer outro número para sair.\n");

        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            if (numc < numM)
            {
                getchar();
                printf("Digite o nome da conta: \n");
                scanf("%s", nome);
                contas[numc] = criaconta(nome, numc, 0.0);
                printf("Conta criada!\n numero: %d \n", numc);
                numc++;
            }
            else
            {
                printf("Numero maximo de contas atingido.");
            }

            break;

        case 2:
            printf("Digite o numero da conta que deseja depositar:\n");
            scanf("%d", &dep);
            printf("Digite o valor: \n");
            scanf("%f", &valor);
            deposita(contas[dep], valor);
            printf("Deposito efetuado!");
            break;
        case 3:
            printf("Digite o numero da conta que deseja sacar:\n");
            scanf("%d", &dep);
            printf("Digite o valor: \n");
            scanf("%f", &valor);
            saca(contas[dep], valor);
            break;
        case 4:
            printf("Qual a conta de origem? \n");
            scanf("%d", &dep);
            printf("Digite o valor: \n");
            scanf("%f", &valor);
            printf("Qual a conta de destino? \n");
            scanf("%d", &aux);
            transfere(contas[dep], contas[aux], valor);
            break;
        case 5:
            printf("Digite o numero da conta: \n");
            scanf("%d", &dep);
            saldo(contas[dep]);
            break;
        case 6:
            printf("Qual conta excluir?\n");
            scanf("%d", &dep);
            excluiconta(contas[dep]);
            break;
        default:
           

           
            break;
        }
    } while (opcao >= 1 && opcao <= 6);
     for (int i = 0; i < numc; i++)
            {
                if (contas[i] != NULL)
                {
                    excluiconta(contas[i]);
                }
            }
    return 0;
}