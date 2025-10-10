/* (Adaptado) Criar duas structs (uma para vinil, e outra para prateleiras), usando struct aninhadas */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct vinil {
    char titulo[100];
    char artista[100];
    int ano;
};

struct prateleira {
    char nome[100];
    struct vinil discos[50];
    int total_discos;
};

int main() {
    struct prateleira minha_prateleira;
    strcpy(minha_prateleira.nome, "Minha Coleção de Vinis");
    minha_prateleira.total_discos = 0;

    struct vinil v1;
    strcpy(v1.titulo, "Pain to Power");
    strcpy(v1.artista, "Maruja");
    v1.ano = 2025;

    struct vinil v2;
    strcpy(v2.titulo, "Willoughby Tucker, I'll Always Love You");
    strcpy(v2.artista, "Ethel Cain");
    v2.ano = 2025;

    minha_prateleira.discos[minha_prateleira.total_discos++] = v1;
    minha_prateleira.discos[minha_prateleira.total_discos++] = v2;

    printf("Prateleira: %s\n", minha_prateleira.nome);
    for (int i = 0; i < minha_prateleira.total_discos; i++) {
        printf("Disco %d: %s - %s (%d)\n", i + 1,
                minha_prateleira.discos[i].artista,
                minha_prateleira.discos[i].titulo,
                minha_prateleira.discos[i].ano);
    }

    return 0;
}