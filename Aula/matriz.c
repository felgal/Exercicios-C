#include <stdio.h>
#include <stdlib.h>
int **misc(int**mat,int l,int c);
int eSim(int **mat,int l,int c);
int main(void){
	int l,c;
	scanf("%d%d",&l,&c);
	if((l<=0)||(c<=0)) return 0;
	int **mat = (int **)malloc(sizeof(int *)*l);
	int i,j;
	for(i=0;i<l;i++) mat[i]=(int*)malloc(sizeof(int)*c);
	for(i=0;i<l;i++)
		for(j=0;j<c;j++)
			scanf("%d",&mat[i][j]);
	int **resp=misc(mat,l,c);
	if(eSim(mat,l,c))
		imp_sim(resp,l);	
	else
		imprime(resp,l,c);
	desaloca(resp,c);
	desaloca(mat,l);
	return 0;
}

int eSim(int **mat,int l,int c){
	if(l!=c) return 0;
	int i,j;
	for(i=0;i<l;i++)
		for(j=i+1;j<l;j++)
			if(mat[i][j]!=mat[j][i])
				return 0;
	return 1;	
}
int **misc(int **mat,int l,int c){
	int resp-sim=eSim(mat,l,c);
	int **resp,i,j;
	if(resp-sim){
		resp=(int **)malloc(sizeof(int *)*l);
		for(i=0;i<l;i++)
			resp[i]=(int *)malloc(sizeof(int)*(i+1));					
		for(i=0;i<l;i++)
			for(j=0;j<=i;j++)
				resp[i][j]=mat[i][j];	
	
	}
	else{
		resp=(int **)malloc(sizeof(int *)*c);
		for(i=0;i<c;i++)
			resp[i]=(int *)malloc(sizeof(int)*l);					
		for(i=0;i<l;i++)
			for(j=0;j<=c;j++)
				resp[j][i]=mat[i][j];	
	
	}
	return resp;
	
}
void desaloca(int **mat,int l){
	int i;
	for(i=0;i<l;i++)
		free(mat[i]);
	free(mat);
}

void imprime(int **mat,int l,int c){
	int i,j;
	for(i=0.i<l;i++){
		for(j=0;j<c;j++)
			prinf("%d ",mat[i][j]);
		printf("\n");
	}
}	

void imp_sim(int **mat,int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++)
			printf("%d ",mat[i][j]);
		printf("\n");	
	}
}

