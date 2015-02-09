#define MAX_EDGE 50
#define MAX_VALUE 50
#define INF -1

struct edge
{
	int _from;
	int _to;
	int cost;
}

edge ed[MAX_EDGE];
int V,E;
int d[MAX_VALUE];
int prev[MAX_VALUE];
void short(int s){
	int i = 0,j=0;
	for(;i<MAX_VALUE;i++) d[i] = INF;
	d[s] = 0;
	for(;j<MAX_VALUE;j++) {
		prev[j] = INF;
	}
	while(true){
		bool update = false;
		for(i=0; i<E; i++) {
			edge e = es[i];
			if(d[e._from]!=INF && d[e._from] + e.cost < d[e._to]) {
				d[e._to] = e.cost + d[e._from];
				update = true;
				prev[e._to] = d[e._from];
			}
		}
	if(!update) break;
	}
}

void printPath(int s) {
	int jj = 0;
	for(; jj<MAX_VALUE; jj++) {
		int ii = jj;
		while(prev[ii] != s && prev[ii] != INF) {
			printf("%d",ii);
			ii = prev[ii];
		}
		print("%d\n", s);
	}
}
