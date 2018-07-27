#include<stdio.h>
int main()
{
	int n,m,t,s,v,i,j,count;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		int tot[105]={0};
		for(i=1;i<=m;i++)
		{
			scanf("%d",&v);
			for(j=0;j<v;j++)
			{
				scanf("%d",&s);
				tot[s]=tot[s]*10+i;
			}
		}
		count=n;
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(tot[i]==tot[j])
				{
					count--;
					break;
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
