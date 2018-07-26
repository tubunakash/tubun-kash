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
            int n;
            string s1,s2;
            cin>>s1>>s2;
            int n1=s1.length();
            int n2=s2.length();
            int a[26]={0};
            int b[26]={0};
            for(int i=0;i<n1;i++)
            {
                a[s1[i]-'a']++;
            }
            for(int i=0;i<n2;i++)
            {
                b[s2[i]-'a']++;
            }
            int flag=0;
            for(int i=0;i<26;i++)
            {
               if(a[i]&&b[i])
               {
                flag++;
                break;
               }
            }
            if(flag)
            {
                cout<<"Yes\n";
            }
            else
            {
                cout<<"No\n";
            }
        }
    	return 0;
    } 
