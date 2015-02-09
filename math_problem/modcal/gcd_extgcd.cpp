gcd(a,b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

extgcd(int a,int b,int &x,int &y)
{
	//ax+by = gcd(a,b)
	int d = a;
	if(b!=0) {
		d = extgcd(b,a%b,y,x);
		y -= (a/b) * x;
	} else {
		x=1; y=0;
	}
	return d;
}
