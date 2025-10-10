/* Escreva um programa que dado um inteiro entre 1 e 12 informado pelo
usuario, imprima na tela o mes correspondente (ex.: 1: janeiro, 2:
fevereiro, …). Utilize a estrutura Enum e a estrutura de decisão switch. */

#include <stdio.h>
#include <stdlib.h>

enum meses {
    JANEIRO = 1, FEVEREIRO, MARCO, ABRIL, MAIO, JUNHO,
    JULHO, AGOSTO, SETEMBRO, OUTUBRO, NOVEMBRO, DEZEMBRO
};

int main() {
    int mes;
    printf("Digite um numero entre 1 e 12: ");
    scanf("%d", &mes);

    switch (mes) {
        case JANEIRO:
            printf("Janeiro\n");
            break;
        case FEVEREIRO:
            printf("Fevereiro\n");
            break;
        case MARCO:
            printf("Março\n");
            break;
        case ABRIL:
            printf("Abril\n");
            break;
        case MAIO:
            printf("Maio\n");
            break;
        case JUNHO:
            printf("Junho\n");
            break;
        case JULHO:
            printf("Julho\n");
            break;
        case AGOSTO:
            printf("Agosto\n");
            break;
        case SETEMBRO:
            printf("Setembro\n");
            break;
        case OUTUBRO:
            printf("Outubro\n");
            break;
        case NOVEMBRO:
            printf("Novembro\n");
            break;
        case DEZEMBRO:
            printf("Dezembro\n");
            break;
        default:
            printf("Numero invalido! Por favor, digite um numero entre 1 e 12.\n");
    }

    return 0;
}

/* gcc unionExample.c -o unionExample && ./unionExample */