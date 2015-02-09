#include<iostream>
#include<vector>
#include<memory>
#include<string.h>
#define MAX 50
#define INF 10000
using namespace std;
struct edge {int to, cap, rev; };
vector<edge> G[MAX];
bool used[MAX];

//int min(int a,int b);
int dfs(int v,int t,int f);
int max_flow(int s,int t);
void add_edge(int from, int to ,int cap);
int main(){
	//test 5
	add_edge(0, 1, 10);
	add_edge(0, 2, 2);
	add_edge(1, 2, 6);
	add_edge(1, 3, 6);
	add_edge(3, 2, 3);
	add_edge(3, 4, 8);
	add_edge(2, 4, 5);
/*	G[0][0].to = 1 ;
	G[0][0].cap = 10; 
	G[0][0].rev = 0;*/
/*	G[0][1].to = 2;
	G[0][1].cap = 2;
	G[0][1].rev = 0;
	G[1][0].to = 2;
	G[1][0].cap = 6;
	G[1][0].rev = 0;
	G[1][1].to = 3;
	G[1][1].cap = 6;
	G[1][1].rev = 0;
	G[2][0].to = 4;
	G[2][0].cap = 5;
	G[2][0].rev = 0;
	G[3][0].to = 2;
	G[3][0].cap = 3;
	G[3][0].rev = 0;
	G[3][1].to = 4;
	G[3][1].cap = 8;
	G[3][1].rev = 0;
	*/
	int ff_;
	ff_ = max_flow(0,4);
	cout <<ff_<< endl;
	return 0;
}

int dfs(int v,int t,int f){
	if (v == t) return f;
	used[v] = true;
	int i=0;
	for(i=0;i<G[v].size();i++)
		{
			edge &e = G[v][i];
			if(!used[e.to] && e.cap > 0) {
				int d = dfs(e.to, t, min(f,e.cap));
				if(d>0)	{
					e.cap -= d;
					G[e.to][e.rev].cap += d;	
					return d;
				}
			}
		}
	return 0;
}

int max_flow(int s,int t){
	int flow = 0;
	while(1){
		memset(used, 0, sizeof(used));
		int f = dfs(s,t,INF);
		if(f == 0) return flow;
		flow += f;
	}
}

void add_edge(int from, int to ,int cap) {
	G[from].push_back((edge){to, cap, G[to].size()});
	G[to].push_back((edge){from, 0, G[from].size() - 1});

}
