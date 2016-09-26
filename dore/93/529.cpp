//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 2e5 + 85 - 69,
	  maxl = 20;
int h[maxn],
	par[maxn][maxl],
	sum[maxn],
	n, m;
vector<int> adj[maxn];

void dfs(int u){
	for(int j = 1; j < maxl and par[u][j - 1] != -1; j++)
		par[u][j] = par[par[u][j - 1]][j - 1];
	for(auto v : adj[u])
		if(v != par[u][0])
			par[v][0] = u, h[v] = h[u] + 1, dfs(v);
	return;
}

void calc(int u){
	for(auto v : adj[u])
		if(v != par[u][0]){
			sum[v] += sum[u];
			calc(v);
		}
}

int kthpar(int u, int k){
	for(int i = 0; k; i++)
		if((k >> i) & 1)
			u = par[u][i], k ^= (1 << i);
	return u;
}

int lca(int u, int v){
	if(h[u] < h[v]) swap(u, v);
	u = kthpar(u, h[u] - h[v]);
	if(v == u) return u;
	for(int i = maxl - 1; i >= 0; i--)
		if(par[u][i] != par[v][i])
			u = par[u][i], v = par[v][i];
	return par[u][0];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(par, -1, sizeof par);
	cin >> n >> m;
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	dfs(0);
	m -= n - 1;
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		if(h[u] < h[v]) swap(u, v);
		int p = lca(v, u);
		if(p == v){
			int pp = kthpar(u, h[u] - h[v] - 1);
			sum[0]++;
			sum[pp]--;
			sum[u]++;
		}
		else
			sum[v]++, sum[u]++;
	}
	calc(0);
	bool found = false;
	for(int i = 0; i < n; i++)
		if(sum[i] == m)
			cout << i + 1 << ' ', found = true;
	if(!found)
		cout << -1;
	cout << endl;
	return 0;
}
