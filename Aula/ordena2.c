#include <stdio.h>
#include <stdlib.h>
void ordena(int *vet,int n);
int* ordena2(int *vet,int n);
int main(void){
	int n;
	scanf("%d",&n);
	if(n<=0) return 0;
	int vet[n],i;
	for(i=0;i<n;i++){
		scanf("%d",&vet[i]);	
	}
	int* resp = ordena2(vet,n);
	for(i=0;i<n;i++)
		printf("%d ",resp[i]);
	free(resp);
	return 0;
}

int *ordena2(int *vet,int n){
	int *resp = (int *)malloc(sizeof(int)*n);
	int i;
	for(i=0;i<n;i++)
		resp[i]=vet[i];
	ordena(resp,n);
	return resp;
}

void ordena(int* vet,int n){
	int i;
	for(i=0;i<n;i++){
		int menor=i,j;
		for(j=i+1;j<n;j++){
			if(vet[menor]>vet[j])menor=j;
		}
		if(menor!=i){
		int temp=vet[i];
		vet[i]=vet[menor];
		vet[menor]=temp;
		}
	}
}
