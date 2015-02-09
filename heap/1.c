#define MA
int heap[MA],sz=0;

//small top heap insert
void push(int x)
{
	int i = sz++;
	while(i>0)
	{
		int p = (i - 1)/2;
		if(heap[p] <= x)
			break;
		heap[i]=heap[p];
		i = p;
	}
	heap[i] = x;
}

int pop()
{
	int ret = heap[0];
    int x = heap[--sz];
	int i = 0;	
	while(i*2+1 < sz)
	{
		int a = 2*i+1,b = 2*i+2;
		if(b<sz && heap[a]>heap[b])  a = b;
		if(heap[a]>=x) break;
		heap[i]=heap[a];
		i = a;
	}
	heap[i]=x;
	return ret;
}
