    #include <bits/stdc++.h>
    using namespace std;
     
    typedef long long LL;
    const int maxn=1010;
    const int maxm=3010;
    const int maxstd=16;
    const LL mod=int(1e9)+7;
    const LL inf=LL(1e18);
     
    struct sstd
    {
        int pos, talk, per;
    };
     
    struct LINK
    {
        int id, next, dis;
    };
     
    struct sque
    {
        int id, sett;
    };
     
    int n, m, school, festival;
    int now;
    int stu_sum;
    int h[maxn], idx[maxn];
    LINK t[maxm*2];
    LL f[maxstd+10][(1<<maxstd)];
    LL cost[1<<maxstd];
    LL percent[1<<maxstd];
    bool vis[maxstd+10][1<<maxstd];
    sstd stu[maxstd+100];
    sque q[(maxstd+10)*(1<<maxstd)];
    LL dis[maxstd+10][maxstd+10];
    int qq[maxn];
    bool vvis[maxn];
    LL ff[maxn];
     
    void join(int u, int v, int d)
    {
        t[now].id=v; t[now].next=h[u]; t[now].dis=d; h[u]=now++;
        t[now].id=u; t[now].next=h[v]; t[now].dis=d; h[v]=now++;
    }
    void read()
    {
        scanf("%d%d%d%d", &n, &m, &school, &festival);
        scanf("%d", &stu_sum);
        for (int i=1; i<=stu_sum; ++i)
        {
            scanf("%d%d%d", &stu[i].pos, &stu[i].talk, &stu[i].per);
            idx[stu[i].pos]=i;
        }
        for (int i=1; i<=n; ++i) h[i]=-1;
        for (int i=1; i<=m; ++i)
        {
            int u, v, d;
            scanf("%d%d%d", &u, &v, &d);
            join(u, v, d);
        }
    }
    LL POW(LL num, int times, int mod)
    {
        LL ans=1;
        while (times)
        {
            if (times & 1) ans=ans*num%mod;
            num=num*num%mod;
            times>>=1;
        }
        return ans;
    }
    void bfs()
    {
        int maxnum=(stu_sum+5)*(1<<stu_sum);
        for (int i=0; i<=stu_sum+1; ++i)
            for (int j=0; j<(1<<stu_sum); ++j)
            {
                f[i][j]=inf;
                vis[i][j]=false;
            }
        
        f[0][0]=0;
        int head=1, tail=1;
        q[1].id=0;
        q[1].sett=0;
        while (head<=tail)
        {
            sque cur=q[(head++)%maxnum];
            vis[cur.id][cur.sett]=false;
            for (int i=0; i<=stu_sum+1; ++i)
            {
                int nsett=((1<=i && i<=stu_sum)? (1<<(i-1)):0) | cur.sett;
                if (f[cur.id][cur.sett]+dis[cur.id][i]>=f[i][nsett]) continue;
                
                f[i][nsett]=f[cur.id][cur.sett]+dis[cur.id][i];
                    
                if (!vis[i][nsett])
                {
                    vis[i][nsett]=true;
                    q[(++tail)%maxnum].id=i;
                    q[tail%maxnum].sett=nsett;
                }
            }
        }
    }
    void SPFA(int start, int finish)
    {
        int head=1, tail=1;
        qq[1]=start;
        for (int i=1; i<=n; ++i)
        {
            vvis[i]=false;
            ff[i]=inf;
        }
        ff[start]=0;
        
        while (head<=tail)
        {
            int cur=qq[(head++)%(n+2)];
            vvis[cur]=false;
            for (int i=h[cur]; i>-1; i=t[i].next)
                if ((idx[t[i].id]==0 || t[i].id==start || t[i].id==finish) && ff[cur]+t[i].dis<ff[t[i].id])
                {
                    ff[t[i].id]=ff[cur]+t[i].dis;
                    if (!vvis[t[i].id])
                    {
                        vvis[t[i].id]=true;
                        qq[(++tail)%(n+2)]=t[i].id;
                    }
                }
        }
    }
    void solve()
    {
    	stu[0].pos=school;
    	stu[stu_sum+1].pos=festival;
    	for (int i=0; i<=stu_sum; ++i)
    		for (int j=i+1; j<=stu_sum+1; ++j)
    		{
    			SPFA(stu[i].pos, stu[j].pos);
    			dis[i][j]=dis[j][i]=ff[stu[j].pos];
    		}
     
    /*
        for (int i=0; i<=stu_sum+1; i++, putchar('\n'))
            for (int j=0; j<=stu_sum+1; ++j)
                printf("%lld ", dis[i][j]);*/
     
        bfs();
        LL inv100=POW(100, mod-2, mod);
        for (int i=1; i<(1<<stu_sum); ++i)
        {
            cost[i]=1;
            percent[i]=1;
            for (int j=1; j<=stu_sum; ++j)
                if ( (i>>(j-1)) & 1)
                {
                    cost[i]=cost[i]*stu[j].talk%mod;
                    percent[i]=((percent[i]*stu[j].per%mod)*inv100)%mod;
                }
                else percent[i]=(percent[i]*(100-stu[j].per)%mod)*inv100%mod;
            cost[i]+=f[stu_sum+1][i];
            //printf("%lld\n", cost[i]);
        }
     
        LL ans=0;
        for (int i=(1<<stu_sum)-1; i>0; --i)
        {
            //printf("%lld %lld\n", cost[i], percent[i]);
            ans=(ans+(cost[i]%mod)*percent[i]%mod)%mod;
            for (int j=0; j<stu_sum; ++j)
                if ((i>>j) & 1) cost[i^(1<<j)]=min(cost[i^(1<<j)], cost[i]); 
        }
        printf("%lld\n", ans);
    }
    int main()
    {
        read();
        solve();
        return 0;
    } 
