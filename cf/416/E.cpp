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

const int maxn = 500;
LL dis[maxn],
   ans[maxn],
   ind[maxn];

void dij(int sou){
	memset(dis, 63, sizeof dis);
	memset(mark, false, sizeof mark);
	memset(ans, 0, sizeof ans);
	memset(ind, 0, sizeof ind);
	for(int i = 0; i < n; i++)
		vec[i].clear(), cev[i].clear();
	dis[sou] = 0;
	for(int i = 0; i < n; i++){
		int v = -1;
		for(int j = 0; j < n; j++)
			if(!mark[i] and (v == -1 or dis[i] <= dis[v]))
				v = i;
		mark[v] = true;
		for(int j = 0; j < n; j++)
			if(!mark[j])
				relax(v, j);
	}
	for(int i = 0; i < n; i++)
		for(auto u : cev[i])
			vec[u].PB(i), ind[i]++;
	while(sz(q)){
		int v = q.front();
		q.pop();
		for(auto u : adj[v]){
			ans[u] += ans[v];
			ind[u] = 0;
			if(!ind[u])
				q.push(u);
		}
	}
	for(int i = sou + 1; i < n; i++)
		cout << ans[i] << ' ';
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(adj, 63, sizeof adj);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		fi--, se--;
		adj[fi][se] = adj[se][fi] = th;
	}
	for(int i = 0; i < n; i++)
		dij(i);
	return 0;
}
