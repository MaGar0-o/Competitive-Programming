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

const int maxn = 305;
const LL Mod = 9901;
int a[maxn], b[maxn];
LL fact[maxn],
   P[maxn],
   ans;
int n, m;
bool mark[maxn];
vector<int> adj[maxn];
bool dfsret;

void dfs(int v){
	if(sz(adj[v]) == 1) dfsret = 1;
	mark[v] = true;
	for(auto u : adj[v])
		if(!mark[u])
			dfs(u);
	return;
}

LL func(LL mask){
	if(__builtin_popcount(mask) & 1)
		return -1;
	return +1;
}

bool check(int mask){
	for(int i = 0; i < n; i++)
		adj[i].clear();
	memset(mark, false, sizeof mark);
	for(int i = 0; i < m; i++)
		if((mask >> i) & 1)
			adj[a[i]].PB(b[i]), adj[b[i]].PB(a[i]);
	dfs(0);
	for(int i = 0; i < n; i++)
		if(!mark[i] or sz(adj[i]) != 2)
			return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	fact[0] = P[0] = 1;
	for(LL i = 1; i < maxn; i++){
		fact[i] = (fact[i - 1] * i) % Mod;
		P[i] = (P[i - 1] << 1) % Mod;
	}
	cin >> n >> m;
	for(int i = 0; i < m; i++)
		cin >> a[i] >> b[i], a[i]--, b[i]--;
	for(int mask = 0; mask < (1 << m); mask++){
		if(check(mask)){
			ans = (ans + 2*func(mask)) % Mod;
			continue;
		}
		for(int i = 0; i < n; i++)
			adj[i].clear();
		memset(mark, false, sizeof mark);
		for(int i = 0; i < m; i++)
			if((mask >> i) & 1)
				adj[a[i]].PB(b[i]), adj[b[i]].PB(a[i]);
		int cnt = 0, cnt2 = 0;
		bool an = false;
		for(int i = 0; i < n; i++){
			if(sz(adj[i]) > 2) an = true;
			if(!mark[i] and sz(adj[i])){
				dfsret = 0;
				dfs(i);
				if(!dfsret) an = true;
				cnt++, cnt2++;
			}
			else if(sz(adj[i]) == 0)
				cnt2++;
		}
		if(an) continue;
		ans = (ans + fact[cnt2 - 1] * P[cnt] * func(mask)) % Mod;
	}
	cout << ((ans&1) ? (ans + Mod) / 2 : ans / 2) << '\n';
	return 0;
}
