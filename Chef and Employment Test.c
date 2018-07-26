#include <stdio.h>
 
int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k,i,j,t=0,temp=0,a[1000];
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(a[i]>a[j])
				{
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
		n=n+k;
		t=n/2;
		printf("%d",a[t]);
		printf("\n");
	}
	return 0;
}
