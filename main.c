#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Noticia.h"
#include "ListaCabCau.h"
#include "ListaEncadeada.h"

//setlocale(LC_ALL, "pt-br");
void limparTela();
void pausarOSFriendly();

int main(){

    int opt=0;
    char keyword[100];
    Lista cabCau;
    NoListaEncad **ListaEncad;
     
    criarLista(&cabCau);
    criarListaEncad(ListaEncad);

    while(opt !=8){
        limparTela();
        printf("----------------MENU------------------\n");
        printf("1 - Adicionar nova noticia\n");
        printf("2 - Remover notícia pendente por id\n");
        printf("3 - Remover notícia verificada por palavra-chave\n");
        printf("4 - Buscar noticias pendentes por palavra-chave\n");
        printf("5 - Imprimir as noticias\n");
        printf("6 - Classificar notícias\n");
        printf("7 - Imprimir quantidade de notícias por categoria\n");
        printf("8 - Sair\n");
        printf("Escolha uma opção:\n");
        printf("-------------------------------------------\n\n> ");

        scanf("%d", &opt); 
        limparTela();

        switch(opt){
            case 1:
                Data newData;
                char newTitulo[50], newConteudo[500], newFonte[100];
                TypeClass newClassificacao = 1;

                printf("Insira o título da noticia: \n> ");
                scanf(" %[^\n]", newTitulo);
                printf("\nInsira o conteudo da noticia: \n> ");
                scanf(" %[^\n]", newConteudo);
                printf("\nInsira o fonte da noticia: \n> ");
                scanf(" %[^\n]", newFonte);
                printf("\nDigite o dia, mes e ano da noticia (Exemplo: 25/12/2026): \n> ");
                scanf("%d/%d/%d", &newData.dia,&newData.mes, &newData.ano);

                Noticia *novaNot = criarNoticia(newData, newTitulo, newConteudo, newFonte, newClassificacao);

                inserirNoticiaInicio(&cabCau, *novaNot);
                liberarNoticia(novaNot);

                pausarOSFriendly();
                break;

            case 2:
                int searchID;
                printf("Digite o ID da noticia: \n> ");
                scanf("%d", &searchID);
                if(removerNoticiaID(&cabCau, searchID))
                    printf("Removida com sucesso!");
                else
                    printf("Não foi possivel encontrar!\n");
        
                pausarOSFriendly();
                break;
            case 3:
                
                printf("Digite a palavra-chave:\n> ");
                scanf(" %[^\n]", keyword);

                removerNoticiaKeyword(ListaEncad, keyword);
                pausarOSFriendly();
                break;
            case 4:
                
                printf("Digite a palavra-chave:\n> ");
                scanf(" %[^\n]", keyword);

                imprimirNoticia(buscarKeyword(&cabCau, keyword));
                pausarOSFriendly();
                break;

            case 5:
                int subOpt;
                printf("Qual tipo de noticia deseja ver?\n 1 - Pendentes || 2 - Verificadas || 3 - Ambas\n> ");
                scanf("%d", &subOpt);
                
                if(subOpt != 2){
                    printf("Pendentes: \n");
                    imprimirLista(&cabCau);
                }
                if(subOpt != 1){
                    printf("Verificadas: \n");
                    imprimeListaEncad(ListaEncad);
                }
                pausarOSFriendly();
                break;

            case 6:
                classificarNoticia(&cabCau, ListaEncad);
                pausarOSFriendly();
                break;
            
            case 7:
                qtdNoticias(&cabCau, ListaEncad);
                pausarOSFriendly();
                break;

            case 8:
                liberarListaEncad(ListaEncad);
                liberarLista(&cabCau);
                break;
            default:
                printf("\nOPCAO INVALIDA!\n");
                pausarOSFriendly();
                break;
        }
    }
    
    return 0;
}

void pausarOSFriendly(){
    printf("\nPressione Enter para continuar...");
    getchar(); 
    getchar();
}

void limparTela() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}