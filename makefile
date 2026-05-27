all: compila
compila: main.o Noticia.o ListaCabCau.o ListaEncadeada.o
		gcc main.o Noticia.o ListaCabCau.o ListaEncadeada.o -o trabEd1
main.o: main.c
		gcc -c main.c
Noticia.o: Noticia.c
		gcc -c Noticia.c
ListaCabCau.o: ListaCabCau.c
		gcc -c ListaCabCau.c
ListaEncadeada.o: ListaEncadeada.c
		gcc -c ListaEncadeada.c
clean:
		ifeq ($(OS),Windows_NT)
			del /Q *.o trabEd1.exe
		else
			rm -f *.o trabEd1
		endif
.PHONY: clean
