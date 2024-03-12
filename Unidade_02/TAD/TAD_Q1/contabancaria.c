#include "contabancaria.h"

struct contabancaria{
    char titular [30];
    int numero;
    float saldo;
};

conta* criaconta(char* titular, int numero, float saldo){
    conta *contab = (conta*) malloc(sizeof(conta));
    if(contab == NULL){
        printf("Erro na alocação");
        exit(1);
    }
    contab->numero = numero;
    contab->saldo = saldo;
    strcpy(contab->titular, titular);
    return contab;
};

void deposita(conta * a, float valor){
    a->saldo = valor + a->saldo;
    printf("Valor alterado para: %.2f\n", a->saldo);
};

void saca(conta * a, float valor){
    if (valor > a->saldo){
        printf("Você não tem saldo suficiente para o valor desejado\n");
        return;
    }
    a->saldo = a->saldo - valor;
    printf("Saque efetuado, valor disponivel agora: %.2f \n", a->saldo);
};

void transfere(conta * a, conta * b, float valor){
    if (a->saldo < valor){
        printf("Saldo insuficiente para transferência. \n");
        return;
    }
    a->saldo = a->saldo - valor;
    b->saldo = b->saldo + valor;
};

void saldo(conta * a){
    printf("Saldo da conta: %.2f \n", a->saldo);
};

void excluiconta(conta * x){
    free(x);
};


