#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t>0)
	{
		int n;
		cin>>n;
		int p=n;
		int q=p/8;
		int r=p%8;
		if(r==1)
		{
			cout<<n+3;
			cout<<"LB"<<endl;
		}
		if(r==2)
		{
			cout<<n+3;
			cout<<"MB"<<endl;
		}
		if(r==3)
		{
			cout<<n+3;
			cout<<"UB"<<endl;
		}
		if(r==4)
		{
			cout<<n-3;
			cout<<"LB"<<endl;
		}
		if(r==5)
		{
			cout<<n-3;
			cout<<"MB"<<endl;
		}
		if(r==6)
		{
			cout<<n-3;
			cout<<"UB"<<endl;
		}
		if(r==7)
		{
			cout<<n+1;
			cout<<"SU"<<endl;
		}
		if(r%8==0)
		{
			cout<<n-1;
			cout<<"SL"<<endl;
		}
		t--;
	}
	return 0;
}
