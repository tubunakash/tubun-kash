#include<stdio.h>
int gcd(int a,int b)
{
	if(a==0)
	{
		return b;
	}
	return gcd(b%a,a);
}
int main()
{
	int i,j,t,a[1000],n,g;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[j]);
			g=a[0];
		}
		for(j=0;j<n;j++)
		g=gcd(g,a[j]);
		if(g==1)
		printf("0\n");
		else
		printf("-1\n");
	}
	return 0;
}
