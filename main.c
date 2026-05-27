#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Noticia.h"
#include "ListaCabCau.h"

//setlocale(LC_ALL, "pt-br");
void limparTela();

int main(){

    int opt=0;
    Lista cabCau;
    criarLista(&cabCau);

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

        switch(opt){
            case 1:
                Data newData;
                char newTitulo[50], newConteudo[500], newFonte[100];
                TypeClass newClassificacao;

                printf("Insira o título da noticia: \n> ");
                scanf(" %[^\n]", newTitulo);
                printf("\nInsira o conteudo da noticia: \n> ");
                scanf(" %[^\n]", newConteudo);
                printf("\nInsira o fonte da noticia: \n> ");
                scanf(" %[^\n]", newFonte);
                printf("\n A noticia e:\n1 - Em analise | 2 - Confiavel | 3 - Suspeita\n> ");
                scanf("%d", &newClassificacao);
                printf("Digite o dia, mes e ano da noticia: \n> ");
                scanf("%d %d %d", &newData.dia,&newData.mes, &newData.ano);

                Noticia *novaNot = criarNoticia(newData, newTitulo, newConteudo, newFonte, newClassificacao);

                inserirNoticiaInicio(&cabCau, *novaNot);
                liberarNoticia(novaNot);

                printf("\nNoticia adicionada com sucesso!");
                printf("\nPressione Enter para continuar...");
                getchar(); 
                getchar();
                break;

            /*case :
            case :
            case :
            case :
            case :
            case :*/
            case 8:
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }
    /*
    Data temp = {.dia = 1, .mes = 1, .ano = 2005};
    Noticia *novaNot = criarNoticia(1, temp, "Escala 6x1", "Bluebird Bluebird Bluebird Bluebird Bluebird", "G1", 4);
    
    inserirNoticiaInicio(&cabCau, *novaNot);
    liberarNoticia(novaNot);
    novaNot = criarNoticia(2, temp, "Escala 5x2", "Helter Skelter", "Uol", 1);
    inserirNoticiaInicio(&cabCau, *novaNot);
    imprimirLista(&cabCau);*/
    return 0;
}

void limparTela() {
#ifdef _WIN32
	system("cls"); // Windows
#else
	system("clear"); // Linux/Mac
#endif
}
