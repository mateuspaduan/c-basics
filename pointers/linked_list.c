#include <stdio.h>
#include <stdlib.h>

typedef struct LETRA{
	
	char conteudo;
	struct LETRA * next;
}tipoLetra;

void add(tipoLetra ** nome, tipoLetra ** ref, char letra){
	tipoLetra * buffer;
	buffer = (tipoLetra *)malloc(sizeof(tipoLetra));
	cN->next = NULL;
	cN->conteudo = letra;
	
	
	
	if(nome == NULL){
		*nome = (tipoLetra *)malloc(sizeof(tipoLetra));// nome = cN;
		*ref = cN;
	}
	else{ *ref->next = cN;
				*ref = *ref->next;
	/*
		(*nome).next = (tipoLetra *)malloc(sizeof(tipoLetra));//*nome = conteudo de nome	
		//ou
		//nome->next = ....
		nome->next->letra = letra;
	*/
	
	}
}

void list(tipoLetra nome){
	tipoLetra * aux = nome;
	while(aux != NULL){
		printf("%d", aux->conteudo);
		aux = aux->next;
		free(aux);
	};
	
}

int main(){

	tipoLetra * nome = NULL;
	tipoLetra * ref = NULL;
	
	char letra;
	
	printf("Digite seu nome: ");
	while(scanf("%c", &letra) != '\n')
		add(&nome, &ref, letra);
	
	
	list(nome);
	
	
	printf("\n");

	return 0;
}

/*
	int qtd;
	printf("Quantas letras tem seu nome? ");
	scanf("%d", &qtd);
	
	
	nome = (char *) malloc(sizeof(char)*(qtd+1));
														//num de posições
					//char nome[qtd+1];
					
	scanf("%s", nome);
	*/
