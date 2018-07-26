#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int ar[10000],i,n,sum=0;
		scanf("%d",&n);
		for(i=0;i<n;++i)
		{
			scanf("%d",&ar[i]);
			sum+=ar[i];
			if(sum%2==0)
			{
				printf("\nNO");
			}
			else
			{
				printf("\nYES");
			}
		}
		return 0;
	}
}
