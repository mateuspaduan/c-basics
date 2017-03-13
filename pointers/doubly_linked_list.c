#include<stdio.h>
#include<stdlib.h>
typedef struct LETRA{
	char letra;
	struct LETRA * proximo;
	struct LETRA * anterior;
}let_t;

let_t * inicio;
let_t * buffer;
let_t * aux;

void add(char letra){
	buffer = (let_t *) malloc(sizeof(let_t));
	
	buffer->letra = letra;//(*buffer).letra = letra;
	buffer->proximo = NULL;
	
	if(inicio == NULL){
		buffer->anterior = NULL;
		inicio = buffer;
	}
	
	if(aux!=NULL) {
		aux->proximo = buffer; 
		buffer->anterior = aux;
	}
	
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
char popFIFO(){
	char letra = inicio->letra;
	buffer = inicio;
	inicio = inicio->proximo;
	if(inicio != NULL) inicio->anterior = NULL;
	free(buffer);
	buffer = inicio;
	return letra;
}
char popLIFO(){
	char letra = aux->letra;
	buffer = aux;
	aux = aux->anterior;
	if(aux != NULL) aux->proximo = NULL;
	free(buffer);
	buffer = aux;
	return letra;
}
int main(){
	char letra;
	int op;
	
	inicio = NULL;
	aux = NULL;
	
	while(1){
		printf("1-Inserir\n2-Remover Primeiro\n3-Remover Último\n4-Sair\nOP: ");
		scanf("%d", &op);
		getchar();
		if(op == 1){
			printf("Digite uma letra: ");
			scanf("%c", &letra);
			add(letra);
		} else if(op == 2) {
			if(inicio == NULL) printf("Lista vazia!\n");
			else {
				letra = popFIFO();
				printf("Letra %c removida!\n", letra);
			}
		} else if(op == 3){
			if(aux == NULL) printf("Lista vazia!\n");
			else {
				letra = popLIFO();
				printf("Letra %c removida!\n", letra);
			}
		}else if(op == 4) break;
		else printf("Opção inválida!\n");
	}
	limpaMemoria();
	return 0;
}
