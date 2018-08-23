/* https://codeforces.com/problemset/problem/1006/E */

#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>v[200020];
int a[200020],b[200020],c[200020];
int num=1;
int dfs(int x)
{
	a[num]=x;
	b[x]=num++;
	for(int i=0;i<v[x].size();i++)
	  dfs(v[x][i]);
	c[x]=num;
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	int i,j,p,u,k;
	for(i=2;i<=n;i++)
	{
		scanf("%d",&p);
		v[p].push_back(i);
	}
	dfs(1);
	for(i=0;i<q;i++)
	{
		scanf("%d%d",&u,&k);
		if(k<=c[u]-b[u])
		 num=a[b[u]+k-1];
		else
		 num=-1;
		printf("%d\n",num);
	}
}
