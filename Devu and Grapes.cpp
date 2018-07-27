    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long int
    #define pb push_back
    #define mkp make_pair
    #define mod 1000000007
    ll power(ll a,ll b)
    {
        if(b==0)
        return 1;
        if(b==1)
        return a;
        ll r=power(a,b/2)%mod;
        if(b%2==0)
        return (r*r)%mod;
        else
        return (((r*r)%mod)*a)%mod;
    }
    int main()
    {
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	cout.tie(NULL);
    	int t;
        cin>>t;
        while(t--)
        {
          ll n,k;
          cin>>n>>k;
          ll sum=0,r;
          for(int i=0;i<n;i++)
          {
           cin>>r;
           if(r<=k)
           {
            sum=sum+k-r;
            continue;
           }
           ll w=r%k;
           sum=sum+min(w,k-w);
          }
          cout<<sum<<"\n";
        }
    	return 0;
    } 
