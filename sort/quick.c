#include <stdio.h>
#define MAX 10

void quick_sort(int *v, int inicio, int fim){ // ou v[]
	
	int i, f, aux, fred;
	i = inicio;
	f = fim
	fred = v[(f+i)/2];
	
	while(i <= f){
		while(fred > v[i]) i++;
		while(fred < v[j]) j--;
		
		if(i <= f){
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			i++;
			j--;
		}
	}
	if(f>inicio) // nao entra quando o final for menor/igual que o inicio
		quick_sort(v, inicio, f);
	if(i<fim) // nao entra quando o inicio for maior/igual que o final
		quick_sort(v, i, fim);
	
	return;
}

int main(){
	
	int v[MAX] = {61,16,21,71,2,18,89,1,33,12};
	int i;
	//Imprimindo o vetor desordenado:
	printf("Desordenado:\n");
	for(i=0;i<MAX;i++) printf("%d\n", v[i]);
	
	quick_sort(v, 0, MAX-1);
	
	//Imprimindo o vetor ordenado:
	printf("Ordenado:\n");
	for(i=0; i<MAX; i++) printf("%d\n", v[i]);

	return 0;
}
