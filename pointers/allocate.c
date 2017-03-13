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
	if(inicio == NULL) buffer->anterior = NULL;

	if(inicio == NULL) inicio = buffer;
	if(aux != NULL) {
		aux->proximo = buffer;
		buffer->anterior = aux;
	}
	aux = buffer;
}

void listFila(){
	buffer = inicio;
	while(buffer != NULL){
		printf("%c", buffer->letra);
		buffer = buffer->proximo;
	}
	printf("\n");
}

void listPilha(){
	buffer = aux;
	while(buffer != NULL){
		printf("%c", buffer->letra);
		buffer = buffer->anterior;
	}
	printf("\n");
}

void limpaMemoria(){
	buffer = inicio;
	while(buffer != NULL){
		aux = buffer;
		buffer = buffer->proximo;
		free(aux);
	}
}
int main(){
	
	char letra;
	
	while(1){
		inicio = NULL;
		aux = NULL;
		
		//Entrada da string
		printf("Digite seu nome: ");
		while(scanf("%c", &letra) && letra != '\n')
			add(letra);
	
		//Imprime a string
		printf("Seu nome é ");
		listFila();
		
		printf("Seu ao contrário nome é ");
		listPilha();
	
		//Limpa memória
		limpaMemoria();
	}
	
	return 0;
}
