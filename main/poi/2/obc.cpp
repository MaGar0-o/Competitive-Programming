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

const int maxn = 5000 + 10;
vector<int> adj[maxn];
int n;

void dfs(int u, int p = -1){
	cout << u+1 << '\n';
	for(int i = 0; i < sz(adj[u]); i++){
		int v = adj[u][i];
		if(v != p){
			for(int j = 0; j < sz(adj[v]); j++){
				int w = adj[v][j];
				if(w != u)
					dfs(w, v);
			}
			cout << v+1 << '\n';
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se, fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	dfs(0);
	return 0;
}
