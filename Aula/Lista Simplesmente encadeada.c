//Estrutura basica de lista
/*typedef struct lista{
	int info;
	struct lista *prox;
}TLSE;

TLSE *inicializa(void){
	return NULL;
}

TLSE *l=inicializa()

TLSE *ins_ini(TLSE *l,int elem){
	TLSE *novo=(TLSE *)malloc(sizeof(TLSE));
	novo->info=elem;
	novo->prox=l;
	return novo;
}*/

void imprime(TLSE *l){
	while(l){
		printf("%d",l->info);
		l=l->prox;	
	}
}

void imp_rec(TLSE *l){
	if(l){
		// se inverter as linhas de baixo,ele imprime invertido
		printf("%d",l->info);
		imp_rec(TLSE *l);	
	}
}

void libera(TLSE *l){
	TLSE *t;
	while(t){
		t-l;
		l=l->prox;
		free(t);	
	}
}

void libera_rec(TLSE *l){
	if(l){
		lib_rec(l->prox);
		free(l);	
	}

}

TLSE *busca(TLSE *l,int elem){
	TLSE *resp=l;
	while((resp)&&(resp->info!=elem)){
		resp=resp->prox;
	}
	return resp;
}

TLSE *busca_rec(TLSE *l,int elem){
	if((!l)||(l->info==elem)) return l;
	return busca_rec(l->prox,elem);	
}

TLSE *ins_fim(TLSE *l,int elem){
	if(!l) return ins_ini(l,elem);
	TLSE *p=l;
	while (p->prox) p = p->prox;
	p->prox=ins_ini(NULL,elem);
	return l;
}

TLSE *ins_fim_rec(TLSE *l,int elem){
	if(!l) return ins_ini(l,elem);
	l->prox=ins_fim_rec(l->prox,elem);
	return l;
}

TLSE *ins_ord(TLSE *l,int elem){
	TLSE *p=l,*ant=NULL;
	while((p)&&(p->info<elem)){
		ant=p;
		p=p->prox;	
	}
	if(!ant)return ins_ini(l,elem);
	p=ins.ini(p,elem);
	ant->prox=p;
	return l;
}

TLSE *ins_ord_rec(TLSE *l,int elem){
	if((!l)||(l->info>=elem)) return ins_ini(l,elem);
	l->prox=ins_ord_rec(l->prox,elem);
}

TLSE *retira(TLSE *l,int elem){
	TLSE *ant=NULL,*p=l;
	while((p)&&(p->info!=elem)){
		ant=p;
		p=p->prox;	
	}
	if(!p) return l;
	else ant->prox = p->prox;
	free(p);
	return l;
}

TLSE *ret_rec(TLSE *l,int elem){
	if (!l) return NULL:
	if(l->info==elem){
		TLSE *p=l;
		l=l->prox;
		free(p);
		return l;	
	}
	l->prox=ret_rec(l->prox,elem);
	return l;
}


