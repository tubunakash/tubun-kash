#include<iostream>
using namespace std;
 
int main(){
	int T;
	cin>>T;
	while(T--){
		long int N,K;
		cin>>N>>K;
		if(K > 0)
			cout<<N/K<<" "<<N%K<<"\n";	
		else
			cout<<0<<" "<<N<<"\n";
	}
	return 0;
}
