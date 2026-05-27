#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Noticia.h"

Noticia* criarNoticia(Data newData, char newTitulo[], char newConteudo[], char newFonte[], TypeClass newClassificacao){
  static int id = 1;
  Noticia *novo = (Noticia *) malloc(sizeof(Noticia));
  if(novo !=NULL){
    novo->id = id;
    id++;
    novo->data = newData;
    strcpy(novo->titulo, newTitulo);
    strcpy(novo->conteudo, newConteudo);
    strcpy(novo->fonte, newFonte);
    novo->tipo = newClassificacao;
  } else {
    printf("\nErro de alocacao!\n");
  }
  return novo;
}

void imprimirNoticia(Noticia* n){
  if(n!=NULL){
    printf("#%d - %s\n", n->id, n->titulo);
    printf("%d/%d/%d\n",n->data.dia,n->data.mes,n->data.ano);
    printf("%s\n", n->conteudo);
    printf("Fonte: %s\n", n->fonte);
    switch(n->tipo){
        case EMANALISE:
            printf("Tipo: Em Analise");
            break;
        case CONFIAVEL:
            printf("Tipo: Confiavel");
            break;
        case SUSPEITA:
            printf("Tipo: Suspeita");
            break;
        default:
            printf("Tipo: Não Determinado");
            break;
    }

    printf("\n----------------------\n");
    
  } else
  printf("Nada encontrado!\n");
}

Noticia* liberarNoticia(Noticia* n){
  free(n);
  return NULL;
}