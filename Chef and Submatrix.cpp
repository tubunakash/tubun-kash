    #include <bits/stdc++.h>
    using namespace std;
    int main()
    {
    	int t;cin>>t;while(t--)
    	{
    		int n;cin>>n;
    		int i,j;
    		int a[n+1][n+1];
    		for(i=0;i<=n;i++)a[i][0]=0;
    		for(j=0;j<=n;j++)a[0][j]=0;
    		for(i=1;i<=n;i++){for(j=1;j<=n;j++)cin>>a[i][j];
    		}
    		
    		
    		 for(i = 1; i <= n; i++)
                for(j = 1; j <= n; j++)
                    a[i][j] = a[i - 1][j] ^ a[i][j - 1]  ^ a[i - 1][j - 1] ^ a[i][j];
    		
    	//	for(i=1;i<=n;i++){for(j=1;j<=n;j++)cout<<f[i][j]<<" ";cout<<endl;}
    		
    		int ans=0;int x1,x2,y1,y2;
    		for(x1=1;x1<=n;x1++)
    		{
    			for(y1=1;y1<=n;y1++)
    			{
    				for(x2=x1;x2<=n;x2++)
    				{
    					for(y2=y1;y2<=n;y2++)
    					{
    						ans=max(ans,a[x2][y2]^a[x1-1][y2]^a[x2][y1-1]^a[x1-1][y1-1]);
    					}
    				}
    			}
    		}
    		cout<<ans<<endl;
    	}
    	return 0;
    } 
