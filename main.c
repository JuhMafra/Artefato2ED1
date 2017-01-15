#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "lista.h"
/* Artefato 2 de Jean e Juliana*/
int main()
{
    FILE *f = fopen("arquivo.txt","r");
    Lista *l = cria_lista();
    char c;

    if(f == NULL){
        printf("Erro!!!!");
        exit(1);
    }
    else{
         c= fgetc(f);
        while(!feof(f)){
                if(c != ' ' && c != '\n'){

                    c = toupper(c);
                    insere_lista(&l,c);
                    c = fgetc(f);
                 }
                 else{
                    c = fgetc(f);
                 }
        }
        rewind(f);
        ocorrencia(&l,f);
        fclose(f);
return 0;

}
}
