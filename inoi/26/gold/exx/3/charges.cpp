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

const int maxn = 1e6 + 85 - 69;
LL dis[maxn],
   wei[maxn];
int frm[maxn],
	too[maxn],
	n, m;
bool inq[maxn];
vector<int> vec[maxn];
vector<pll> adj[maxn];
queue<int> q;
set<pll> s;

inline void adde(int u, int v, LL val){
	adj[u].PB(MP(v, val));
	return;
}

int getid(int u, int w){
	int lo = -1, hi = sz(vec[u]);
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if(wei[vec[u][mid]] <= w)
			lo = mid;
		else
			hi = mid;
	}
	return hi;
}

bool cmp(int i, int j){
	return wei[i] < wei[j];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		fi--, se--;
		frm[i] = fi;
		too[i] = se;
		wei[i] = th;
		vec[fi].PB(i);
	}
	for(int i = m; i < m + m; i++){
		frm[i] = too[i - m];
		too[i] = frm[i - m];
		wei[i] = wei[i - m];
		vec[frm[i]].PB(i);
	}
	m += m;
	for(int i = 0; i < n; i++){
		sort(all(vec[i]), cmp);
		for(int j = 0; j + 1 < sz(vec[i]); j++){
			adde(vec[i][j]<<1|0, vec[i][j + 1]<<1|0, (wei[vec[i][j + 1]] - wei[vec[i][j]])<<1);
			adde(vec[i][j + 1]<<1|1, vec[i][j]<<1|1, wei[vec[i][j]] - wei[vec[i][j + 1]]);
		}
	}
	for(int i = 0; i < m; i++){
		int id = getid(too[i], wei[i]);
		if(id < sz(vec[too[i]])){
			adde(i<<1|0, vec[too[i]][id]<<1|0, 2*wei[vec[too[i]][id]] - wei[i]);
			adde(i<<1|1, vec[too[i]][id]<<1|0, 2*wei[vec[too[i]][id]] - wei[i]);
		}
		if(id){
			id--;
			adde(i<<1|0, vec[too[i]][id]<<1|1, wei[vec[too[i]][id]]);
			adde(i<<1|1, vec[too[i]][id]<<1|1, wei[vec[too[i]][id]]);
		}
	}
	memset(dis, 63, sizeof dis);
	for(int i = 0; i < m; i++)
		if(frm[i] == 0){
			dis[i<<1|0] = wei[i]<<1, q.push(i<<1|0), inq[i<<1|0] = true,s.insert(MP(wei[i]<<1, i<<1|0));
			dis[i<<1|1] = wei[i]<<1, q.push(i<<1|1), inq[i<<1|1] = true,s.insert(MP(wei[i]<<1, i<<1|1));
		}
	while(sz(s)){
		int u = s.begin()->R;
		s.erase(s.begin());
		for(auto e : adj[u]){
			LL w = e.R;
			int v = e.L;
			if(dis[u] + w < dis[v]){
				s.erase(MP(dis[v], v));
				dis[v] = dis[u] + w;
				s.insert(MP(dis[v], v));
			}
		}
	}
	/*while(sz(q)){
		int u = q.front();
		cout << u << endl;
		q.pop();
		inq[u] = false;
		for(auto e : adj[u]){
			int v = e.L;
			LL w = e.R;
			if(dis[u] + w < dis[u]){
				dis[v] = dis[u] + w;
				if(!inq[v])
					q.push(v), inq[v] = true;
			}
		}
	}*/
	LL ans = LONG_MAX;
	for(int i = 0; i < m; i++)
		if(too[i] == n - 1)
			smin(ans, min(dis[i<<1], dis[i<<1|1]));
	cout << ans << endl;
	return 0;
}
