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

const int maxn = 1e5 + 85 - 69;
vector<int> adj[maxn];
int n;

pii dfs(int u, int p = -1){
	pii ret(-1, u);
	for(auto v : adj[u])
		if(v^p)
			smax(ret, dfs(v, u));
	ret.L++;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	LL ans1 = 1LL * n * (n - 1) / 2;
	LL ans2 = dfs(dfs(0).R).L;
	cout << ans2 << ' ' << ans1 << endl;
	return 0;
}
