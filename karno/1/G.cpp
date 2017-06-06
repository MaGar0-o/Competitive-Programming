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

const int maxn = 5e5 + 85 - 69;
vector<int> adj[maxn];
vector<pair<int, pii> > quer;
int h[maxn],
	dn[maxn],
	ord[maxn],
	frm[maxn],
	too[maxn],
	wei[maxn],
	WEI[maxn],
	stim[maxn],
	ftim[maxn],
	seg[maxn<<2],
	lis[maxn],
	lds[maxn],
	n, m, tim, ans;

bool cmp(int i, int j){return wei[i] < wei[j];}
bool dncmp(int u, int v){return dn[u] > dn[v];}
bool cmp1(pair<int, pii> i, pair<int, pii> j){return WEI[i.L] > WEI[j.L];}

void go(int u, int st, int en){
	quer.PB(MP(u, MP(st, en)));
	for(auto v : adj[u])
		go(v, st, en);
	return;
}

int getdn(int u, int p = -1){
	dn[u] = 1;
	for(auto v : adj[u])
		if(v != p)
			dn[u] += getdn(v, u);
	return dn[u];
}

void dfs(int u, int p = -1){
	{
		int id = find(all(adj[u]), p) - adj[u].begin();
		if(id != sz(adj[u])) adj[u].erase(adj[u].begin() + id);
	}
	sort(all(adj[u]), dncmp);
	stim[u] = tim++;
	for(auto v : adj[u]){
		h[v] = h[u] + 1;
		dfs(v, u);
	}
	ftim[u] = tim;
	for(int i = 1; i < sz(adj[u]); i++)
		go(adj[u][i], stim[u] + 1, stim[adj[u][i]]);
	return;
}

void modify(int idx, int val, int l = 0, int r = n, int id = 1){
	if(idx >= r or idx < l) return;
	if(r - l == 1){
		seg[id] = val;
		return;
	}
	int mid = (l + r) >> 1;
	modify(idx, val, l, mid, id<<1|0);
	modify(idx, val, mid, r, id<<1|1);
	seg[id] = max(seg[id<<1|0], seg[id<<1|1]);
	return;
}

int get_max(int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return 0;
	if(st <= l and r <= en)
		return seg[id];
	int mid = (l + r) >> 1;
	return max(get_max(st, en, l, mid, id<<1|0),
			get_max(st, en, mid, r, id<<1|1));
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	m = n - 1;
	for(int i = 0; i < m; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		fi--, se--;
		frm[i] = fi, too[i] = se, wei[i] = th;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	getdn(0);
	dfs(0);
	iota(ord, ord + m, 0);
	sort(ord, ord + m, cmp);
	for(int i = 0; i < m; i++){
		if(h[frm[i]] > h[too[i]])
			swap(frm[i], too[i]);
		WEI[too[i]] = wei[i];
	}
	for(int i = 0; i < m; i++){
		int id = ord[i];
		lis[too[id]] = get_max(stim[too[id]], ftim[too[id]]) + 1;
		modify(stim[too[id]], lis[too[id]]);
	}
	memset(seg, 0, sizeof seg);
	
	for(int i = m - 1; i >= 0; i--){
		int id = ord[i];
		lds[too[id]] = get_max(stim[too[id]], ftim[too[id]]) + 1;
		modify(stim[too[id]], lds[too[id]]);
	}
	memset(seg, 0, sizeof seg);

	/*for(int i = 0; i < n; i++)
		cout << lis[i] << ' ';
	cout << endl;
	for(int i = 0; i < n; i++)
		cout << lds[i] << ' ';
	cout << endl;*/
	
	sort(all(quer), cmp1);
	int ptr = m - 1;
	for(auto ask : quer){
		//cout << ask.L << ' ' << ask.R.L << ' ' << ask.R.R << endl;
		while(ptr >= 0 and wei[ord[ptr]] > WEI[ask.L]){
			modify(stim[too[ord[ptr]]], lds[too[ord[ptr]]]);
			ptr--;
		}
		smax(ans, get_max(ask.R.L, ask.R.R) + lis[ask.L]);
	}
	memset(seg, 0, sizeof seg);
	ptr = 0;
	reverse(all(quer));
	for(auto ask : quer){
		while(ptr < m and wei[ord[ptr]] < WEI[ask.L]){
			modify(stim[too[ord[ptr]]], lis[too[ord[ptr]]]);
			ptr++;
		}
		smax(ans, get_max(ask.R.L, ask.R.R) + lds[ask.L]);
	}
	smax(ans, *max_element(lis, lis + n));
	smax(ans, *max_element(lds, lds + n));
	cout << ans << '\n';
	return 0;
}
