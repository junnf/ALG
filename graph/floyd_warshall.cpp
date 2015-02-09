int d[MAX_V][MAX_V]
void floyd_warshall()
{
	for(int k; k<V; k++)
		for(int i = 0; i<V; i++)
			for(int j=0; j<V; j++) {
				d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
			}
}

