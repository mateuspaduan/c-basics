#include<stdio.h>
#include<stdlib.h>
typedef struct LETRA{
	char letra;
	struct LETRA * proximo;
}let_t;

let_t * inicio;
let_t * buffer;
let_t * aux;

void add(char letra){
	buffer = (let_t *) malloc(sizeof(let_t));
	
	buffer->letra = letra;//(*buffer).letra = letra;
	
	if(inicio == NULL) buffer->proximo = NULL;
	inicio = buffer;
	if(aux!=NULL) buffer->proximo = aux;
	
	aux = buffer;
}

void limpaMemoria(){
	buffer = inicio;
	while(buffer != NULL){
		aux = buffer;
		buffer = buffer->proximo;
		free(aux);
	}
	inicio = NULL;
	aux = NULL;
}
char pop(){
	char letra = inicio->letra;
	aux = inicio;
	inicio = inicio->proximo;
	free(aux);
	aux = inicio;
	return letra;
}
int main(){
	char letra;
	int op;
	
	inicio = NULL;
	aux = NULL;
	
	while(1){
		printf("1-Inserir\n2-Remover\n3-Sair\nOP: ");
		scanf("%d", &op);
		getchar();
		if(op == 1){
			printf("Digite uma letra: ");
			scanf("%c", &letra);
			add(letra);
		} else if(op == 2) {
			if(inicio == NULL) printf("Fila vazia!\n");
			else {
				letra = pop();
				printf("Letra %c removida!\n", letra);
			}
		} else if(op == 3) break;
		else printf("Opção inválida!\n");
	}
	limpaMemoria();
	return 0;
}
