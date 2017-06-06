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

const int maxn = 1e5;
int dp[maxn],
	pd[maxn],
	comp[maxn],
	cocnt;
bool mark[maxn];
vector<int> vec[maxn],
	adj[maxn],
	jda[maxn];
int n, m;
stack<int> stc;

void dfs(int v){
	if(mark[v]) return;
	mark[v] = true;
	for(auto u : adj[v])
		dfs(u);
	stc.push(v);
	return;
}

void dfs2(int v){
	if(mark[v]) return;
	mark[v] = true;
	comp[v] = cocnt;
	vec[cocnt].PB(v);
	for(auto u : jda[v])
		dfs2(u);
	return;
}

int main(){
	ifstream cin("grass.in");
	ofstream cout("grass.out");
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		jda[se].PB(fi);
	}
	for(int i = 0; i < n; i++)
		dfs(i);
	memset(mark, false, sizeof mark);
	while(sz(stc)){
		int v = stc.top();
		stc.pop();
		if(mark[v])
			continue;
		dfs2(v);
		cocnt++;
	}
	memset(dp, -1, sizeof dp);
	memset(pd, -1, sizeof pd);
	dp[comp[0]] = pd[comp[0]] = 0;
	for(int i = comp[0]; i < cocnt; i++)
		if(~dp[i])
			for(auto v : vec[i])
				for(auto u : adj[v])
					if(comp[u] > comp[v])
						smax(dp[comp[u]], dp[i] + sz(vec[comp[u]]));
	for(int i = comp[0]; i >= 0; i--)
		if(~pd[i])
			for(auto v : vec[i])
				for(auto u : jda[v])
					if(comp[u] < comp[v])
						smax(pd[comp[u]], pd[i] + sz(vec[comp[u]]));
	int ans = 0;
	for(int i = 0; i <= comp[0]; i++)
		if(~pd[i])
			for(auto v : vec[i])
				for(auto u : adj[v])
					if(comp[u] >= comp[0] and ~dp[comp[u]])
						smax(ans, pd[i] + dp[comp[u]]);
	cout << ans + sz(vec[comp[0]]) << endl;
	return 0;
}
