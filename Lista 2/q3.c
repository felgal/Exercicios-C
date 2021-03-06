#include <stdio.h>
//declarações de funções secundarias 
int verificaPermutacao(char *p1,char *p2);
int verificaLetra(char l,char *p2);


//função principal para verificar se um valor é permutação de outro
int main(void){
	//declaração e inicialização de variaveis das palavras
	char palavra1[10],palavra2[10];
	scanf("%s",palavra1);
	scanf("%s",palavra2);
	if(verificaPermutacao(palavra1,palavra2)){
		printf("É permutação\n");
	}
	else{
		printf("Não é permutação\n");	
	}
	
}

//montagem das funções anteriormente declaradas

//função para pegar cada letra para verificar se a letra permite ser permutada na outra palavra
int verificaPermutacao(char *p1,char *p2){
	//loop para verificar cada letra
	int i;
	for(i=0;p1[i]!='\0';i++){
		if(!verificaLetra(p1[i],p2)){
			return 0;		
		}	
	}
	if(p2[i]!='\0') return 0;
	return 1;
}
//função para verificar se a letra pode ser permutada na palavra
int verificaLetra(char l,char *p2){
	int quantRepete=0,i;
	for(i=0;p2[i]!='\0';i++){
		if(p2[i]==l){
			quantRepete+=1;		
			if(quantRepete>1){
				return 0;
			}		
		}
	}
	if(quantRepete==1) return 1;
	return 0;
}
