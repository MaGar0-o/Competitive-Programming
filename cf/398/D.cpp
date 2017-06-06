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
#define endl '\n'

const int maxn = 5e4 + 85 - 69,
	  maxsq = 200;
int cnt[maxn];
bool onli[maxn];
vector<pair<char, pii> > quer;
set<int> adj[maxn];
int n, m, q;

inline void add_friend(int u, int v){
	adj[u].insert(v);
	adj[v].insert(u);
}

inline void del_friend(int u, int v){
	adj[u].erase(v);
	adj[v].erase(u);
}

bool isfriend(int u, int v){
	return adj[u].find(v) != adj[u].end();
}

void recalc(void){
	for(int i = 0; i < sz(quer); ++i){
		auto qu = quer[i];
		if(qu.L == 'O')
			onli[qu.R.L] = true;
		else if(qu.L == 'F')
			onli[qu.R.L] = false;
		else if(qu.L == 'A')
			add_friend(qu.R.L, qu.R.R);
		else
			del_friend(qu.R.L, qu.R.R);
	}
	quer.clear();
	memset(cnt, 0, sizeof cnt);
	for(int u = 0; u < n; u++)
		for(auto v : adj[u])
			cnt[u] += onli[v];
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	quer.reserve(1 << 9);
	cin >> n >> m >> q;
	int o;
	cin >> o;
	for(int i = 0; i < o; i++){
		int x;
		cin >> x, x--;
		onli[x] = true;
	}
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		add_friend(fi, se);
		cnt[fi] += onli[se];
		cnt[se] += onli[fi];
	}
	while(q--){
		if(sz(quer) == maxsq)
			recalc();
		char ty;
		int fi, se;
		cin >> ty >> fi;
		fi--;
		if(ty == 'O' or ty == 'F')
			quer.PB(MP(ty, MP(fi, fi)));
		else if(ty == 'A' or ty == 'D'){
			cin >> se, se--;
			quer.PB(MP(ty, MP(fi, se)));
		}
		else{
			int ans = cnt[fi];
			for(auto qu : quer){
				if(qu.R.L != fi) swap(qu.R.L, qu.R.R);
				if(qu.L == 'O'){
					onli[qu.R.L] = true;
					ans += isfriend(fi, qu.R.R);
				}
				else if(qu.L == 'F'){
					onli[qu.R.L] = false;
					ans -= isfriend(fi, qu.R.R);
				}
				else if(qu.L == 'A'){
					add_friend(qu.R.L, qu.R.R);
					ans += qu.R.L == fi and onli[qu.R.R];
				}
				else{
					del_friend(qu.R.L, qu.R.R);
					ans -= qu.R.L == fi and onli[qu.R.R];
				}
			}
			cout << ans << endl;
			for(int i = sz(quer) - 1; i >= 0; i--){
				auto qu = quer[i];
				if(qu.L == 'O')
					onli[qu.R.L] = false;
				else if(qu.L == 'F')
					onli[qu.R.L] = true;
				else if(qu.L == 'A')
					del_friend(qu.R.L, qu.R.R);
				else
					add_friend(qu.R.L, qu.R.R);
			}
		}
	}
	return 0;
}
