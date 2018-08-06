    #include <stdio.h>
    void main()
    {
    	int T;
    	scanf("%d",&T);
    	long long int p,q,n,r,t;
     
    	while(T--)
    	{
    		scanf("%lld%lld%lld",&p,&q,&n);
    				n--;
     
    		if (p==q)
    		{
    			r=1;
    		}
    		else
    		{
    			t=((n*q)/(2*(p-q)));
     
    		
    		if (p<q)
    		{
    			t=-t;
    		}
    		r=t+1;
    	}
    		printf("%lld\n",r);
			}
     
    }
