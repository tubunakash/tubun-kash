/* https://codeforces.com/problemset/problem/1015/C */

#include<bits/stdc++.h>
using namespace std;
long long n,m,c,a,b,co,i;
priority_queue<int>q;
main()
{
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>a>>b;
		c+=a;
		q.push(a-b);
	}
	while(m<c && q.size()!=0)
	{
		c=q.top();
		q.pop();
		co++;
	}
	if(m<c)
	cout<<-1;
	else
	cout<<co;
}
