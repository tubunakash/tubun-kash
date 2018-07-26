    #include<bits/stdc++.h>
    using namespace std;
    int main(){
    	int t;
    	int n;
    	string s;
    	vector<int> num1(6),num2(6);
    	cin>>t;
    	int count1,count2;
    	int flag;
    	while(t--){
    		cin>>n;
    		for(int i=0;i<5;i++){
    			num1[i]=0;
    			num2[i]=0;
    		}
    		for(int i=0;i<n;i++){
    			cin>>s;
    			if(s=="a"){
    				num1[0]++;
    				num2[0]++;
    			}
    			else if(s=="b"){
    				num1[1]++;
    				num2[1]++;
    			}
    			else if(s=="aa"){
    				num1[2]++;
    				num2[2]++;
    			}
    			else if(s=="bb"){
    				num1[3]++;
    				num2[3]++;
    			}
    			else if(s=="ab"){
    				num1[4]++;
    				num2[4]++;
    			}
    			else{
    				num1[5]++;
    				num2[5]++;
    			}
    		}
    		char c='a';
    		count1=flag=0;
    		int i=0;
    		while(i<n){
    			if(c=='a'){
    				if(num1[0]!=0){
    					i+=num1[0];
    					flag=0;
    					num1[0]=0;
    				}
    				if(num1[2]!=0){
    					i+=num1[2];
    					flag=0;
    					num1[2]=0;
    				}
    				if(num1[4]!=0){
    					i++;
    					num1[4]--;
    					flag=1;
    				}
    				c='b';
    				count1++;
    			}
    			else{
    			    if(num1[1]!=0){
    					i+=num1[1];
    					flag=0;
    					num1[1]=0;
    				}
    				if(num1[3]!=0){
    					i+=num1[3];
    					flag=0;
    					num1[3]=0;
    				}
    				if(num1[5]!=0){
    					i++;
    					num1[5]--;
    					flag=1;
    				}
    				c='a';
    				count1++;	
    			}
    		}
    		if(flag==1)
    			count1++;
    		count2=flag=0;
            c='b';
    		i=0;
    		while(i<n){
    			if(c=='b'){
    				if(num2[1]!=0){
    					i+=num2[1];
    					flag=0;
    					num2[1]=0;
    				}
    				if(num2[3]!=0){
    					i+=num2[3];
    					flag=0;
    					num2[3]=0;
    				}
    				if(num2[5]!=0){
    					i++;
    					num2[5]--;
    					flag=1;
    				}
    				c='a';
    				count2++;
    			}
    			else{
    			    if(num2[0]!=0){
    					i+=num2[0];
    					flag=0;
    					num2[0]=0;
    				}
    				if(num2[2]!=0){
    					i+=num2[2];
    					flag=0;
    					num2[2]=0;
    				}
    				if(num2[4]!=0){
    					i++;
    					num2[4]--;
    					flag=1;
    				}
    				c='b';
    				count2++;	
    			}
    		}
    		if(flag==1)
    			count2++;
    		cout<<min(count1,count2)<<endl;
    	}
    	return 0;
    } 
