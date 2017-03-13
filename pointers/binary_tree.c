#include<stdio.h>
#include<stdlib.h>

typedef struct NO{
	char conteudo[20];
	int cod;
	struct NO * right;
	struct NO * left;
}ramo;

ramo * root;
ramo * buffer;
ramo * aux;


void strcopy(char * nome1, char * nome2){
  int i=0;
  while(nome2[i] != '\0'){
    nome1[i] = nome2[i];
    i++;
  }
  nome1[i] = '\0';
}

int strcomp(char * nome1, char * nome2){
  int i=0;
  while(nome1[i] != '\0' && nome2[i] != '\0'){
    if(nome1[i] < nome2[i]) return -1;
    else if(nome1[i] > nome2[i]) return 1;
  }
  if(nome1[i] == '\0' && nome2[i] == '\0') return 0;
  else if(nome1[i] != '\0' && nome2[i] == '\0') return 1;
  else if(nome1[i] == '\0' && nome2[i] != '\0') return -1;
  
}

void listagem(ramo * aux){
  if(aux->left != NULL) listagem(aux->left);
  printf("%s - %d\n", aux->conteudo, aux->cod);
  if(aux->right != NULL) listagem(aux->right);
}

int buscar(char * nome){
  aux = root;
    while(1){
      int cmp = strcomp(aux->conteudo, nome);
      if(cmp > 0) 
        if(aux->left != NULL) aux = aux->left;
        else return -1;
      else if(cmp < 0)
        if(aux->right != NULL) aux = aux->right;
        else return -1;
      else return aux->cod;
      
    }
}

void add(char * conteudo, int cod){
	buffer = (ramo *) malloc(sizeof(ramo));
	
	strcopy(buffer->conteudo, conteudo);//(*buffer).letra = letra;
	buffer->cod = cod;
	buffer->right = NULL;
	buffer->left = NULL;
	
	if(root == NULL) root = buffer;
  else{
    aux = root;
    while(1){
      if(strcomp(buffer->conteudo, aux->conteudo) < 0)
        if(aux->left == NULL){ 
          aux->left = buffer;
          break;
        }
        else aux = aux->left;
      else
        if(aux->right == NULL){
          aux->right = buffer;
          break;
        }
        else aux = aux->right;
    }
  }
}

void limpaMemoria(){
	buffer = root;
	while(buffer != NULL){
		aux = buffer;
		buffer = buffer->right;
		free(aux);
	}
	root = NULL;
	aux = NULL;
}

int main(){
	char nome[20];
	int op, cod;
	
	root = NULL;
	aux = NULL;
	while(1){
	  printf("1-Inserir\n2-Listar\n3-Buscar\nSair\nOP: ");
	  scanf("%d", &op);
	  getchar();
	  switch(op){
	    case 1:
	      printf("Digite um nome: ");
	      scanf("%s", nome);
	      printf("Digite um codigo: ");
	      scanf("%d", &cod);
	      add(nome, cod);
	      break;
	    case 2:
	      if(root != NULL) listagem(root);
	      else printf("Árvore vazia!\n");
	      break;
	    case 3:
	      if(root == NULL) printf("Árvore vazia!\n");
	      else {
	        printf("Pokename: ");
	        scanf("%s", nome);
	        cod = buscar(nome);
	        if(cod > 0) printf("cod = %d", cod);
	        else printf("Nome nao encontrado!\n");
	      } 
	      break;
	    case 4:
	      return 0;
	    default:
	      printf("Opção Inválida!\n");
	      break;
	  }
	}
	limpaMemoria();
	return 0;
}
