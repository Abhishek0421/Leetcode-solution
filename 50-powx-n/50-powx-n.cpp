class Solution {
public:
		double power(double a,int b)
	{
	if(b==0)return 1;
	else if(b%2==0)return power(a*a,b/2);
	else return a*power(a*a,b/2);
	}        

	double myPow(double x, int n) {
	if(n<0)
	{
		n=abs(n);
		x=1/x;
	}
	return power(x,n);
	}
};