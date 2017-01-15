#include <stdio.h>
#include <stdlib.h>
/* Artefato 2 de Jean e Juliana*/
struct sublista{
    int linha;
    int ocorrencia;
    struct sublista *prox;
};
typedef struct sublista sublista;
struct lista{
        char info;
        struct lista *prox;
        struct sublista *subinfo;
};
typedef struct lista Lista;
Lista* cria_lista();
void insere_lista(Lista** Li, char c);
int estahNaLista(Lista **Li, char c);
void ocorrencia(Lista ** Li,FILE *arquivo);
