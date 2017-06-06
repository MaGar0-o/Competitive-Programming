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
#define node NoDe
#define free frEE

const int maxn = 1e5 + 10,
	  maxnode = maxn * 32;
int go[maxnode][2],
	free[maxnode],
	frm[maxn],
	too[maxn],
	wei[maxn],
	val[maxn],
	ord[maxn],
	root[maxn],
	node[maxn],
	siz[maxn],
	n, q, maxor, sz;
bool mark[maxn];
vector<int> adj[maxn],
	ans;

int get_new(void){
	return free[--sz];
}

void destroy(int u){
	for(int i = 0; i < 2; i++){
		if(~go[u][i])
			destroy(go[u][i]);
		go[u][i] = -1;
	}
	free[sz++] = u;
	return;
}

int get_max(int u, int val){
	int ret = 0;
	for(int i = 30; i >= 0; i--){
		int c = (val>>i)&1;
		if(~go[u][!c]) u = go[u][!c], ret = ret<<1|1;
		else u = go[u][c], ret = ret<<1|0;
	}
	return ret;
}

void add(int u, int val){
	for(int i = 30; i >= 0; i--){
		int &v = go[u][(val>>i)&1];
		if(v == -1) v = get_new();
		u = v;
	}
	return;
}

void dfs(int u, int w, int rt, int ep = -1){
	add(node[rt], w);
	smax(maxor, get_max(node[rt], w));
	val[u] = w;
	root[u] = rt;
	for(auto e : adj[u]) if(e ^ ep){
		int v = frm[e]^too[e]^u;
		dfs(v, w ^ wei[e], rt, e);
	}
	return;
}

void merge(int u, int v, int w){
	if(siz[root[u]] <= siz[root[v]])
		swap(u, v);
	destroy(node[root[v]]);
	dfs(v, val[u] ^ w, root[u]);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(go, -1, sizeof go);
	sz = maxnode;
	iota(free, free + maxnode, 0);
	cin >> n >> q;
	const int Q = q;
	for(int i = 0; i < n - 1; i++){
		cin >> frm[i] >> too[i] >> wei[i];
		frm[i]--, too[i]--;
	}
	memset(mark, true, sizeof mark);
	for(int i = 0; i < q; i++)
		cin >> ord[i], mark[--ord[i]] = false;
	for(int i = 0; i < n - 1; i++)
		if(mark[i])
			ord[q++] = i, mark[i] = false;
	for(int i = 0; i < n; i++)
		node[i] = get_new(), add(node[i], 0), siz[root[i] = i] = 1;
	for(int i = q - 1; i >= 0; i--){
		int id = ord[i];
		merge(frm[id], too[id], wei[id]);
		adj[frm[id]].PB(id);
		adj[too[id]].PB(id);
		ans.PB(maxor);
	}
	for(int i = 0; i < Q; i++)
		cout << ans.back() << ' ', ans.pop_back();
	return 0;
}
