#define MAX 100
//m is length of p
char *compute(char *a,int m);
int KMPMatch(char *T,char* P);

int *compute(char a[],int m){
	int PI[MAX],q;
	int *temp=&PI[0];
	PI[1] = 0;
	k=0;
	for(q=2;q<=m;q++){
		while(k>0 && a[k+1]!=a[q])
			k=PI[k];
		if(a[k+1]==a[q])
			k++;
		PI[q] = k;
	return temp;
}

int KMPMatch(char *T,char *P,int m,int n){
	int *a;
	int i;
	int q = 0;
	a=compute(T,m);
	for(i=0;i<n;i++){
		while(q>0&&P[q+1]!=T[i])
			q=a[q];
		if P[q+1] == T[i]
			q=q+1;
		if q==m
			q=a[q];
	}

}
