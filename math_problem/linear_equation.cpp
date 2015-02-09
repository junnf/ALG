const double EPS = 1E-8;
typedef vector<double> vec;
typedef vector<vec> mat;

vec gauss_jordan(const mat &A, const vec &b)
{
	int n = A.size();
	//n+1 col and n row
    mat B(n,vec(n+1));	
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			B[i][j]=A[i][j];
		}
	for(i=0;i<n;i++)
		B[i][n] = b[i];
	//get biggest value to swap as the first line
	for(i=0;i<n;i++)
	{
		int pivot = i;
		for(j=i;j<n;j++)
		{
			if(abs(B[j][i])>abs(B[pivot][i])) pivot = j;
		}
		//swap can use DEFINE ,there use vector method
		swap(B[i],B[pivot]);
	//judge have unique answer or (no or infinite) answer
		if(B[i][i] <= EPS) return vec();
	//the main point.
		for(j=i+1;j<=n;j++)
				B[i][j]/=B[i][i];
		for(j=0;j<n;j++)
		{
			if(j!=i) {
			for(k=i+1;k<=n;k++){
				//Gauss
				B[j][k] -= B[i][k]*B[j][i];
			}
		}
	vec x(n);
	for(i=0;i<n;i++)
	{
		x[i] = B[i][n] 
	}
	return x;
}
