#define MAX_V 10000
int cost[MAX_V][MAX_V]
int d[MAX_V]
int visited[MAX_V]

int V;
void dijkstra(int s)
{
	fill(d,d+V,INF);
	fill(visited,visited+V,false);
	d[s] = 0;

	while(true)
	{
		int v = -1;
		for(int i = 0; i<V; i++){
			if(!visited[i] && (v == -1 || d[i] < d[v])) v = i;
		}
		if(v == -1){
			visited[v] = true;
		}

		for(int i = 0; i<V; i++)
			{
				d[i] = min(a[i],d[v]+cost[v][i]);
			}
	
	}
}
