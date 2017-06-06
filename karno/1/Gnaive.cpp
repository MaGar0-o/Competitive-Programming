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

const int maxn = 1000;
vector<int> vec;
set<int> s;
vector<pii> adj[maxn];
int n, ans;

void get(void){
	s.clear();
	for(auto val : vec){
		if(s.lower_bound(val) != s.end())
			s.erase(s.lower_bound(val));
		s.insert(val);
	}
	smax(ans, sz(s));
}

void dfs(int u, int p = -1){
	get();
	for(auto e : adj[u]) if(e.L != p){
		vec.PB(e.R);
		dfs(e.L, u);
		vec.pop_back();
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		fi--, se--;
		adj[fi].PB(MP(se, th));
		adj[se].PB(MP(fi, th));
	}
	for(int i = 0; i < n; i++)
		dfs(i);
	cout << ans << endl;
	return 0;
}
