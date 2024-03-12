#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Struct exigida no exercício:
typedef struct contabancaria conta;

//Função que libera a alocação da conta "x"
void excluiconta(conta * x);

//Função para verificar o saldo da conta:
void saldo(conta * a);

//Função para transferência entre contas:
void transfere(conta * a, conta * b, float valor);

//Função para saque de saldo:
void saca(conta * a, float valor);

//Função para depósito de saldo:
void deposita(conta * a, float valor);

//Função para criação de conta:
conta* criaconta(char* titular, int numero, float saldo);