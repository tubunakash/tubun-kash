#include<bits/stdc++.h>
using namespace std;
int main()
{
	int q,i;
	cin>>q;
	long long int *ar=new long long int[q];
	for(i=0;i<q;i++)
	{
		cin>>ar[i];
	}
	sort(ar,ar+i);
	for(i=0;i<q;i++)
	{
		cout<<ar[i]<<endl;
	}
	return 0;
}
