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

const int maxn = 1e5 + 10;
int ans,
	wei[maxn],
	frm[maxn],
	too[maxn],
	n, q;
bool mark[maxn];
vector<int> adj[maxn];

void dfs(int u, int w = 0, int ep = -1){
	smax(ans, w);
	for(auto e : adj[u])
		if((e^ep) and !mark[e])
			dfs(frm[e]^too[e]^u, w^wei[e], e);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 0; i < n - 1; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		fi--, se--;
		frm[i] = fi, too[i] = se, wei[i] = th;
		adj[fi].PB(i), adj[se].PB(i);
	}
	for(int i = 0; i < q; i++){
		ans = 0;
		for(int j = 0; j < n; j++)
			dfs(j);
		cout << ans << ' ';
		int id;
		cin >> id, id--;
		mark[id] = true;
	}
	return 0;
}
