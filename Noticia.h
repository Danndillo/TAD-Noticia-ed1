#ifndef NOTICIA_H
#define NOTICIA_H 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
    int dia;
    int mes;
    int ano;
} Data;

typedef enum tipoClassificacao {
    EMANALISE = 1,
    CONFIAVEL,
    SUSPEITA
} TypeClass;

typedef struct noticia{
    int id;
    Data data;
    char titulo[50];
    char conteudo[500];
    char fonte[100];
    TypeClass tipo;
} Noticia;

Noticia* criarNoticia(Data newData, char newTitulo[], char newConteudo[], char newFonte[], TypeClass newClassificacao);
void imprimirNoticia(Noticia* n);
Noticia* liberarNoticia(Noticia* n);

#endif //NOTICIA_H