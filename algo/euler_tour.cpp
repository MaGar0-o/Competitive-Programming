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
vector<int> adj[maxn],
	tour;
int frm[maxn],
	too[maxn];
int n, m;
bool mark[maxn];

void dfs(int v){
	while(sz(adj[v])){
		int e = adj[v].back();
		adj[v].pop_back();
		if(mark[e]) continue;
		mark[e] = true;
		dfs(frm[e] + too[e] - v);
	}
	tour.PB(v);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> frm[i] >> too[i], too[i]--, frm[i]--;
		//adj[too[i]].PB(i);
		adj[frm[i]].PB(i);
	}
	dfs(frm[0]);
	for(auto v : tour)
		cout << v+1 << ' ';
	cout << endl;
	return 0;
}
