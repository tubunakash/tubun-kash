    #include<iostream>
    #include<string>
    using namespace std;
     
    int main()
    {
     
     
    	int T,i,j,flag,length,len;
    	string str;
     
    	cin>>T;
     
    	while(T--)
    	{
     
     
    		cin>>str;
     
    		length = str.length();
     
    		if(length < 2)
    		{
    			cout<<"no"<<"\n";
    		}
     
    		else
    		{
    		len = length - 1;
     
    		flag = 0;
     
    		for(i=0;i<len;++i)
    		{
    			for(j=i+1;j<length;++j)
    			{
    				if(str[i] == str[j])
    				{
    					flag = 1;
    					cout<<"yes"<<"\n";
    					break;
    				}
    			}
     
    			if(flag == 1)
    				break;
     
    		}
     
     
    		if(flag!=1)
    			cout<<"no"<<"\n";
     
     
    		}
     
    	}
     
     
    return 0;
    } 
