#include<stdio.h>
#include<string.h>
int main()
{
	int i,t,j,k,p,n,I,w,words,m,s,flag;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		s=0;
		flag=0;
		words=0;
		scanf("%d %d",&n,&k);
		char forgot[n][100];
		for(j=0;j<n;j++)
		{
			scanf("%s",forgot[j]);
		}
		char modern[3000][100];
		for(j=0;j<k;j++)
		{
			scanf("%d",&words);
			for(w=0;w<words;w++)
			{
				scanf("%s",modern[s]);
				s++;
			}
		}
		for(p=0;p<n;p++)
		{
			for(m=0;m<s;m++)
			{
				if(strcmp(modern[m],forgot[p])==0)
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			printf("NO ");
			else
			printf("YES ");
			flag=0;
		}
		printf("\n");
	}
	return 0;
}
