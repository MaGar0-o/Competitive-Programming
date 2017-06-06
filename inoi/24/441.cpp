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

const int maxn = 1e5 + 85 - 69;
vector<int> adj[maxn];
int fi[maxn],
	se[maxn],
	th[maxn],
	par[maxn],
	dsu_par[maxn],
	wei[maxn],
	h[maxn],
	n, m;
bool mark[maxn];

int other(int e, int v){
	return fi[e] ^ v ? fi[e] : se[e];
}

int parof(int v){
	if(dsu_par[v] == v) return v;
	return dsu_par[v] = parof(dsu_par[v]);
}

bool dfs(int v, int inn = -1){
	//cout << "start dfs: " << v << endl;
	mark[v] = true;
	for(auto e : adj[v]){
		int u = other(e, v),
			w = th[e];
		if(e == inn)
			continue;
		if(!mark[u]){
			wei[u] = w;
			par[u] = v;
			h[u] = h[v] + 1;
			if(dfs(u, e))
				return true;
		}
		else{
			int vv = v;
			//cout << "One time going up in v = " << v << endl;
			while(h[vv] > h[u]){
				//cout << "going up: " << vv << endl;
				if(wei[vv] != w)
					return true;
				int tmp = par[parof(vv)];
				dsu_par[vv] = par[vv];
				vv = tmp;
			}
		}
	}
	//cout << "end dfs: " << v << endl;
	return false;
}

bool check(int tim){
	for(int i = 0; i < n; i++)
		adj[i].clear(), dsu_par[i] = i, par[i] = -1;
	for(int i = 0; i <= tim; i++){
		adj[fi[i]].PB(i);
		adj[se[i]].PB(i);
	}
	memset(wei, 0, sizeof wei);
	memset(h, 0, sizeof h);
	memset(mark, false, sizeof mark);
	for(int i = 0; i < n; i++){
		//cout << "checking " << i << endl;
		if(!mark[i] and dfs(i))
			return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++)
		cin >> fi[i] >> se[i] >> th[i], fi[i]--, se[i]--;
	int lo = -1, hi = m;
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if(check(mid))
			hi = mid;
		else
			lo = mid;
	}
	for(int i = 0; i <= lo; i++)
		cout << 0;
	for(int i = lo + 1; i < m; i++)
		cout << 1;
	cout << '\n';
	return 0;
}
