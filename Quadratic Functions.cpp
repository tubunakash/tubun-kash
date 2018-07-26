    #include <bits/stdc++.h>
    using namespace std;
     
    typedef long long unsigned llu;
    typedef long long lld;
    typedef long ld;
    typedef unsigned int ui;
     
    #define ff 			first
    #define ss 			second
    #define pb 			push_back
    #define pf			push_front
    #define pob 		pop_back
    #define mp 			make_pair
    #define gcd(a,b)    __gcd(a,b)
    #define IOS 		ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
    #define SET(a,val)  memset(a,val,sizeof(a))
    #define PI          3.1415926535897932384626433832795
     
    #define count1(n)   __builtin_popcount(n)   //count number of ones
    #define trail0(n)   __builtin_ctz(n)        //count number of trailing zeros
     
    #define imax 	INT_MAX
    #define imin 	INT_MIN
    #define ldmax	LONG_MAX
    #define ldmin	LONG_MIN
    #define lldmax  LLONG_MAX
    #define lldmin  LLONG_MIN
    #define llumax  ULLONG_MAX
     
    #define SSTR( x ) static_cast< std::ostringstream & >( \
            ( std::ostringstream() << std::dec << x ) ).str()
     
    //constants
    const lld MOD=1000000007;
    #define INF 	1<<57
    #define MAX 	100000
    #define gc 		getchar
    //Delete a single element 'a[0]' from a multimap
    /*if(s.find(a[0])!=s.end())
                s.erase(s.equal_range(a[0]).ff);*/
                
    /*lld gcd(lld a,lld b)
    { 
      if(b == 0) 
        return a;
      else 
        return gcd(b, a % b);
    }*/
    int main()
    {
        //freopen("input.txt", "r", stdin)
        //freopen("output.txt", "w", stdout)
    	IOS;
    	int t;
    	cin>>t;
    	while(t--)
    	{
    		lld a,b,c,d,e,f,l,r;
            cin>>a>>b>>c;
            cin>>d>>e>>f;
            cin>>l>>r;
            
            lld p=abs(2*(a-d)*(l*l*l-r*r*r)+3*(b-e)*(l*l-r*r)+6*(c-f)*(l-r));
            lld q=6;
            p=abs(p);
            //cout<<p<<".."<<q<<endl;
            lld tt=__gcd(p,q);
            p=p/tt;
            q=q/tt;
            cout<<p<<"/"<<q<<"\n";
    	}
        return 0;
    }    
