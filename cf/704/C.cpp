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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		int cnt;
		cin >> cnt;
		for(int j = 0; j < cnt; j++){
			int x;
			cin >> x;
			x < 0 ? x++ : x--;
			adj[0][i].PB({abs(x), tyof(x)});
			adj[1][abs(x)].PB({i, tyof(x)});
		}
	}
	for(int i = 0; i < n; i++){
		if(sz(adj[0][i]) & 1)
			dfs(0, i);
		dp[0][0] = 
	}
	return 0;
}
