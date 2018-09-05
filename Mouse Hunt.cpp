#include <bits/stdc++.h>
using namespace std;
const int N=3e5;
int n,c[N],a[N],v[N],ans;
int g(int i,int j,int y)
{
	y=min(y,c[i]);
	return i-j? g(a[i],j,y): y;
}
int f(int i,int m)
{
	v[i]=m;
	int j=a[i];
	if (v[j]==m) ans+=g(j,i,c[j]);
	if (!v[j]) f(j,m);
}
int main()
{
	cin.sync_with_stdio(0);
	cin>>n;
	#define A for (int i=1; i<=n; ++i)
	A cin>>c[i];
	A cin>>a[i];
	A if (!v[i]) f(i,i);
	cout<<ans;
}
