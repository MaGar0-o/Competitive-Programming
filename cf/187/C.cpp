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
	vec;
vector<pair<int, pii> > merq;
int par[maxn],
	dis[maxn];
deque<int> q[maxn];
int n, m, k;
set<int> s;

int root(int u){ return par[u]==u or par[u] == -1 ? u : par[u] = root(par[u]);}

void merge(int u, int v){
	if((u = root(u)) == (v = root(v))) return;
	if(sz(q[u]) < sz(q[v])) swap(v, u);
	par[v] = u;
	while(sz(q[v])){
		q[u].push_back(q[v].front());
		q[v].pop_front();
	}
	s.erase(v);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	merq.reserve(1 << 17);
	memset(par, -1, sizeof par);
	cin >> n >> m >> k;
	for(int i = 0; i < k; i++){
		int x;
		cin >> x, x--;
		vec.PB(x);
	}
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	int st, en;
	cin >> st >> en, st--, en--;
	vec.PB(en);
	sort(all(vec));
	vec.resize(unique(all(vec)) - vec.begin());
	/*for(auto i : vec){
		s.insert(i);
		q[i].push_back(i);
		par[i] = i;
	}
	int ans = 0;
	for(ans = 1; ans <= n; ans++){
		for(auto id : s){
			if(!sz(q[id])) continue;
			int lst = q[id].back();
			while(1){
				int u = q[id].front();
				q[id].pop_front();
				for(auto v : adj[u]){
					if(par[v] == -1){
						par[v] = id;
						dis[v] = dis[u] + 1;
						q[id].push_back(v);
					}
					else
						merq.PB(MP(dis[v] + dis[u] + 1, MP(id, root(v))));
				}
				if(u == lst) break;
			}
		}
		sort(all(merq));
		for(auto P : merq){
			merge(P.R.L, P.R.R);
			if(root(st) == root(en)){
				cout << P.L << endl;
				return 0;
			}
		}
		merq.clear();
	}
	cout << -1 << endl;*/
	return 0;
}
