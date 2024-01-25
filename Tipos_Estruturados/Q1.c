#include <stdio.h>
#include <stdlib.h>

#define ING 3

typedef struct ingresso
{
    float preco;
    char local[50];
    char atracao[30];
}Ingresso;

void preenche(Ingresso *i)
{
    printf("Preço do ingresso: \n");
    scanf("%f", &i->preco);
    getchar();
    printf("Onde será a atração? \n");
    scanf("%[^\n]", i->local);
    getchar();
    printf("E qual será a atração? \n");
    scanf("%[^\n]", i->atracao);
}
void imprime(Ingresso *i){
    printf("Mostrando dados do ingresso: \n");
    printf("Preço: %f \n", i->preco);
    printf("Atração: %s \n", i->atracao);
    printf("Local: %s \n", i->local);
}
void altera_preco(Ingresso* i, float valor){
    i->preco = valor;
    printf("Valor do preço alterado! \n Novo valor: %f \n", i->preco);
}

void imprime_menor_maior_preco(int n, Ingresso* vet){
        if (n <= 0)
    {
        printf("Vetor vazio ou tamanho inválido.\n");
        return;
    }
    int maiorP = 0;
    int menorP = 0;
    for (int i = 1; i < n; i++){
        if (vet[i].preco > vet[maiorP].preco){
            maiorP = i;
        }
        if (vet[i].preco < vet[menorP].preco){
            menorP = i;
        }

    }
    printf("Maior preço: %f \n", vet[maiorP].preco);
    printf("Menor preço: %f \n", vet[menorP].preco);
}

int main(void)
{
    float novoValor;
    Ingresso p[ING];
    for (int i = 0; i < ING; i++){
    preenche(&p[i]);
    imprime(&p[i]);
    printf("Digite o novo valor: \n");
    scanf ("%f", &novoValor);
    altera_preco(&p[i], novoValor);
    }
    imprime_menor_maior_preco(ING, p);
    return 0;
}