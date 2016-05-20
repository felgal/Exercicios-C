#include <stdlib.h>
#include <stdio.h>
//funções secundarias
void leSudoku(int **mat){
	int i,j;
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
			scanf("%d",&mat[i][j]);
}

void printaSudoku(int **mat){
	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			printf("%d ",mat[i][j]);
			if((j+1)%3==0 && j!=8)
				printf("|");
		}
		printf(" \n");
		if((i+1)%3==0 && i!=8){
			for(j=0;j<6;j++)
				printf("---");	
		}
		printf("\n");
	}
}
void verificaSudoku(int **mat){
	int i,j;
	for (i=0;i<9;i++)
		for(j=0;j<9;j++)
			if(verificaPonto(mat,i,j,mat[i][j])){
				printf("Não \n");
				return;
			}
	printf("É\n\n");
	return;
}
int verificaPonto(int **mat,int i,int j,int elem){
	if( verificaColuna(mat,i,j,elem) && verificaLinha(mat,i,j,elem) && verificaQuadrado(mat,i,j,elem)){
		return 0;
	}
	
	return 1;
}
//isso verifica a coluna e nao a linha
int verificaLinha(int **mat,int x,int y,int elem){
	int i;
	for (i=0;i<9;i++){
		if (mat[i][y]==elem && i!=x) return 0;
	}
	return 1;
}
int verificaColuna(int **mat,int x,int y,int elem){
	int i;
	for (i=0;i<9;i++)
		if (mat[x][i]==elem && i!=y) return 0;
	return 1;
}

int verificaQuadrado(int **mat,int x,int y,int elem){
	int i,j;
	for (i=(x/3)*3;i<(x/3)*3+3;i++)
		for (j=(y/3)*3;j<(y/3)*3+3;j++)
			if (mat[i][j]==elem && i!=x && j!=y) return 0;
	return 1;
}
//função principal
int main(void){
	//gerando a matriz do sudoku contendo apenas lixo
	int **mat = (int **)malloc(sizeof(int *)*9);
	int i,j;
	for(i=0;i<9;i++) mat[i]=(int*)malloc(sizeof(int)*9);
	//le e coloca os valores lidos na matriz
	leSudoku(mat);
	//printa o sudoku
	printaSudoku(mat);
	//verifica se o sudoku esta correto
	verificaSudoku(mat);
	//fim
	return 0;
}

