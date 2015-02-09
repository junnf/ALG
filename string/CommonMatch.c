//pnum is length of p-string
int CommonMatch(char *p, char *t,int pnum ) {
	int s = 0,flag = 0;
	int i;
	char *temp = NULL;
	char *_temp = p;
	for(;*t != '\0' && flag == 0;t++,s++) {
		_temp = p;
		temp=t;
		i=0;
		for(; i<pnum; i++,_temp++) { 
			if(*_temp == *temp)
			{
				if(i == pnum-1){	
					flag=1;
					break;
				}
				temp++;	
			}
			else {
				break;
			}
		}
	}
	if(flag==0){
		s = 0;
	}
	return s;
}
