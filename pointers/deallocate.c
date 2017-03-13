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

void clear(){
	buffer = inicio;
		while(buffer != NULL){
			aux = buffer;
			printf ("%c", buffer->letra);
			buffer = aux->proximo;
			free (aux);
		}
		printf("\n");
}

void popLetra(){
	printf("%c", inicio->letra);
	inicio = inicio->proximo;
	free(aux);
	aux = inicio;
}

int main (){
	char a;
	int op;

	while(1){
		printf("1 - Insert\n2 - Remove\nOP: ");
		scanf("%d", &op);
		getchar();
		if(op == 1) {
			scanf("%c", &a);
			addLetra(a);
		}
		else if(op == 2){ 
			if(inicio == NULL) printf("Pilha vazia!\n");
			else popLetra();
		}
		else if(op == 0) break;
		else printf("Opção Inválida!\n");
	}
	
	clear();
	
	return 0;
}







