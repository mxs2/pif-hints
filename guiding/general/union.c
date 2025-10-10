/* Usando uma união rotulada, defina um tipo de dados para representar
figuras geométricas, como retângulos e círculos, e crie uma função para
calcular a área de uma figura. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M_PI 3.141 /* Definição de PI, caso não esteja definido */

struct retangulo {
    double largura;
    double altura;
};

struct circulo {
    double raio;
};

struct figura {
    enum { RETANGULO, CIRCULO } tipo;
    union {
        struct retangulo r;
        struct circulo c;
    } forma;
};

double calcular_area(struct figura *f) {
    switch (f->tipo) {
        case RETANGULO:
            return f->forma.r.largura * f->forma.r.altura;
        case CIRCULO:
            return M_PI * f->forma.c.raio * f->forma.c.raio;
        default:
            return 0.0;
    }
}

int main() {
    struct figura f1;
    f1.tipo = RETANGULO;
    f1.forma.r.largura = 5.0;
    f1.forma.r.altura = 10.0;

    struct figura f2;
    f2.tipo = CIRCULO;
    f2.forma.c.raio = 7.0;

    printf("Area do retangulo: %.2f\n", calcular_area(&f1));
    printf("Area do circulo: %.2f\n", calcular_area(&f2));

    return 0;
}