#include <stdio.h>
void func(int vet[]) {
    for(int i = 4; i >= 0; i--) {
        printf("Num %d\n", vet[i]);
    }
}
int main() {
    int vetor[5] = {1, 2, 3, 4, 5};
    printf(" Oi! :D\n");
    func(vetor);
    return 0;
}
// 2, o programa faz o seguinte:
// * O programa começa criando uma função (chamada de "f")
// essa função então é programada para receber de argumento, matrizes
// * Após receber, a função executa cálculos em numeros da matrizes
// esses numeros sao selecionados alinhando coluna x linha que dá de encontro com um número na matriz
//* Depois dos cálculos, a função encaminha pra funçao chamadora "main" o resultado dos cálculos.
//* Por fim, o resultado é: -5

//3, há erros de ponto e vírgula (ausência) na declaração das variáveis e também entre os argumentos do for
// Posso estar errado, mas acho que o return também não pode ficar vázio, pois a funçao main nao é do tipo void.

//4, Não consegui resolver.

//5, a saída será 2 200.