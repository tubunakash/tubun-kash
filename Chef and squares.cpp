    #include<cstdio>
    #include<algorithm>
    #include<cstring>
    using namespace std;
    int t,n,a[405][405];
    int main()
    {
    	scanf("%d",&t);
    	while(t--)
    	{
    		scanf("%d",&n);
    		memset(a,0,sizeof(a));
    		for(int i=1;i<=n;i++)a[1][((n+1)/2+i-2)%n+1]=i;
    		for(int i=2;i<=n;i++)
    		{
    			for(int j=1;j<n;j++)a[i][j]=a[i-1][j+1];
    			a[i][n]=a[i-1][1];
    		}
    		for(int i=1;i<=n;i++)
    		{
    			for(int j=1;j<=n;j++)
    			  printf("%d ",a[i][j]);
    			printf("\n");
    		}
    	}
    	return 0;
    } 
