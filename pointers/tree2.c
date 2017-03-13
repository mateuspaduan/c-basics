#include<stdio.h>
#include<stdlib.h>
typedef struct NO{
	char nome[20];
	int matricula;
	struct NO * direita;
	struct NO * esquerda;
}no_t;

no_t * raiz;
no_t * buffer;
no_t * aux;

void strcopy(char * str1, char * str2){
	int i=0;
	while(str2[i] != '\0'){
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0';
}

int strcomp(char * str1, char * str2){
	int i=0;
	while(str1[i] != '\0' && str2[i] != '\0'){
		if(str1[i] < str2[i]) return -1;
		else if(str1[i] > str2[i]) return 1;
		i++;
	}
	if(str1[i] == '\0' && str2[i] == '\0') return 0;
	else if(str1[i] != '\0' && str2[i] == '\0') return 1;
	else if(str1[i] == '\0' && str2[i] != '\0') return -1;
}

void listagem(no_t * aux){
	if(aux->esquerda != NULL) listagem(aux->esquerda);
	printf("%s - %d\n", aux->nome, aux->matricula);
	if(aux->direita != NULL) listagem(aux->direita);
}

int busca(char * nome){
	aux = raiz;
	while(1){
		int cmp = strcomp(aux->nome, nome);
		if(cmp > 0) {
			if(aux->esquerda != NULL) aux = aux->esquerda;
			else return -1;
		}
		else if(cmp < 0) {
			if(aux->direita != NULL) aux = aux->direita;
			else return -1;
		} else return aux->matricula;
	}
}

void add(char * nome, int mat){
	buffer = (no_t *) malloc(sizeof(no_t));
	
	strcopy(buffer->nome, nome);
	buffer->matricula = mat;
	buffer->direita = NULL;
	buffer->esquerda = NULL;
	
	if(raiz == NULL) raiz = buffer;
	else{
		aux = raiz;
		while(1){
			if(strcomp(aux->nome, buffer->nome) > 0){
				if(aux->esquerda == NULL){ 
					aux->esquerda = buffer;
					break;
				}
				else aux = aux->esquerda;
			} else {
				if(aux->direita == NULL){
					aux->direita = buffer;
					break;
				}
				else aux = aux->direita;
			}
		}
	}
	
}
int main(){
	
	char nome[20];
	int op, mat;
	
	raiz = NULL;
	aux = NULL;
	
	while(1){
		printf("1-Inserir\n2-Listar\n3-Buscar\n");
		printf("4-Sair\nOP: ");
		scanf("%d", &op);
		getchar();
		switch(op){
			case 1:
				printf("Digite um nome: ");
				scanf("%s", nome);
				printf("Digite a matricula: ");
				scanf("%d", &mat);
				add(nome, mat);
				break;
			case 2:
				if(raiz != NULL) listagem(raiz);
				else printf("Árvore vazia!\n");
				break;
			case 3:
				if(raiz == NULL) printf("Árvore vazia!\n");
				else {
					printf("Digite o nome a ser buscado: ");
					scanf("%s", nome);
					mat = busca(nome);
					if(mat != -1)
						printf("A matricula de %s é %d\n", nome, mat);
					else
						printf("Não existe o nome buscado!\n");
				}
				break;
			case 4:
				return 0;
			default:
				printf("Opção inválida!\n");
				break;
		}
	}
	return 0;
}
