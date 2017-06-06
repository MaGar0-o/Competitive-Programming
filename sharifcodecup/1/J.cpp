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

const int maxn = 1000;
int match[2][maxn];
bool mark[maxn];
int n, m, k, ans;
vector<int> adj[maxn];

bool dfs(int v){
	if(mark[v]) return false;
	mark[v] = true;
	for(auto u : adj[v])
		if(match[1][u] == -1 or dfs(match[1][u])){
			match[0][v] = u;
			match[1][u] = v;
			return true;
		}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	cin >> k;
	for(int i = 0; i < k; i++){
		int fi, se;
		cin >> fi >> se, fi--, se--;
		adj[fi].PB(se);
	}
	memset(match, -1, sizeof match);
	bool found;
	do{
		found = false;
		memset(mark, false, sizeof mark);
		for(int i = 0; i < n; i++)
			if(match[0][i] == -1)
				if(dfs(i))
					ans++, found = true;
	}while(found);
	cout << ans << endl;
	return 0;
}
