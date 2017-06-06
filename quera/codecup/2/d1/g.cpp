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

void dfs(int u, int pe = -1){
	for(auto e : adj[u]){
		if(pe == e) return;
		int v = frm[e]^too[e]^u;
		dfs(v, e);
		for(auto vv : vec[v]){

		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++)
		cin >> vel[i];
	for(int i = 0; i < m; i++){
		int fi;
		cin >> fi;
		fi--;
		leaf.PB(fi);
	}
	for(int i = 0; i < n - 1; i++){
		int fi, se, th;
		cin >> fi >> se >> th, fi--, se--;
		adj[fi].PB(i);
		adj[se].PB(i);
		wei[i] = th;
		frm[i] = fi;
		too[i] = se;
	}
	dfs(0);
	cout << sz(vec[0]) << '\n';
	for(auto ver : vec[0])
		cout << ver << ' ';
	cout << '\n';
	return 0;
} 
