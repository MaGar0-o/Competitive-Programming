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

const int maxn = 5000;
LL cnt[maxn],
   C[3][maxn],
   ans;
vector<int> adj[maxn];
int n;

void dfs(int v, int p, int d = 0){
	cnt[d]++;
	for(int i = 0; i < sz(adj[v]); i++){
		int u = adj[v][i];
		if(u != p)
			dfs(u, v, d + 1);
	}
	return;
}

void calc(int st){
	memset(C, 0, sizeof C);
	for(int i = 0; i < sz(adj[st]); i++){
		int v = adj[st][i];
		memset(cnt, 0, sizeof cnt);
		dfs(v, st);
		for(int d = 0; d < n; d++){
			for(int j = 2; j; j--)
				C[j][d] += C[j - 1][d] * cnt[d];
			C[0][d] += cnt[d];
		}
	}
	for(int d = 0; d < n; d++)
		ans += C[2][d];
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
	for(int i = 0; i < n; i++)
		calc(i);
	cout << ans << endl;
	return 0;
}
