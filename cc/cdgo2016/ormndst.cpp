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

const int maxn = 1e4 + 85 - 69;
vector<pii> adj[maxn];
set<pii> s;
int n, m, dis[maxn];

void solve(void){
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		adj[i].clear();
	for(int i = 0; i < m; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		fi--, se--;
		adj[fi].PB(MP(se, th));
		adj[se].PB(MP(fi, th));
	}
	int sou;
	cin >> sou, sou--;
	memset(dis, 63, sizeof dis);
	dis[sou] = 0;
	s.insert(MP(dis[sou], sou));
	while(sz(s)){
		int v = s.begin()->R;
		s.erase(s.begin());
		for(auto e : adj[v])
			if((dis[v] | e.R) < dis[e.L]){
				s.erase(MP(dis[e.L], e.L));
				dis[e.L] = dis[v] | e.R;
				s.insert(MP(dis[e.L], e.L));
			}
	}
	for(int i = 0; i < n; i++)
		cout << dis[i] << ' ';
	cout << '\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
