#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Noticia.h"

typedef struct nolistaencad{
    Noticia info;
    struct nolista* prox;
    struct nolista* ant;
} NoListaEncad;

void criarLista(NoListaEncad **l);
int estaVazio(NoListaEncad **l);
void imprimeLista(NoListaEncad **l);
int contarElementos(NoListaEncad **l);
void inserirOrdenado(NoListaEncad **l, Noticia v);
void liberarLista(NoListaEncad **l);
NoListaEncad* buscaElemento(NoListaEncad **l, Noticia v);
NoListaEncad* ultimoElemento(NoListaEncad** l)

#endif //LISTAENCADEADA_H