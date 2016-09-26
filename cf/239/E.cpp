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
	cin >> n;
	for(int i = 1; i < n; i++){
		cin >> frm[i] >> too[i];
		frm[i]--, too[i]--;
		adj[frm[i]].PB(MP(i, 0));
		adj[too[i]].PB(MP(i, 1));
	}
	for(int i = 0; i < n; i++){
		memset(mark, false, sizeof mark);
		vec.clear();
		dfs(i);
		for(auto v : vec){
			ans[v] = cnt[v] = 0;
			dfs2(v);
		}
	}
	return 0;
}
