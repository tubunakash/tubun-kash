#include<bits/stdc++.h>
#define N 500005
using namespace std;
int T,n,m,kk,x,y,ans,head[N],num[N],chu[N],ru[N];
struct Edge{int nxt,to;}e[N];
inline void link(int x,int y){e[++kk].nxt=head[x];e[kk].to=y;head[x]=kk;}
priority_queue<int,vector<int>,greater<int>> Q;
int main(){
	scanf("%d",&T);
	while (T--){
		memset(head,0,sizeof(head));kk=0;
		scanf("%d%d",&n,&m);int ans=0;
		memset(ru,0,sizeof(ru));memset(num,0,sizeof(num));
		memset(chu,0,sizeof(chu));
		for (int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			ru[x]++;chu[y]++;
			link(x,y);
		}
		for (int i=1;i<=n;i++){
			if (!chu[i]){
				for (int j=head[i];j;j=e[j].nxt){
					int v=e[j].to;
					if (chu[v]==1) num[i]++;
				}
			}
			else continue;
		}
		for (int i=1;i<=n;i++)
			if (!chu[i]) Q.push(num[i]);
		while (Q.size()>1){
			int x=Q.top();Q.pop();
			int y=Q.top();Q.pop();
			ans++;
			Q.push(y+1);
		}
		ans=ans+max(0,Q.top()-1);
		while (!Q.empty()) Q.pop();
		printf("%d\n",ans);
	}
	return 0;
} 