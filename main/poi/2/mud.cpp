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
#define dn pop

const int maxn = 1e5 + 10;
vector<int> adj[maxn];
LL ans[maxn],
   pop[maxn],
   wei[maxn],
   popall;
pii mp[maxn];
int n, sz;

void dfs0(int u){
	for(int i = 0; i < sz(adj[u]); i++){
		int v = adj[u][i];
		dfs0(v), pop[u] += pop[v];
	}
}

void dfs1(int u){
	for(int i = 0; i < sz(adj[u]); i++){
		int v = adj[u][i];
		ans[v] = ans[u] - dn[v] * wei[v] + (popall - dn[v]) * wei[v];
		dfs1(v);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	mp[0] = MP(-1, -1);
	cin >> n >> pop[(sz=0)++];
	popall = pop[0];
	for(int i = 0; i < n; i++){
		int k;
		cin >> k;
		int p = 0;
		LL sum = 0;
		for(int j = 0; j < k; j++){
			adj[p].PB(sz);
			cin >> wei[sz] >> pop[sz];
			popall += pop[sz];
			sum += wei[sz];
			ans[0] += pop[sz] * sum;
			mp[sz] = MP(i, j);
			p = sz++;
		}
	}
	dfs0(0);
	dfs1(0);
	int id = min_element(ans, ans + sz) - ans;
	cout << ans[id] << '\n';
	cout << mp[id].L+1 << ' ' << mp[id].R+1 << '\n';
	return 0;
}
