    #include <stdio.h>
     
    int main(void) {
    	
    	int n,t,count,i,num;
    	scanf("%d",&n);
    	while(n--)
    	{
    		int ar[105]={0};
    		count=0;
    		scanf("%d",&t);
    		for(i=1;i<=t;i++)
    		{
    			scanf("%d",&num);
    			ar[num]++;
    		}
    		for(i=1;i<=101;i++)
    		{
    			if(ar[i]>=1)
    			count++;
    		}
    		printf("%d\n",count);
    	}
    	return 0;
    }
      
