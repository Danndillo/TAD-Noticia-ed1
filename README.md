# SISTEMA GERENCIADOR DE NOTÍCIAS
## Autores 
- [Arthur Torres Gurgel](https://github.com/torrestuh/)
- [Danillo de Paula Carvalho](https://github.com/Danndillo/)

## Contextualização

Trabalho realizado para a disciplina de **Estrutura de Dados I**, ministrada pela professora Drª Juliana Pinheiro Campos Pirovani, componente curricular do curso de Bacharelado em Ciência da Computação da **Universidade Federal do Espírito Santo (UFES)**.

## Descrição do Projeto
O trabalho consiste na implementação de um sistema que registra e gerencia notícias utilizando listas encadeadas como principal estrutura de dados.

O usuário é capaz de:
- Adicionar notícias;
- Remover por ID ou palavra-chave;
- Buscar notícias por palavra-chave;
- Visualizar e classificar as notícias cadastradas.

## Estrutura do Código
O projeto está segmentado da seguinte forma:

- `main.c`: Responsável pela lógica principal e interações com o usuário.
- `Noticia.c / Noticia.h`: Definem o tipo abstrato de dados `Noticia`, seus campos e operações básicas.
- `ListaCabCau.c / ListaCabCau.h`: Implementação de uma lista encadeada com cabeça e cauda.
- `ListaEncadeada.c / ListaEncadeada.h`: Implementação de uma lista simplesmente encadeada.
- `makefile`: Arquivo para a compilação do projeto.

## Estruturas de Dados Utilizadas

Foram implementadas duas variações de listas encadeadas:

- Lista com Cabeça e Cauda (`ListaCabCau`) - Armazena todas as notícias pendentes, definidas como "Em Análise". Gerenciada por uma estrutura `Lista` com dois sentinelas, no começo e fim da lista.

- Lista Encadeada Simples (`ListaEncadeada`) - Armazena notícias já classificadas ("Confiável" ou "Suspeita"). Gerenciada por um ponteiro para o primeiro nó (`NoListaEncad`).

## Funcionalidades do Menu

| Opção | Funcionalidade | Descrição |
|-------|----------------|-----------|
| 1 | Adicionar notícia | Insere nova notícia na lista de notícias pendentes |
| 2 | Remover por ID | Remove notícia específica da lista de pendentes |
| 3 | Remover por palavra-chave | Remove notícia verificada da lista de verificadas |
| 4 | Buscar por palavra-chave | Localiza notícia pendente pela palavra-chave |
| 5 | Imprimir notícias | Exibe para o usuário pendentes, verificadas ou ambas |
| 6 | Classificar notícias | Altera classificação e move entre listas |
| 7 | Quantidade de notícias por tipo | Quantidade por categoria (*Em Análise/Confiável/Suspeita*) |
| 8 | Sair | Encerra o programa |

## Rodando Localmente

Clone o projeto

```bash
    git clone https://github.com/Danndillo/TAD-Noticia-ed1
```

Vá para o diretório do projeto

```bash
    cd TAD-Noticia-ed1
```

Compilar o projeto

```bash
    make
```

Execute o projeto
```bash
    ./trabEd1
```
