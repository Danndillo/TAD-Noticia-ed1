#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaCabCau.h"

void criarLista(Lista *l){
    l->cabeca = (NoLista*) malloc(sizeof(NoLista));
    l->cauda = (NoLista*) malloc(sizeof(NoLista));
    l->cabeca->prox = l->cauda;
    l->cauda->prox = NULL;
}

int estaVazia(Lista *l){
    return (l->cabeca->prox == l->cauda);
}

void inserirNoticiaInicio(Lista* l, Noticia v){
  NoLista *novo = (NoLista*) malloc(sizeof(NoLista));
  NoLista *aux = l->cabeca->prox;
  l->cabeca->prox = novo;
  novo->noticia = v;
  novo->prox = aux;
}

void imprimirLista(Lista *l){
  for(NoLista *p = l->cabeca->prox; p->prox != NULL; p = p->prox){
    imprimirNoticia(&(p->noticia));
    printf("\n");
  }
}

void removerNoticia(Lista *l, Noticia v){

}

void removerNoticiaID(Lista *l, int id){

}

Noticia* buscarKeyword(Lista *l, char key[]){

}

void imprimirTodasNoticias(Lista *l){

}

int qtdNoticias(Lista *l){

}


void liberarLista(Lista *l){

}
