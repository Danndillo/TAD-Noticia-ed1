#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaEncadeada.h"

void criarListaEncad(NoListaEncad **l){
    *l=NULL;
}

int estaVazioEncad(NoListaEncad **l){
    return (*l == NULL);
}

void imprimeListaEncad(NoListaEncad **l){
    if(estaVazioEncad(l)){
        printf("A lista está vazia!\n");
    } else {
        for(NoListaEncad *p = *l; p!=NULL; p = p->prox){
            imprimirNoticia(&(p->info));
        }
        printf("\n");
    }
}

void removerNoticiaKeyword(NoListaEncad **l, char keyword[]){
    if(estaVazioEncad(l)){
        printf("A lista está vazia!\n");
    } else {
        NoListaEncad *p, *ant = NULL;
        for(p = *l; p!=NULL && !(strstr(p->info.titulo, keyword) || strstr(p->info.conteudo, keyword)); p = p->prox){
            ant = p;
        }
        
        if(p==NULL){
            printf("Não encontrado!\n");
        } else {
            if(ant == NULL)
                *l = p->prox;
            else 
                ant->prox = p->prox;
            
            free(p);
            printf("Noticia removida com sucesso!\n");
        }
    }
}

void inserirNoticiaEncad(NoListaEncad **l, Noticia v){
    NoListaEncad *novo = (NoListaEncad*) malloc(sizeof(NoListaEncad));
    
    if(novo!=NULL){
        novo->info = v;
        novo->prox = *l;
        *l = novo;
    } else {
        printf("Erro de alocação!\n");
    }
}

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