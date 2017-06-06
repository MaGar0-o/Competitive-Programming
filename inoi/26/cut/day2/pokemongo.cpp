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

void dfs(int v, int p = -1){
	if(inq[v]) smax(dis[v], -func[v]);
	for(auto u : adj[v])
		if(u != p){
			dfs(u, v);
			vec[v].PB(MP(dis[u] + 1);
		}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(func, -1, sizeof func);
	fill(dis, dis + n, -1000000000);
	cin >> n >> q;
	for(int i = 1; i < n; ++i){
		int fi, se;
		cin >> fi >> se, --fi, --se;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	for(int i = 0; i < q; ++i){
		cin >> q1[i] >> q2[i];
		func[--q1[i]] = q2[i];
		inq[q1[i]] = true;
	}
	return 0;
}
