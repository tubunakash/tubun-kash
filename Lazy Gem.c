#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n,b,m,res,sum=0,c=0;
		scanf("%lld %lld %lld",&n,&b,&m);
		while (n)
		{
			if(n%2!=0)
			{
				res=(n+1)/2;
				sum+=(res*m);
				m=2*m;
			}
			else
			{
				res=n/2;
				sum+=(res*m);
				m=2*m;
			}
			n=n-res;
			c++;
		}
		b=b*(c-1);
		printf("%lld\n",(sum+b));
	}
}
