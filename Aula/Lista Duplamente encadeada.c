typedef struct lista2{
	int info;
	struct lista2 *ant,*prox;
}TLDE;

TLDE *ins_ini(TLDE *l,int elem){
	TLDE *novo=(TLDE *)malloc(sizeof(TLDE));
	novo->info=elem;
	novo->prox=l;
	novo->ant=NULL;
	if(!l) l->ant=novo;
	return novo;
}
TLDE *retira(TLDE *l,int elem){
	TLDE *p=busca(l,elem);
	if(!p) return l;
	if(p==l) l=l->prox;
	else p->ant->prox=p->prox;
	if(p->prox) p->prox->ant=p->ant;
	free(p);
	return l;
}

TLDE *ins_fim(TLDE *l,int elem){
	if(!l) return ins_ini(l,elem);
	TLDE *p=l;
	while(p->prox)p=p->prox;
	p->prox = ins_ini(p->prox,elem);
	p->prox->ant=p;
	return l;
}

TLDE *ins_fim_rec(TLDE *l,int elem){
	if(!l) return ins_ini(l,elem);
	if(!l->prox){
		l->prox=ins_ini(l,elem);
		l->prox->ant=l;
		return l;
	}
	l->prox=ins_fim_rec(l->prox,elem);
	return l;
}
