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
  for(NoLista *p = l->cabeca->prox; p != l->cauda; p = p->prox){
    imprimirNoticia(&(p->info));
    printf("\n");
  }
}

void removerNoticiaID(Lista *l, int id){
  if(estaVazia(l))
    printf("A lista esta vazia!\n");
  else {
    NoLista *p, *aux = l->cabeca;
    for(p = l->cabeca->prox; p != l->cauda && p->info.id != id; p = p->prox){
      aux = p;
    } 

    if(p == l->cauda)
      printf("Nao encontrado");
    else {
      aux->prox = p->prox;
      free(p);
      printf("Removida com sucesso!");
    }
  }
}

void classificarNoticia(Lista *l, NoListaEncad **Encad){
  if(estaVazia(l))
    printf("A lista esta vazia!\n");
  else {
  for(NoLista *p = l->cabeca->prox, *proximo; p->prox != NULL; p = p->prox){
    TypeClass newTypeClass;

    imprimirNoticia(&(p->info));

    printf("\nQual a nova classificacao desta noticia?\n1 - Em Analise | 2 - Confiavel | 3 - Suspeita\n> ");
    scanf("%d", &newTypeClass);

    p->info.tipo = newTypeClass;
    printf("\n");

    proximo = p->prox;
    if(newTypeClass != 1){
      inserirNoticiaEncad(Encad, p->info);
      removerNoticiaID(l, p->info.id);
    }
  }
}
}

Noticia* buscarKeyword(Lista *l, char keyword[]){
  NoLista *p;

  for(p = l->cabeca->prox; p != l->cauda && !(strstr(p->info.titulo, keyword) || strstr(p->info.conteudo, keyword)); p = p->prox){
    continue;
  }
  
  if(p == l->cauda){
    printf("Não Encontrado!");
    return NULL;
  }

  return &(p->info);
}

void qtdNoticias(Lista *l, NoListaEncad **Encad){
  int analise = 0, confiavel = 0, suspeita = 0;

  for(NoLista *p = l->cabeca->prox; p != l->cauda; p = p->prox){
    analise++;
  }

  for(NoListaEncad *q = *Encad; q!=NULL; q = q->prox){
    if(q->info.tipo == 2)
      confiavel++;
    else
      suspeita++;
  }

  printf("\nEm Analise: %d\nConfiaveis: %d\nSuspeitas: %d\n", analise, confiavel, suspeita);
}

/*void removerNoticiaKey(Lista *l, char keyword[]){
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
}*/



Noticia* buscarID(Lista *l, char key[]){
  
}

void imprimirTodasNoticias(Lista *l){

}


void liberarLista(Lista *l){

}