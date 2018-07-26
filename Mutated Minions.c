    #include <stdio.h>
    int main() {
    	int t;
    	scanf("%d",&t);
    	while(t--) {
    		int n,s=0,k,i,a;
    		scanf("%d%d",&n,&k);
    		for(i=0;i<n;++i) {
    			scanf("%d",&a); 
    			if((a+k)%7==0)
    				++s;
    		}
    		printf("%d\n",s);
    	}
    	return 0;
    } 
