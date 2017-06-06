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

int dfs0(int u){
	siz[u] = 1;
	for(auto v : adj[u])
		if(v ^ par[u])
			par[v] = u, siz[u] += dfs0(v);
	return siz[u];
}

void dfs1(int u){
	stim[u] = tim++;
	for(int i = 0; i < sz(adj[u]); i++){
		int v = u;
		root[v] = (i ? v : root[u]);
		dfs1(v);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(par, -1, sizeof par);
	cin >> n;
	for(int i = 1, fi, se; i < n; i++){
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	dfs0(0);
	for(int i = 0; i < n; i++){
		sort(all(adj[i]), cmp);
		if(i) adj[i].clear(find(all(adj[i]), par[i]));
	}
	dfs1(0);
	int q;
	cin >> q;
	while(q--){
		char ty;
		int fi, se;
		cin >> ty >> fi;
		fi--;
		if(ty == '+'){
			cin >> se;
			while(~fi){
				add(se, stim[root[fi]], stim[fi] + 1);
				fi = par[root[fi]];
			}
		}
		else{ //if(ty == '?')
			LL ret = 0;
			while(~fi){
				ret += get(stim[root[fi]], stim[fi] + 1);
				fi = par[root[fi]];
			}
			cout << ret << endl;
		}
	}
	return 0;
}
