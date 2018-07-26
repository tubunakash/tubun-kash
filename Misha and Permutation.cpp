    #include<bits/stdc++.h>
    #define sqr(x) (x)*(x)
    #define ll long long
    #define ull unsigned long long
    #define ui unsigned int
    #define vi vector<int>
    #define pb push_back
    #define ld long double
    #define mp make_pair
    #define pii pair<int,int>
    #define debuge puts("isok")
    #define debug(x) cout<<#x<<"="<<x<<endl
    #define SS second
    #define FF first
    using namespace std;
     
    const int mod=1e9+7;
    int n,k;
    int dp[10005][10],sum[10005][10];
    void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}
    struct poly{
    	int n,a[15];
    	void clear(){n=0;memset(a,0,sizeof(a));}
    	int get(int x){
    		int now=1,ans=0;
    		for(int i=0;i<=n;i++)
    			ch(ans,(ll)now*a[i]%mod),now=(ll)now*x%mod;
    		return ans;
    	}
    }c[1005][10],t[1005][10];
     
    int exp(int x,int y){
    	int ans=1;
    	while(y){
    		if(y&1) ans=(ll)ans*x%mod;
    		x=(ll)x*x%mod;y>>=1;
    	}
    	return ans;
    }
    poly operator + (poly a,poly b){
    	for(int i=0;i<=max(a.n,b.n);i++) ch(a.a[i],b.a[i]);
    	a.n=max(a.n,b.n);
    	return a;
    }
    poly operator * (poly a,poly b){
    	poly tmp;tmp.clear();
    	tmp.n=a.n+b.n;
    	for(int i=0;i<=a.n;i++)
    		for(int j=0;j<=b.n;j++)
    			ch(tmp.a[i+j],(ll)a.a[i]*b.a[j]%mod);
    	return tmp;
    }
    poly operator / (poly a,poly b){
    	poly tmp;tmp.clear();
    	int inv=exp(b.a[b.n],mod-2);
    	for(int i=a.n;i>=b.n;i--){
    		int k=(ll)a.a[i]*inv%mod;
    		tmp.a[i-b.n]=k;
    		for(int j=0;j<=b.n;j++)
    			ch(a.a[i-b.n+j],mod-(ll)k*b.a[j]%mod);
    	}
    	tmp.n=a.n-b.n;
    	return tmp;
    }
    poly operator * (poly a,int b){
    	for(int i=0;i<=a.n;i++) a.a[i]=(ll)a.a[i]*b%mod;
    	return a;
    }
    void pre_dp(){
    	int n=10000;
    	dp[0][0]=1;
    	for(int i=1;i<=n;i++)
    		for(int k=0;k<=7;k++){
    			dp[i][k]=sum[i][k]=0;
    			if(!k){dp[i][k]=1;continue;}
    			if(i<k) continue;
    			dp[i][k]=(dp[i-k][k]+dp[i-k][k-1])%mod;
    			sum[i][k]=(((ll)k*dp[i][k]%mod+sum[i-k][k])%mod+sum[i-k][k-1])%mod;
    		}
    }
    poly calc(int n,int *a,int *b){
    	poly tmp,ans;
    	tmp.clear();tmp.a[0]=1;
    	ans.clear();
    	for(int i=1;i<=n+1;i++){
    		poly t;t.clear();t.n=1;t.a[0]=mod-a[i],t.a[1]=1;
    		tmp=tmp*t;
    	}
    	for(int i=1;i<=n+1;i++){
    		poly t;t.clear();t.n=1;t.a[0]=mod-a[i],t.a[1]=1;
    		int inv=1;
    		for(int j=1;j<=n+1;j++) if(i!=j) inv=(ll)inv*(a[i]-a[j]+mod)%mod;
    		inv=exp(inv,mod-2);
    		ans=ans+tmp/t*inv*b[i];
    	}
    	return ans;
    }
    void pre_poly(){
    	int fac=1,x[10],y[10];
    	for(int k=2;k<=6;k++){
    		fac*=k;
    		for(int i=0;i<fac;i++){
    			for(int j=1;j<=k+1;j++)
    				x[j]=j,y[j]=dp[j*fac+i][k];
    			c[i][k]=calc(k,x,y);
    			for(int j=1;j<=k+2;j++)
    				x[j]=j,y[j]=sum[j*fac+i][k];
    			t[i][k]=calc(k+1,x,y);
    		}
    	}
    }
    int C(int n,int k){
    	if(n<=1000) return dp[n][k];
    	int fac=1;
    	for(int i=1;i<=k;i++) fac=fac*i;
    	return c[n%fac][k].get(n/fac);
    }
    int T(int n,int k){
    	if(n<=1000) return sum[n][k];
    	int fac=1;
    	for(int i=1;i<=k;i++) fac=fac*i;
    	return t[n%fac][k].get(n/fac);
    }
     
    int main(){
    	pre_dp();
    	pre_poly();
    	int Test=0;scanf("%d",&Test);
    	while(Test--){
    		scanf("%d%d",&n,&k);
    		int ans=1;
    		for(int i=1;i<=k;i++) ans=(ll)ans*(n-i+1)%mod*exp(i,mod-2)%mod;
    		ch(ans,mod-(ll)(n+1)*C(n,k-1)%mod);
    		ch(ans,T(n,k-1));
    		printf("%d\n",ans);
    	}
    }
