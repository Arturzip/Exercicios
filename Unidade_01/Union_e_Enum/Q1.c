#include <stdio.h>
#include <string.h>

union Genero {
    char masculino[10];
    char feminino[10];
};

struct Pessoa {
    char nome[20];
    int idade;
    union Genero genero;
};

void mostrarDados(struct Pessoa p){
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    if (p.genero.masculino[0] != '\0') {
        printf("Gênero: %s\n", p.genero.masculino);
    } else {
        printf("Gênero: %s\n", p.genero.feminino);
    }
}

void preencherDados(struct Pessoa *p){
    int op;
    p->genero.masculino[0] = '\0';
    p->genero.feminino[0] = '\0';
    printf("Preencha seu nome: \n");
    scanf("%s", p->nome);
    printf("Preencha sua idade: \n");
    scanf("%d", &(p->idade));
    printf("Qual seu gênero? \n 1 - Masculino \n 2 - Feminino\n");
    scanf("%d", &op);
    switch (op) {
    case 1:
        strcpy(p->genero.masculino, "Masculino");
        break;
    case 2:
        strcpy(p->genero.feminino, "Feminino");
        break;
    default:
        printf("Erro! Tente novamente.\n");
        break;
    }
}

int main(void){
    struct Pessoa pessoa;
    preencherDados(&pessoa);
    mostrarDados(pessoa);
    return 0;
}
