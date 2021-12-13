// #include "estruturas.h"
#include <stdio.h>
#include <stdlib.h>

struct TimeFutebol {
    char *nome;
    int pontos, gols, vitorias, derrotas, empates;
};

void imprimir(struct TimeFutebol *time){
    printf("testando time\n");
    printf("nome: %s\n", time->nome);
    printf("pontos: %d\n", time->pontos);
    printf("gols: %d\n", time->gols);
    printf("vitorias: %d\n", time->vitorias);
    printf("derrotas: %d\n", time->derrotas);
    printf("empates: %d\n", time->empates);
}

int main() {
    struct TimeFutebol *time = malloc(sizeof(struct TimeFutebol));

    time->nome = malloc(sizeof(char) * 100);
    time->pontos;
    time->gols;
    time->vitorias;
    time->derrotas;
    time->empates;

    scanf("%s", time->nome);
    scanf("%d", &time->pontos);
    scanf("%d", &time->gols);
    scanf("%d", &time->vitorias);
    scanf("%d", &time->derrotas);
    scanf("%d", &time->empates);
   
    imprimir(time);

    free(time->nome);
    free(time);
    
    return 0;
}