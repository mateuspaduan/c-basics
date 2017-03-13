#include <stdio.h>
#include <stdlib.h>

typedef struct B {
	char letra;
	struct B * proximo;
} tipo;

tipo * buffer = NULL;
tipo * aux = NULL;
tipo * inicio = NULL;

void addLetra(char info){
	buffer = (tipo*) malloc (sizeof(tipo));
	
	if(inicio == NULL) buffer->proximo = NULL;
	else buffer->proximo = aux;
	
	inicio = buffer;
	
	buffer->letra = info;
	
	aux = buffer;
}

void printPalavra(){
	buffer = inicio;
		while(buffer != NULL){
			aux = buffer;
			printf ("%c", buffer->letra);
			buffer = aux->proximo;
			free (aux);
		}
		printf("\n");
}

pop(){
	
	
}
int main ()
{
	char a;

	while(scanf("%c", &a) && a != '\n'){
		addLetra(a);
	}
	
	printPalavra();
	
	return 0;
}







