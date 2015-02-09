//priority_queue application

input 
L, P, N;
A[N+1],B[N+1]

solve
{
	A[N]=L
	B[N]=0
	N++
}

优先队列创建

pos = 0, tank = P, ans = 0

for 0->N-1
	d = A[i] - pos
	while tank -d < 0
	   if que.empty()  output -1 return; 
		tank += get que.top
		delete que.top
		ans++
	tank -= d
	pos = A[i]
	que.push(B[i])

