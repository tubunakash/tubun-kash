#include<bits/stdc++.h>
using namespace std;
int main()
{
	long t,c,d,I;
	cin>>t;
	while(t--)
	{
		cin>>c>>d>>I;
		long min,max=c+d;
		if(c>2*d)
		min=c-d;
		else
		min=d;
		if(I%4==0 && (I>=4*min) && (I<=4*max))
		cout<<"yes"<<endl;
		else
		cout<<"no"<<endl;
	}
}
