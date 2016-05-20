#include <stdio.h>
/*
int * limpaVetor(int n,int *primos){
	int i;
	for(i=n;i<n-1;i++){
		primos[i]=1;		
	}
	return primos;
}*/

int main(void){
	//inicializaçao de variaves
	int i,n,posAtual,j;
	
	//leituda de tamanho de n
	scanf("%d",&n);

	//inicializaçao do vetor indicando os primos
	int primos[n-1];
	printf("%d\n",n);

	for(i=0;i<n-1;i++){
		primos[i]=1;

	}

	for(i=0;i<n-1;i++){
		if(primos[i]){
			printf("%d\n",i);		
		}

	}

	
	//verificar e tornar falso o que não for primo
	for(i=0;i<(n/2)-1;i++){
		if(primos[i]){

			//limpaVetor(i+1,primos);
			for(j=i+1;j<n-1;j++){
				if((j+2)%(i+2)==0){
					primos[j]=0;				
				}
			}
		}
		
	}
	//pra indicar que a saida começou
	printf("+++++++++++++\n");		
 	//saida de valores caso o valor continue true
	for(i=0;i<n-1;i++){
		if(primos[i]){
			printf("%d\n",i+2);		
		}	
	}
	return 0;
}	
