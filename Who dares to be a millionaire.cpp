    #include <iostream>
    using namespace std;
    long int series(int, int);
    int main(){
    	int t,n,count,i;
    	string s1,s2;
    	long temp,max;
    	scanf("%d", &t);
    	while(t--){
    		scanf("%d", &n);
    		cin>>s1;
    		cin>>s2;
    		count=max=0;
    		for(i=0;i<n;i++)
    			if(s1[i]==s2[i])
    				count++;
    		for(i=0;i<=n;i++){
    			scanf("%ld", &temp);
    			if(i<=count)
    				if(temp>max)
    					max=temp;
    		}
    		if(count==n)
    			max=temp;
    		printf("%ld\n", max);
    	}
    } 
