bool find()
{
	memset(d, 0,sizeof(d));
	for(int i = 0;i<V;i++)
		for(j=0; j<E; j++)
		{
			edge e = es[j];
			if(d[e.to]>d[e.from]+[e.cost])
			{
				d[e.to] = d[e.from] +d[e.cost];
				if(i == V-1) return true;
			}
			return false;
		}
}

