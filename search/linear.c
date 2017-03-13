#include <stdio.h>
#define MAX 10

int main(){
	
	int v[MAX] = {61,16,21,71,2,18,89,1,33,12}, i;
	//Imprimindo o vetor desordenado:
	
	for(i=0;i<MAX;i++) printf("V[%d] = %d\n", i, v[i]);
	
	int cade_o, flag=0;
	
	scanf("%d", &cade_o);
	
	for(i=0;i<MAX;i++)
		if(cade_o == v[i]){
			printf("Elemento %d está na posição %d\n", v[i], i); //usar o vetor para mostrar, não o elemento buscado;
			break;
		}
			
	if(i == MAX) printf("Elemento %d não encontrado!\n", cade_o);
	
	return 0;
}
