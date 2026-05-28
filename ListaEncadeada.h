#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Noticia.h"

typedef struct nolistaencad{
    Noticia info;
    struct nolistaencad* prox;
} NoListaEncad;

void criarListaEncad(NoListaEncad **l);
int estaVazioEncad(NoListaEncad **l);
void imprimeListaEncad(NoListaEncad **l);
void removerNoticiaKeyword(NoListaEncad **l, char keyword[]);
void inserirNoticiaEncad(NoListaEncad **l, Noticia v);
/*int contarElementosEncad(NoListaEncad **l);
void inserirOrdenadoEncad(NoListaEncad **l, Noticia v);
void liberarListaEncad(NoListaEncad **l);
NoListaEncad* buscaElementoEncad(NoListaEncad **l, Noticia v);
NoListaEncad* ultimoElementoEncad(NoListaEncad** l)
*/
#endif //LISTAENCADEADA_H