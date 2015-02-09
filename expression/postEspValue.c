#include"Stack.h"


int postfixValue(char *expression);


int main(void){
	char exp[8]="12+1+2-\0";
	int a = postfixValue(exp);	
}

int postfixValue(char *expression){
	Stack s = CreateStack(40);
	int ss;
	char temp1[2],temp2[2],str[2];
	int tempCal;
	while(*expression!='\0'){
		//atoi char -> int
		//itoa int -> char
		if(((*expression-'0')<=9)&&((*expression-'0')>=0)){
			Push(s,*expression);
		}
		else {
			temp1[0] = Top(s);
			Pop(s);
			temp2[0] = Top(s);
			Pop(s);
			if(*expression == '+')
			{	ss = atoi(temp1) + atoi(temp2);}
			else if(*expression == '-')
			{	ss = -(atoi(temp1) - atoi(temp2));}
			else if(*expression == '*')
			{ss = atoi(temp1) * atoi(temp2);}
			else{
				ss = atoi(temp1) / atoi(temp2);
			}
			sprintf(str,"%d",ss);
			Push(s,*str);
		}
		expression++;
	}
	temp1[0] = Top(s);
	printf("%c",temp1[0]);
	return 0;
}

