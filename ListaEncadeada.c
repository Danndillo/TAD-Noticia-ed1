/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaEncadeada.h"

void criarLista(NoListaEncad **l){
     *l=NULL;
}

int estaVazio(NoListaEncad **l){
    return *l == NULL;
}

void imprimeLista(NoListaEncad **l){
    if(!estaVazio(l)){
        for(NoLista*p = *l;p!=NULL;p = p->prox){
            imprimirNoticia(&(p->info));
        } printf("\n");
    } else{
        printf("Esta Vazia \n");
    }
}

int contarElementos(NoListaEncad **l){
    int tot = 0;
    NoLista *p;
    
    for(p = *l; p!=NULL; p= p->prox)
        tot++;

    return tot;
}

void inserirOrdenado(NoListaEncad **l, Noticia v){
    NoLista *p, *ant = NULL;
    for(p=*l; p!=NULL && p->info < v; p = p->prox){
        ant = p;
    }
        NoLista* novo = (NoListaEncad *) malloc(sizeof(NoListaEncad));
        if(novo != NULL){
            novo->info = v;
            novo->prox = p;
        }
        if(ant == NULL)
            *l = novo;
        else
            ant->prox = novo;
    }

void liberarLista(NoListaEncad **l){
    NoLista *p, *temp;
    for(p = *l; p!=NULL ; p=temp){
        temp = p->prox;
        free(p);
    }
    *l = NULL;
}

NoLista* buscaElemento(NoListaEncad **l, Noticia v){
    if(!estaVazio(l)){
        for(NoListaEncad*p = *l;p!=NULL;p = p->prox){
            if(p->info == v)
                return p;
        } 
        printf("Não encontrado!");
        return NULL;
    } else{
        printf("Esta Vazia \n");
        return NULL;
    }
}

NoLista* ultimoElemento(NoListaEncad** l){
    NoListaEncad *p, *ant=NULL;
    
    for(p = *l;p!=NULL;p=p->prox){
        ant = p;
    }
    return ant;
}*/