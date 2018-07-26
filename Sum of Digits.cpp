    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
        int t;
        cin >> t;
        while(t--){
    	int num;
    	cin >> num;
    	int d;
    	int sum=0;
    	while(num>0){
    	  d=num%10;
    	  sum=sum+d;
    	  num/=10;
    	}
    	cout << sum << "\n";
    }
    	return 0;
    } 
