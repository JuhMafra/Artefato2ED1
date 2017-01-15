#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"lista.h"
#define MAX 200
/* Artefato 2 de Jean e Juliana*/
Lista* cria_lista()
{
    return NULL;
}
void insere_lista(Lista** Li, char c)
{
    Lista *p = *Li;
    Lista *ant = NULL;

    if(!estahNaLista(&p,c))
    {
        while(p != NULL && p->info < c)
        {
            ant = p;
            p= p->prox;
        }
        Lista *novo =(Lista*)malloc(sizeof(Lista));
        novo->info = c;

        if(ant == NULL)
        {
            novo->prox = *Li;
            *Li = novo;
        }
        else
        {
            novo->prox = ant->prox;
            ant->prox = novo;
        }
    }

}
int estahNaLista(Lista **Li, char c)
{
    Lista *p = *Li;
    while(p != NULL)
    {
        if(p->info != c)
        {
            p = p->prox;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}


void ocorrencia(Lista ** Li,FILE *arquivo)
{

    Lista *p = *Li;
    Lista *a = p;
    Lista *b = p;
    int c_l = 0,c_o = 0,c_v = 0,aux = 0;
    char c;
    int vet[MAX],i = 0,j = 0;

    p->subinfo = (sublista*)malloc(sizeof (sublista));

    while(p != NULL)
    {

        while(!feof(arquivo))
        {
            c = fgetc(arquivo);
            c = toupper(c);

            if(c == '\n')
            {
                c_l++;

                vet[i++] = c_l;
                vet[i++] = c_o;
                c_o = 0;

            }

            if(c == p->info)
            {
                c_o++;
            }

        }

        rewind(arquivo);
        c_l++;
        aux = c_l;
        vet[i++] = c_l;
        vet[i++] = c_o;
        c_l = 0;
        c_o = 0;
        p = p->prox;


    }

    c_v = i;

    printf("\n");

    for(i = 0; i<c_v; /*vazio*/ )
    {

        while(a != NULL)
        {
            printf("\n%c - ", a->info);

            for(j = 0 ; j< aux; j++)
            {
                a->subinfo = (sublista*) malloc(sizeof(sublista));
                a->subinfo->linha = vet[i++] - 1;
                a->subinfo->ocorrencia = vet[i++];

                printf("(%d,%d)  ", a->subinfo->linha, a->subinfo->ocorrencia);

                if(j != (aux - 1))
                {
                    a->subinfo = a->subinfo->prox;
                }
            }
            a = a->prox;

        }
    }
    printf("\n");
}


