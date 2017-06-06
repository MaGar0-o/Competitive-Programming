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
vector<int> vec[maxn],
	adj[maxn];
int col[maxn],
	ans[maxn],
	n, c;

void dfs(int v){
	if(sz(vec[col[v]])) ans[v] = vec[col[v]].back();
	else ans[v] = -2;
	vec[col[v]].PB(v);
	for(int i = 0; i < sz(adj[v]); i++){
		int u = adj[v][i];
		dfs(u);
	}
	vec[col[v]].pop_back();
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> c;
	for(int i = 1; i < n; i++){
		int x; cin >> x, x--; adj[x].PB(i);
	}
	for(int i = 0; i < n; i++)
		cin >> col[i], col[i]--;
	dfs(0);
	for(int i = 0; i < n; i++)
		cout << ans[i]+1 << ' ';
	return 0;
}
