#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a;
	cin>>a;
	while(a--)
	{
		double basic;
		cin>>basic;
		if(basic<1500)
		cout<<basic*2<<endl;
		else
		{
			cout<<setprecision(3)<<fixed;
			cout<<basic+500+(0.98*basic)<<endl;
		}
	}
}
