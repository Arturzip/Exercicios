#include <stdio.h>
#include <math.h>
void calcula_hexagono(float l, float *area, float *perimetro){
    *area = (3 * pow(l, 2) * sqrt(3))/2;
    *perimetro = 6 * l;
    printf("Área do hexágono: %.2f \nPerímetro do hexágono: %.2f \n", *area, *perimetro);
}

int main(){
    float lado, area, perimetro;
    printf("Informe o lado (l): \n");
    scanf("%f", &lado);
    calcula_hexagono(lado, &area, &perimetro);

    return 0;
}
