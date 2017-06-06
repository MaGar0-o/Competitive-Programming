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
vector<int> adj[maxn];
int n;

pii far(int u, int p = -1, int h = 0){
	pii ret(h, u);
	for(auto v : adj[u])
		if(v^p)
			smax(ret, far(v, u, h + 1));
	return ret;
}

void dfs0(int u, int p = -1){
	dwn[u] = 0;
	for(auto v : adj[u])
		if(v ^ p){
			dfs0(v, u);
			chdwn[u].PB(dwn[v] + 1);
			smax(dwn[u], dwn[v] + 1);
			chdp[u].PB(max(two[v], dpdn[v]));
		}
	sort(all(chdwn[u]), greater<int>());
	sort(all(chdp[u]), greater<int>());
	chdwn[u].PB(0), chdwn[u].PB(0);
	two[u] = chdwn[u][0] + chdwn[u][1];
	return;
}

void dfs1(int u, int p = -1){
	if(~p){
		upp[u] = upp[p] + 1;
		if(dn[u] + 1 != chdwn[p][0])
			upp[u] = chdwn[p][0] + 1;
		else
			upp[u] = chdwn[p][1] + 1;
		dpup[u] = dpup[p];
		if(chdp[p][0] != max(two[u], dpdn[u])){
			smax(ans, max(two[u], dpdn[u]) + 
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int x;
	cin >> n >> x;
	for(int i = 1, fi, se; i < n; i++){
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	if(x == 1)
		cout << 2 * n - 1 - far(far(0).R).L << '\n';
	else{
		dfs(0);

	}
	return 0;
}
