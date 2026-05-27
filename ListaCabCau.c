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
  novo->info = v;
  novo->prox = aux;
}

void imprimirLista(Lista *l){
  for(NoLista *p = l->cabeca->prox; p->prox != NULL; p = p->prox){
    imprimirNoticia(&(p->info));
    printf("\n");
  }
}

void removerNoticiaID(Lista *l, int id){
  NoLista *p, *aux = l->cabeca;
  for(p = l->cabeca->prox; p != l->cauda && p->info.id != id; p = p->prox){
    aux = p;
  }

  if(p == l->cauda)
    printf("Nao encontrado\n");
  else {
    aux->prox = p->prox;
    free(p);
    printf("Removida com sucesso!\n");
  }
}

void removerNoticiaKey(Lista *l, char keyword[]){
  NoLista *p, *aux = l->cabeca;
  for(p = l->cabeca->prox; p != l->cauda && !(strstr(p->info.titulo, keyword) || strstr(p->info.conteudo, keyword)); p = p->prox){
    aux = p;
  }

  if(p == l->cauda)
    printf("Nao encontrado");
  else {
    aux->prox = p->prox;
    free(p);
  }
}

void removerNoticia(Lista *l, Noticia v){
  NoLista *p, *aux = l->cabeca;
  for(p = l->cabeca->prox; p != l->cauda && p->info != v; p = p->prox){
    aux = p;
  }

  if(p == l->cauda)
    printf("Nao encontrado");
  else {
    aux->prox = p->prox;
    liberarNoticia(p->info);
    free(p);
  }
}

Noticia* buscarKeyword(Lista *l, char key[]){
  
}

void imprimirTodasNoticias(Lista *l){

}

int qtdNoticias(Lista *l){

}


void liberarLista(Lista *l){

}