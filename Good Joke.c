#include<stdio.h>
int main()
{
	int t,n,i,ans;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		int ar[n+1][2];
		for(i=1;i<n;i++)
		{
			scanf("%d %d",&ar[i][0],&ar[i][1]);
			ans=ans^i;
		}
		printf("%d\n",ans);
	}
	return 0;
}
