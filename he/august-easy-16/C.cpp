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
vector<pii> adj[maxn];
int n, m, q;
int dis[maxn];
set<pii> s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se, fi--, se--;
		adj[fi].PB(MP(se, 0));
		adj[se].PB(MP(fi, 1));
	}
	memset(dis, 63, sizeof dis);
	dis[0] = 0;
	s.insert(MP(0, 0));
	while(sz(s)){
		int v = s.begin()->R;
		s.erase(s.begin());
		for(int i = 0; i < sz(adj[v]); i++){
			pii e = adj[v][i];
			if(dis[v] + (dis[v] & 1 ^ e.R) + 1 < dis[e.L]){
				s.erase(MP(dis[e.L], e.L));
				dis[e.L] = dis[v] + (dis[v] & 1 ^ e.R) + 1;
				s.insert(MP(dis[e.L], e.L));
			}
		}
	}
	for(int i = 0; i < q; i++){
		int x;
		cin >> x;
		if(x >= dis[n - 1])
			cout << "GGMU\n";
		else
			cout << "FML\n";
	}
	return 0;
}
