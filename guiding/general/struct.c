/* Defina um tipo de estrutura para armazenar um horário composto de
hora, minutos e segundos. Crie e inicialize uma variável desse tipo e,
em seguida, mostre seu valor na tela usando o formato "99:99:99".

Defina um tipo de estrutura para armazenar dados de um vôo como, por
exemplo os nomes das cidades de origem e destino, datas e horários
de de partida e chegada. Crie uma variável desse tipo e atribua
valores aos seus membros usando notação de ponto e, depois,
inicialização.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct horario {
    int hora;
    int minuto;
    int segundo;
};

struct voo {
    char origem[50];
    char destino[50];
    struct horario partida;
    struct horario chegada;
};

int main() {
    struct horario h = {14, 30, 45};
    printf("Horario: %02d:%02d:%02d\n", h.hora, h.minuto, h.segundo);

    struct voo v;
    strcpy(v.origem, "São Paulo");
    strcpy(v.destino, "Rio de Janeiro");
    v.partida.hora = 9;
    v.partida.minuto = 15;
    v.partida.segundo = 0;
    v.chegada.hora = 10;
    v.chegada.minuto = 30;
    v.chegada.segundo = 0;

    printf("Voo de %s para %s\n", v.origem, v.destino);
    printf("Partida: %02d:%02d:%02d\n", v.partida.hora, v.partida.minuto, v.partida.segundo);
    printf("Chegada: %02d:%02d:%02d\n", v.chegada.hora, v.chegada.minuto, v.chegada.segundo);

    return 0;
}