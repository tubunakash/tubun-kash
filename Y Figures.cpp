    #include <bits/stdc++.h>
    using namespace std;
     
    typedef pair <int, int> ii;
    typedef long long ll;
     
    const int Maxn = 200005;
     
    int t;
    int n, q;
    int lab[Maxn];
    vector <int> neigh[Maxn];
    vector <ii> quer[Maxn];
    ll res[Maxn];
    map <int, int> M;
    map <int, int> cnt[Maxn];
    int par[Maxn];
     
    void Merge(int a, int b, map <int, ll> &ways)
    {
    	if (cnt[par[a]].size() < cnt[par[b]].size()) swap(a, b);
    	for (map <int, int>::iterator it = cnt[par[b]].begin(); it != cnt[par[b]].end(); it++) {
    		ways[it->first] += 2ll * cnt[par[a]][it->first] * it->second;
    		cnt[par[a]][it->first] += it->second;
    	}
    	par[b] = par[a];
    }
     
    void Traverse(int v, int p = 0)
    {
    	map <int, ll> ways;
    	par[v] = v; cnt[v].clear();
    	for (int i = 0; i < neigh[v].size(); i++) {
    		int u = neigh[v][i];
    		if (u == p) continue;
    		M[lab[v]]++;
    		Traverse(u, v);
    		Merge(v, u, ways);
    		M[lab[v]]--;
    	}
    	for (int i = 0; i < quer[v].size(); i++) {
    		ii p = quer[v][i];
    		map <int, ll>::iterator it1 = ways.find(p.first);
    		map <int, int>::iterator it2 = M.find(p.first);
    		if (it1 != ways.end() && it2 != M.end())
    			res[p.second] = it1->second * it2->second;
    		else res[p.second] = 0;
    	}
    	cnt[par[v]][lab[v]]++;
    }
     
    int main()
    {
    	scanf("%d", &t);
    	while (t--) {
    		scanf("%d %d", &n, &q);
    		for (int i = 1; i <= n; i++) {
    			scanf("%d", &lab[i]);
    			neigh[i].clear();
    			quer[i].clear();
    		}
    		for (int i = 0; i < n - 1; i++) {
    			int a, b; scanf("%d %d", &a, &b);
    			neigh[a].push_back(b);
    			neigh[b].push_back(a);
    		}
    		for (int i = 1; i <= q; i++) {
    			int x, z; scanf("%d %d", &x, &z);
    			quer[x].push_back(ii(z, i));
    		}
    		M.clear();
    		Traverse(1);
    		for (int i = 1; i <= q; i++)
    			printf("%lld\n", res[i]);
    	}
    	return 0;
    }
