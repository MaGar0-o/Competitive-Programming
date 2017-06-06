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

const int maxn = 2e5 + 85 - 69;
int cur[maxn],
	cnt[maxn],
	dp[maxn],
	a[maxn],
	n, k, sou;
vector<int> adj[maxn];

void dfs0(int u, int p = -1){
	for(auto v : adj[u])
		if(v^p)
			cnt[u] += cnt[v];
	return;
}

void dfs1(int u, int p = -1){
	dp[u] = cur[u];
	for(auto v : adj[u])
		if(v^p){
			dfs1(v, u);
			if(dp[v] >= 0 or cnt[v])
				dp[u] += dp[v];
		}
	return;
}

int get(int val){
	for(int i = 0; i < n; i++)
		if(a[i] >= val)
			cur[i] = +1;
		else
			cur[i] = -1;
	dfs1(sou);
	return dp[sou];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < k; i++){
		cin >> sou, sou--;
		cnt[sou] = 1;
	}
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	dfs0(sou);
	int lo = 0,
		hi = 2e5 + 100;
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if(get(mid) >= 0)
			lo = mid;
		else
			hi = mid;
	}
	cout << lo << '\n';
	return 0;
}
