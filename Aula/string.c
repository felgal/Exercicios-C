void f(char *s1,char *s2){
	int i;
	for(i=0;s1[i]!='\0';i++);
	int j=0;
	while(s2[j]!='\0'){
		s1[i+j]=s2[j];
		j++;	
	}
	s1[i+j]='\0';
}

int cmp(char*s1,char*s2){
	int i=0;
	while((s1[i]!='\0') && (s2[i]!='\0')){
		if(s1[i]>s2[i])
			return 1;
		if(s1[i]<s2[i])
			return -1;
	}
	if(s1[i]==s2[i])return 0;
	if(s1[i]=='\0')return -1;
	return 1;
}
int cmp-rec(char *s1,char*s2){
	if((s1[0]=='\0') &&(s2[0]=='\0') return 0;
	if((s1[0]=='\0') ||(s1[0]<s2[0]) return -1;
	if((s2[0]=='\0') ||(s1[0]>s2[0]) return 1;
	return cmp-rec(&s1[1],&s2[1]);
}
