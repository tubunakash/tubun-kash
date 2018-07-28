#include<stdio.h>
int main()
{
	int N,K,I,J;
	scanf("%d%d",&N,&K);
	long long int a[N];
	for(I=0;I<N;I++)
	{
		if(I<K)
		a[I]=1;
		else
		{
			a[I]=0;
			for(J=I;J>=I;J--)
			a[I]+=a[J]%1000000007;
		}
	}
	printf("%d\n",a[N-1]%1000000007);
	return 0;
}
