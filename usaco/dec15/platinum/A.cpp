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

const int maxn = 5e4 + 85 - 69,
	  maxl = 18;
int par[maxn][maxl],
	ps[maxn],
	cnt[maxn],
	h[maxn],
	n, k;
vector<int> adj[maxn];

void dfs1(int v, int p = -1){
	par[v][0] = p;
	for(int j = 1; j < maxl and par[v][j - 1] != -1; j++)
		par[v][j] = par[par[v][j - 1]][j - 1];
	for(auto u : adj[v])
		if(u != p)
			h[u] = h[v] + 1, dfs1(u, v);
	return;
}

int lca(int v, int u){
	if(h[v] < h[u]) swap(v, u);
	for(int j = 0; h[v] - h[u]; j++)
		if(((h[v] - h[u]) >> j) & 1)
			v = par[v][j];
	if(v == u) return v;
	for(int i = maxl - 1; i >= 0; i--)
		if(par[v][i] != par[u][i])
			v = par[v][i], u = par[u][i];
	return par[v][0];
}

int dfs2(int v, int p = -1){
	for(auto u : adj[v])
		if(u != p)
			ps[v] += dfs2(u, v);
	cnt[v] += ps[v];
	return ps[v];
}

int main(){
	ifstream cin("maxflow.in");
	ofstream cout("maxflow.out");
	cin >> n >> k;
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	dfs1(0);
	for(int i = 0; i < k; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		int pa = lca(fi, se);
		ps[fi]++;
		ps[se]++;
		ps[pa]-=2;
		cnt[pa]++;
	}
	dfs2(0);
	cout << (*max_element(cnt, cnt + n)) << endl;
	return 0;
}
