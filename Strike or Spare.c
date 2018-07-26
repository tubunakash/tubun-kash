#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	scanf("%d",&t);
	int n,i;
	long long unsigned int p,q;
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		q=pow(10,n/2);
		p=1;
		printf("%llu %llu\n",p,q);
	}
	return 0;
}
