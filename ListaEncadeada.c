typedef struct data {
    int dia;
    int mes;S
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

Noticia* criarNoticia(int newId, Data newData, char newTitulo[], char newConteudo[], char newFonte[], TypeClass newClassificacao){
  Noticia *novo = (Noticia *) malloc(sizeof(Noticia));
  if(novo !=NULL){
    novo->id = newId;
    novo->data = newData;
    strcpy(novo->titulo, newTitulo);
    strcpy(novo->conteudo, newConteudo);
    strcpy(novo->fonte, newFonte);
    novo->tipo = newClassificacao;
  } else {

  }
  
  
  return novo;
}

void imprimirNoticia(Noticia* n){
  if(n!=NULL){
    printf("#%d - %s\n", n->id, n->titulo);
    printf("\n%d/%d/%d\n",n->data.dia,n->data.mes,n->data.ano);
    printf("%s\n\n", n->conteudo);
    printf("Fonte: %s\n", n->fonte);
    switch(n->tipo){
        case 1:
            printf("Tipo: Em Analise");
            break;
        case 2:
            printf("Tipo: Confiavel");
            break;
        case 3:
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