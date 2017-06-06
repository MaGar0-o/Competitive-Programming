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

const int maxn = 1e5 + 10,
	  maxl = 17;
const int Inf = 2e9;
vector<pii> stc[maxn],
	adj[maxn];
bool found[maxn];
int par[maxn][maxl],
	rdis[maxn],
	h[maxn],
	dn[maxn],
	cpar[maxn],
	col[maxn],
	n, cent;

void dfs(int u, int p = -1){
	par[u][0] = p;
	for(int i = 1; i < maxl and par[u][i - 1]; i++)
		par[u][i] = par[par[u][i - 1]][i - 1];
	for(auto e : adj[u]) if(e.L != p){
		rdis[e.L] = rdis[u] + e.R;
		h[e.L] = h[u] + 1;
		dfs(e.L, u);
	}
	return;
}

int lca(int u, int v){
	if(h[u] > h[v]) swap(u, v);
	for(int i = 0; h[v] - h[u]; i++)
		if(((h[v] - h[u])>>i)&1)
			v = par[v][i];
	if(u == v) return v;
	for(int i = maxl - 1; i >= 0; i--)
		if(par[u][i] != par[v][i])
			u = par[u][i], v = par[v][i];
	return par[u][0];
}

int distof(int u, int v){
	return rdis[u] + rdis[v] - 2 * rdis[lca(u, v)];
}

void find_cent(int u, int sz, int p = -1){
	dn[u] = 1;
	for(auto e : adj[u])
		if(e.L != p and !found[e.L]){
			find_cent(e.L, sz, u);
			dn[u] += dn[e.L];
		}
	if(cent == -1 and (dn[u] >= (sz + 1)>>1))
		cent = u;
	return;
}

void go(int u, int p = -1, int sz = n){
	cent = -1;
	find_cent(u, sz);
	found[u = cent] = true;
	cpar[u] = p;
	stc[u].reserve(sz + 5);
	for(auto e : adj[u])
		if(!found[e.L])
			go(e.L, u, (dn[e.L] < dn[u] ? dn[e.L] : sz - dn[u]));
	return;
}

void add(int u, int v, int dis, int tim){
	if(u == -1) return;
	add(cpar[u], v, dis, tim);
	dis -= distof(u, v);
	if(dis < 0) return;
	while(stc[u].back().L <= dis)
		stc[u].pop_back();
	stc[u].PB(MP(dis, tim));
	//cout << "adding: " << u << ' ' << dis << ' ' << tim << endl;
	return;
}

int get(vector<pii> &vec, int x){
	int lo = 0,
		hi = sz(vec);
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if(vec[mid].L >= x)
			lo = mid;
		else
			hi = mid;
	}
	return vec[lo].R;
}

int get(int u, int v){
	if(u == -1) return -1;
	int ret = get(cpar[u], v);
	int dis = distof(u, v);
	smax(ret, get(stc[u], dis));
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(cpar, -1, sizeof cpar);
	cin >> n;
	for(int i = 1; i < n; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		fi--, se--;
		adj[fi].PB(MP(se, th));
		adj[se].PB(MP(fi, th));
	}
	for(int i = 0; i < n; i++)
		stc[i].PB({Inf, -1});
	dfs(0);
	go(0);
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		int ty, fi, se, th;
		cin >> ty >> fi, fi--;
		if(ty == 2){
			int id = get(fi, fi);
			cout << (~id ? col[id] : 0) << '\n';
		}
		else{
			cin >> se >> th;
			col[i] = th;
			add(fi, fi, se, i);
		}
	}
	return 0;
}
