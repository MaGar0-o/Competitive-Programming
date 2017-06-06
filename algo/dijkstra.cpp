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

const int maxn = 1e5 + 10;
LL dis[maxn];
vector<pll> adj[maxn];
int n, m;
set<pll> s;

void dijkstra(int sou){
	memset(dis, 63, sizeof dis);
	dis[sou] = 0;
	s.insert(MP(0, sou));
	while(sz(s)){
		int u = s.begin()->R;
		s.erase(s.begin());
		for(auto e : adj[u]){
			int v = e.L;
			LL w = e.R;
			if(dis[u] + w < dis[v]){
				s.erase(MP(dis[v], v));
				dis[v] = dis[u] + w;
				s.insert(MP(dis[v], v));
			}
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> fi >> se >> th;
		fi--, se--;
		adj[fi].PB(MP(se, th));
		adj[se].PB(MP(fi, th));
	}
	dijkstra(0);
	for(int i = 0; i < n; i++)
		cout << dis[i] << ' ';
	cout << endl;
	return 0;
}
