#include<iostream>
using namespace std;

//inf is a random number>=11
const int inf = 11;
typedef class{
	public:
		int r,c;
		bool mov; //if mov = true , in moving status
}LC;

LC s,g;
int mstp;//the shortest step
int w,h;//size of ground
int field[25][25];
void dfs(int i,int j,bool mov,int direction,int step,bool crash)
{
	if(step>10)
			return; //cut branch
	if(field[i][j] == 3){
			if(mstp>=step)
				mstp = step;
			return;
		}
	if(crash){
		//crash stone status
		switch(direction)
		case 0: {field[i-1][j]=0;break;}
		case 1: {field[i][j+1]=0;break;}
		case 2: {field[i+1][j]=0;break;}
		case 3: {field[i][j-1]=0;break;}
	}
	if(!mov){
		if(i-1>=1 && (field[i-1][j]==0 || field[i-1][j]==3))
			dfs(i-1,j,true,0,step+1,false);
		if(j+1<=w && (field[i][j+1]==0 || field[i][j+1]==3))
			dfs(i,j+1,true,1,step+1,false);
		if(i+1<=h && (field[i+1][j]==0 || field[i+1][j]==3))
			dfs(i+1,j,true,2,step+1,false);
		if(j-1>=1 && (field[i][j-1]==0 || field[i][j-1]==3))
			dfs(i,j-1,true,3,step+1,false);}
	else if(mov)
		{
			switch(direction)
			{
			case 0:{
				if(i-1<1)
					return;
			   else{if(field[i-1][j] == 0)
						dfs(i-1,j,true,0,step,false);
					if(field[i-1][j] == 1)
						dfs(i,j,false,0,step,true);
					else if(field[i-1][j] == 3)
						dfs(i-1,j,false,0,step,false);
					}
				   }
			//then the rest condition is the same as the upper
				  // {
				   
				  // }
				   
				  
				  // {
				   
				  // }
				  
				  
				  // {
				   
				  // }
			}
		}
		if(crash)
		{
			switch(direction)
			{
				case 0: {field[i-1][j]=1;break;}
				case 1: {field[i][j+1]=1;break;}
				case 2: {field[i+1][j]=1;break;}
				case 3: {field[i][j-1]=1;break;}
			}
		}
	return;
}

int main(void)
{
	while(cin>>w>>h)
	{
		if(!w && !h)
			break;
		mstp = inf;
		for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++
				{
				cin>>field[i][j];
				if(field[i][j]==2)
				{	s.r=i;s.c=j; mov=false; }
				if(field[i][j]==3)
				{	g.r=i;g.c=j;}
				}
	dfs(s.r,s.c,s.mov,0,0,false);
	if(mstp<=10)
		cout<<mstp<<endl;
	else
		cout<<-1<<endl;
	}
	return 0;
}

