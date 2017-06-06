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

const int maxn = 1000 * 100 + 85 - 69;
const LL Mod = 1000 * 1000 * 1000 + 7;
vector<int> adj[maxn];
LL dp[2][maxn];
LL wei[maxn],
   to[maxn],
   fr[maxn],
   le[maxn],
   ri[maxn],
   siz[maxn];
int n;
LL k;

int other(int e, int v){
	return to[e] == v ? fr[e] : to[e];
}

void dfs(int v, int p = -1){
	siz[v] = 1;
	for(auto e : adj[v]){
		int u = other(e, v);
		if(u == p)
			continue;
		dfs(u, v);
		siz[v] += siz[u];
		wei[e] = siz[u] * (n - siz[u]);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i + 1 < n; i++){
		int fi, se, th, fo;
		cin >> fi >> se >> th >> fo;
		fi--, se--;
		adj[fi].PB(i);
		adj[se].PB(i);
		fr[i] = fi, to[i] = se;
		le[i] = th, ri[i] = fo;
	}
	dfs(0);
	for(int i = 0; i+1 < n; i++)
		k -= wei[i] * le[i], ri[i] -= le[i];
	if(k < 0 or n >= 320){
		cout << 0 << endl;
		return 0;
	}
	dp[1][0] = 1;
	for(int i = 0; i + 1 < n; i++){
		int cur = i&1,
			pre = i&1^1;
		for(int j = 0; j <= k; j++){
			dp[cur][j] = dp[pre][j];
			if(j - wei[i] >= 0){
				dp[cur][j] += dp[cur][j - wei[i]];
				dp[cur][j] %= Mod;
			}
			if(j - wei[i] * (ri[i] + 1) >= 0){
				dp[cur][j] -= dp[pre][j - wei[i] * (ri[i] + 1)];
				dp[cur][j] %= Mod;
			}
		}
	}
	LL ans = 0;
	for(int j = 0; j <= k; j++)
		ans = (ans + dp[n&1][j]) % Mod;
	cout << (ans + Mod) % Mod << endl;
	return 0;
}
