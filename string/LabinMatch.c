#include<stdio.h>
#include<stdlib.h>
//use a power func
//#include"../math.h"
#define MAX 1000

//P[] is match string, T[] as Text String
//like num-string
int RabinMatch(int num_p[], int num_t[], int nump, int numt, int d, int prime);
//KMP
int squ(int d,int n){
	int i;
	int s = 1;
	for(i=0;i<n;i++){
		s*=d;
	}
	return s;
}
//Honor ?

//prime was chosen by word-length
int RabinMatch(int num_p[], int num_t[], int nump, int numt, int d, int q) {
	int s = 0;
	int i = 0;
	int h = squ(d, nump-1);
	//pre-handle ? 
	int p = 0;
	int t0_ = 0;
	int temp=0;
	for(; i<nump; i++)
		{
			p = (d*p + num_p[i]) % q;
			t0_ = (d*t0_ + num_t[i]) % q;
		}
	//create (n-m+1) size array
	int Ts[MAX];
	Ts[0] = t0_;
	s=0;
	for(; s<=numt-nump; s++){
		if(p == Ts[s]){
			while(temp<=nump){
				if(num_t[temp]==num_p[temp]) {
					temp++;
					if(temp==nump){
						return s;
					}
				}
			}
		} 
		else if(s < (numt-nump)) {
			Ts[s+1] = (d*(Ts[s]-(num_t[s+1]*h)) + num_t[s+nump+1]) % q; 
		}
	}
	//
	return s;
}

int main() {
	
	//CommonMatch(char  *p, char *t, int pnum);
	int a =squ(2,10);
	printf("%d",a);
	return 0;
}
