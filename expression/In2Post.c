#include"Stack.h"
void postStr(char *a);
int main(void) {
	char i_str[20]="a+b*c+(d*e+f)*g";//+(d*e+f)";//+(d*e+f)*g\0";
	postStr(i_str);
 }
int judge(char a,char b){
	if(a==b||(a=='*'&&b=='+')){
		return 1;
	}
	else return 0;
}

void postStr(char *a){
	int p;
	//char *temp = malloc(sizeof(char)*20);
	char temp_[15];
	char *temp = &temp_[0];
	Stack s = CreateStack(20);
	int flag = 0;// no handling '('
	//'('=3 > '*'=2 > '+'=1
	while(*a!='\0'){
		if((*a-'a')>=0&&(*a-'a')<=25){
			*temp = *a;
			temp++;
			a++;
		}
		else if(*a=='+'||*a=='*'||*a=='('){
				if(s->top==-1){
					Push(s,*a);
					a++;
				}
				else{
					while(1){
						p = judge(Top(s),*a);
						if(p==1) {
							if(Top(s)!='(') {
								*temp=Top(s);
								Pop(s);
							}
							temp++;
						}
						else if(p==0||IsEmpty(s)){
							Push(s,*a);
							a++;
							break;
						}	
					}
				}
		}
		else if(*a == ')'){
			while(!IsEmpty(s)&&Top(s)!='('){
				*temp=Top(s);
				temp++;
				Pop(s);
			}
			a++;
			Pop(s);
		}
	}
	while(!IsEmpty(s)){
		*temp = Top(s);
		temp++;
		Pop(s);
	}
	printf("%s",temp_);
}
