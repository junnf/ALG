#include<iostream>
using namespace std;

int main(void)
{
	int p,e,i,d;
	int time = 1;
	while(cin>>p>>e>>i>>d)
	{
		if(p==-1 && e==-1 i==-1 && d==-1)
			break;
		int xin = 21252;
		int n=(5544*p+14421*e+1288*i-d+21252)%21252;
		if(n==0)
			n = 21252;
		cout<<n<<endl;
	}
	return 0;
}
