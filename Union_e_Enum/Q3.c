#include <stdio.h>

enum meses { 
    Janeiro = 1, 
    Fevereiro, 
    Março, 
    Abril, 
    Maio, 
    Junho, 
    Julho, 
    Agosto, 
    Setembro, 
    Outubro, 
    Novembro, 
    Dezembro
};
struct Data{
    int Dia;
    enum meses mes;
    int ano;
};

int main (void){
    int op;
    struct Data data;
    
    printf("Digite o dia: \n");
    scanf("%d", &data.Dia);
    printf("Digite o mês (1-12): ");
    scanf("%d", &op);
    printf("Digite o ano: \n");
    scanf("%d", &data.ano);

    data.mes = op;
    printf("%d/%d/%d", data.Dia, data.mes, data.ano);

    return 0;
}