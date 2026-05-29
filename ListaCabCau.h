#ifndef LISTACABCAU_H
#define LISTACABCAU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Noticia.h"
#include "ListaEncadeada.h"

typedef struct noLista{
    Noticia info;
    struct noLista* prox;
} NoLista;

typedef struct lista{
    NoLista* cabeca;
    NoLista* cauda;
} Lista;

void criarLista(Lista *l);
int estaVazia(Lista *l);
void inserirNoticiaInicio(Lista* l, Noticia v);
void imprimirLista(Lista *l);
void classificarNoticia(Lista *l, NoListaEncad **Encad);
int removerNoticiaID(Lista *l, int id);
Noticia* buscarKeyword(Lista *l, char key[]);
void qtdNoticias(Lista *l, NoListaEncad **Encad);
void liberarLista(Lista *l);

#endif // LISTACABCAU_H