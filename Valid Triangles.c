    #include<stdio.h>
    int main()
    {
    	int t;
    	scanf("%d",&t);
    	while(t--)
    	{
    		int a,b,c;
    		scanf("%d%d%d",&a,&b,&c);
    		if(a<=180 && b<=180 && c<=180)
    		{
    		if(a+b+c==180 && a>0 && b>0 &&c>0)
    		{
    			printf("YES\n");
    		}
    		else{
    			printf("NO\n");
    		}
    	}
    	}
    	return 0;
    }
