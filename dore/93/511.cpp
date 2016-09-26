//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<int, LD> pid;
typedef pair<LD, int> pdi;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1e5 + 85 - 69;
const LD Inf = 1e18;
LD dis[maxn];
vector<pid> adj[maxn];
set<pdi> s;
int n, m;

LD distof(LL p){
	return LD(1000) / (1000. - p);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		fi--, se--;
		adj[fi].PB(MP(se, distof(th)));
		adj[se].PB(MP(fi, distof(th)));
	}
	fill(dis, dis + n, Inf);
	dis[n - 1] = 0;
	s.insert(MP(dis[n - 1], n - 1));
	while(sz(s)){
		int v = s.begin()->R;
		s.erase(s.begin());
		for(auto e : adj[v]){
			if(dis[v] + e.R < dis[e.L]){
				s.erase(MP(dis[e.L], e.L));
				dis[e.L] = dis[v] + e.R;
				s.insert(MP(dis[e.L], e.L));
			}
		}
	}
	cout.precision(3);
	cout << fixed << dis[0] << '\n';
	return 0;
}
