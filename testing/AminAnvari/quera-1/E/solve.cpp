//sobskdrbhvk
//remember the flying, the bird dies ):(
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

const int maxn = 1e5 + 85 - 69;
const int Inf = 2e9;
int par[maxn],
	pwei[maxn],
	h[maxn],
	frm[maxn],
	too[maxn],
	wei[maxn],
	ord[maxn],
	n, m, q;
vector<int> adj[maxn];

int root(int u){
	return par[u] < 0 ? u : root(par[u]);
}

void merge(int u, int v, int w){
	if((u = root(u)) == (v = root(v)))
		return;
	if(par[u] > par[v])
		swap(u, v);
	par[u] += par[v];
	par[v] = u;
	pwei[v] = w;
	return;
}

int get_min(int u, int v){
	if(u == v) return Inf;
	if(par[h[u]] < 0 or par[h[v]] < 0) return -1;
	if(h[u] < h[v]) swap(u, v);
	return min(get_min(par[u], v), pwei[u]);
}

void dfs(int u){
	for(auto v : adj[u])
		h[v] = h[u] + 1, dfs(v);
	return;
}

bool cmp(int i, int j){
	return wei[i] > wei[j];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(par, -1, sizeof par);
	cin >> n >> m;
	for(int i = 0; i < m; i++)
		cin >> frm[i] >> too[i] >> wei[i], frm[i]--, too[i]--;
	iota(ord, ord + m, 0);
	sort(ord, ord + m, cmp);
	for(int i = 0; i < m; i++){
		int id = ord[i];
		merge(frm[id], too[id], wei[id]);
	}
	for(int i = 0; i < n; i++)
		if(!(par[i]>>31))
			adj[par[i]].PB(i);
	for(int i = 0; i < n; i++)
		if(par[i]>>31)
			dfs(i);
	cin >> q;
	while(q--){
		int fi, se, th;
		cin >> fi >> se >> th, fi--, se--;
		cout << ((get_min(fi, se) < se) ? "NO\n" : "YES\n");
	}
	return 0;
}
