#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		double loss=0;
		int n;
		scanf("%d",&n);
		while(n--)
		{
			long int rp,q,d;
			scanf("%ld",&rp);
			scanf("%ld",&q);
			scanf("%ld",&d);
			double mp;
			mp=(rp)+(d*0.01)*(rp);
			double sp;
			sp=(mp)-(d*0.01)*(mp);
			loss=loss+(rp-sp)*q;
		}
		printf("%0.91lf\n",loss);
	}
	return 0;
}
