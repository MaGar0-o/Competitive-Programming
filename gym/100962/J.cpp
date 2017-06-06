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

const int maxn = 5e5 + 10;
vector<pair<int, char> > adj[maxn];
pii dp[maxn],
	pd[maxn],
	mx[maxn][2][2];
int par[maxn],
	n, m;
string s, t;

void dfs(int u, int p = -1, char c = '\0'){
	par[u] = p;
	dp[u] = MP(0, u);
	pd[u] = MP(0, u);
	for(auto e : adj[u]) if(e.L ^ p){
		int v = e.L;
		char c = e.R;
		dfs(v, u, c);
		smax(dp[u], dp[v]);
		smax(pd[u], pd[v]);
		if(dp[v] > mx[u][0][0])
			mx[u][0][1] = mx[u][0][0], mx[u][0][0] = dp[v];
		else if(dp[v] > mx[u][0][1])
			mx[u][0][1] = dp[v];
		if(pd[v] > mx[u][1][0])
			mx[u][1][1] = mx[u][1][0], mx[u][1][0] = pd[v];
		else if(pd[v] > mx[u][1][1])
			mx[u][1][1] = pd[v];
	}
	if(dp[u].L < m and s[dp[u].L] == c) dp[u].L++;
	if(pd[u].L < m and t[pd[u].L] == c) pd[u].L++;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1, fi, se; i < n; i++){
		char c;
		cin >> fi >> se >> c, fi--, se--;
		adj[fi].PB(MP(se, c));
		adj[se].PB(MP(fi, c));
	}
	cin >> s;
	t = s;
	reverse(all(t));
	dfs(0);
	//for(int i = 0; i < n; i++)
	//	cout << "#" << i+1 << ' ' << dp[i].L << ' ' << pd[i].L << ' ' << '\n';
	for(int i = 1; i < n; i++){
		if(dp[i].L == m){
			cout << dp[i].R + 1 << ' ' << par[i] + 1 << '\n';
			return 0;
		}
		else if(pd[i].L == m){
			cout << par[i] + 1 << ' ' << pd[i].R + 1 << '\n';
			return 0;
		}
	}
	for(int i = 1; i < n; i++){
		int p = par[i];
		int id = mx[p][1][0] == pd[i];
		if(mx[p][1][id].L + dp[i].L >= m){
			cout << dp[i].R + 1 << ' ' << mx[p][1][id].R + 1 << '\n';
			return 0;
		}
		id = mx[p][0][0] == dp[i];
		if(mx[p][0][id].L + pd[i].L >= m){
			cout << mx[p][0][id].R + 1 << ' ' << pd[i].R + 1 << '\n';
			return 0;
		}
	}
	cout << "-1 -1\n";
	return 0;
}
