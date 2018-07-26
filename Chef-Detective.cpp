#include<iostream>
using namespace std;
int main()
{
	int v[100001]={0};
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		v[x]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(!v[i])
		{
			cout<<i<<" ";
		}
	}
}
