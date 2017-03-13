#include <stdio.h>
#define MAX 10

void quick_sort(int *v, int inicio, int fim){ // ou v[]
	
	int i, f, aux, fred;
	i = inicio;
	f = fim;
	fred = v[(f+i)/2];
	
	while(i <= f){
		while(fred > v[i]) i++;
		while(fred < v[f]) f--;
		
		if(i <= f){
			aux = v[i];
			v[i] = v[f];
			v[f] = aux;
			i++;
			f--;
		}
	}
	if(f>inicio) // nao entra quando o final for menor/igual que o inicio
		quick_sort(v, inicio, f);
	if(i<fim) // nao entra quando o inicio for maior/igual que o final
		quick_sort(v, i, fim);
	
	return;
}

int main(){
	
	int v[MAX] = {61,16,21,71,2,18,89,1,33,12}, i;
	//Imprimindo o vetor desordenado:
	printf("desordenado:\n");
	for(i=0;i<MAX;i++) printf("V[%d] = %d\n", i, v[i]);
	
	int cade_o, flag=0;
	
	scanf("%d", &cade_o);
	
	quick_sort(v, 0, MAX-1);
	printf("ordenado:\n");
	for(i=0;i<MAX;i++) printf("V[%d] = %d\n", i, v[i]);
	
	int inicio=0, fim=MAX-1, meio;
	
	while(inicio <= f){
		meio=(inicio+fim)/2;
		if(cade_o < v[meio]) fim=meio-1;
		else(cade_o > v[meio]) inicio=meio+1;
		else{
			printf("Elemento %d está na posição %d\n", v[meio], meio);	//flag = 1;
			break;
		}
	}
	
	//v[meio] != cade_o  ou  flag
	if(inicio > fim) printf("Elemento %d não foi encontrado!", cade_o);
	
	return 0;
}
