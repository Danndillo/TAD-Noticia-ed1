#ifndef LISTACABCAU_H
#define LISTACABCAU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Noticia.h"

typedef struct noLista{
    Noticia noticia;
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
void removerNoticia(Lista *l, Noticia v);
void removerNoticiaID(Lista *l, int id);
Noticia* buscarKeyword(Lista *l, char key[]);
void imprimirTodasNoticias(Lista *l);
int qtdNoticias(Lista *l);
void liberarLista(Lista *l);

#endif // LISTACABCAU_H
