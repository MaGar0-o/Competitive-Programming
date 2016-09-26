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

const int maxn = 2e4 + 85 - 69,
	  maxk = 2e2 + 85 - 69;
int hub[maxk];
LL dis[maxk][maxn],
   sid[maxk][maxn];
vector<pll> adj[maxn],
	jda[maxn];
set<pll> s;
int n, m, q, k;

void dij(int id){
	int sou = hub[id];
	dis[id][sou] = 0;
	s.insert(MP(0, sou));
	while(sz(s)){
		int v = s.begin()->R;
		s.erase(s.begin());
		for(auto e : adj[v])
			if(dis[id][v] + e.R < dis[id][e.L]){
				s.erase(MP(dis[id][e.L], e.L));
				dis[id][e.L] = dis[id][v] + e.R;
				s.insert(MP(dis[id][e.L], e.L));
			}
	}
	return;
}

void jid(int id){
	int sou = hub[id];
	sid[id][sou] = 0;
	s.insert(MP(0, sou));
	while(sz(s)){
		int v = s.begin()->R;
		s.erase(s.begin());
		for(auto e : jda[v])
			if(sid[id][v] + e.R < sid[id][e.L]){
				s.erase(MP(sid[id][e.L], e.L));
				sid[id][e.L] = sid[id][v] + e.R;
				s.insert(MP(sid[id][e.L], e.L));
			}
	}
	return;
}

int main(){
	ifstream cin("vacationgold.in");
	ofstream cout("vacationgold.out");
	cin >> n >> m >> k >> q;
	for(int i = 0; i < m; i++){
		int fi, se, th;
		cin >> fi >> se >> th, fi--, se--;
		adj[fi].PB(MP(se, th));
		jda[se].PB(MP(fi, th));
	}
	memset(dis, 63, sizeof dis);
	memset(sid, 63, sizeof sid);
	for(int i = 0; i < k; i++){
		cin >> hub[i], hub[i]--;
		dij(i);
		jid(i);
	}
	LL ret = 0,
	   cnt = 0;
	for(int i = 0; i < q; i++){
		int fi, se;
		cin >> fi >> se, fi--, se--;
		LL ans = dis[maxk - 1][maxn - 1];
		for(int j = 0; j < k; j++)
			smin(ans, sid[j][fi] + dis[j][se]);
		if(ans < dis[maxk - 1][maxn - 1]){
			cnt++;
			ret += ans;
		}
	}
	cout << cnt << endl << ret << endl;
	return 0;
}
