#include <stdio.h>

#define FUNCS 2

struct func{
    int id;
    char nome[20];
    float salario;
};
int main (void){
    int i;
    FILE * funcionarios;
    
    struct func colab[FUNCS];
    for (i = 0; i < FUNCS; i++){
        printf("Digite o nome do funcionario %d \n", i+1);
        scanf(" %[^\n]", colab[i].nome);
        printf("Digite o salário do funcionario %d \n", i+1);
        scanf("%f", &colab[i].salario);
        printf("Digite o ID do funcionario %d \n", i+1);
        scanf("%d", &colab[i].id);
    }
    funcionarios = fopen("Funcionários.txt", "w");
    for(i = 0; i < FUNCS; i++){
    fprintf(funcionarios, "Funcionário(a): %s \n Salário: %.2fR$ \n ID: %d\n", colab[i].nome, colab[i].salario, colab[i].id);
    }
    fclose(funcionarios);
    return 0;
}