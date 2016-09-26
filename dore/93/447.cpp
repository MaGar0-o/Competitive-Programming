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

const int maxn = 2e5 + 85 - 69,
	  maxm = 500,
	  maxl = 20,
	  maxa = 26;
queue<int> q;
int go[maxm][maxa],
	fail[maxm][maxa],
	f[maxm],
	par[maxn][maxl],
	car[maxn],
	h[maxn],
	ahof[maxn],
	sz, n, m, qu, k;
bool fosh[maxn];

void build_ac(void){
	for(int i = 0; i < k; i++)
		if(go[0][i] == -1)
			go[0][i] = 0;
	for(int i = 0; i < k; i++)
		if(go[0][i])
			q.push(go[0][i]);
	while(sz(q)){
		int u = q.front();
		q.pop();
		for(int i = 0; i < k; i++){
			if(go[u][i] != -1) fail[u][i] = u;
			else fail[u][i] = fail[f[u]][i];
			if(go[u][i] != -1){
				int v = go[u][i],
					w = f[u];
				w = fail[w][i];
				f[v] = go[w][i];
				q.push(v);
			}
		}
	}
	for(int i = 1; i <= sz; i++){
		fosh[i] |= fosh[f[i]];
		for(int j = 0; j < k; j++)
			if(go[i][j] == -1)
				go[i][j] = go[fail[i][j]][j];
	}
	return;
}

int lca(int u, int v){
	if(h[u] < h[v]) swap(v, u);
	for(int i = 0; h[u] - h[v]; i++)
		if(((h[u] - h[v]) >> i) & 1)
			u = par[u][i];
	if(v == u) return u;
	for(int i = maxl - 1; i >= 0; i--)
		if(par[u][i] != par[v][i])
			u = par[u][i], v = par[v][i];
	return par[u][0];
}

string get_str(int ptr){
	string str;
	while(ptr){
		str += char('a' + car[ptr]);
		ptr = par[ptr][0];
	}
	reverse(all(str));
	return str;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(go, -1, sizeof go);
	memset(par, -1, sizeof par);
	cin >> m >> k >> n >> qu;
	for(int i = 0; i < m; i++){
		string s;
		cin >> s;
		int ptr = 0;
		for(auto c : s){
			auto &nx = go[ptr][c - 'a'];
			if(nx == -1)
				nx = ++sz;
			ptr = nx;
		}
		fosh[ptr] = true;
	}
	build_ac();
	q.push(0);
	for(int built = 0; built < n;){
		int u = q.front();
		q.pop();
		for(int i = 0; i < k; i++){
			int fv = go[ahof[u]][i];
			if(fosh[fv]) continue;
			int v = ++built;
			car[v] = i;
			h[v] = h[u] + 1;
			par[v][0] = u;
			for(int j = 1; j < maxl and par[v][j - 1] != -1; j++)
				par[v][j] = par[par[v][j - 1]][j - 1];
			q.push(v);
			ahof[v] = fv;
		}
	}
	while(qu--){
		char ty;
		int fi, se;
		cin >> ty >> fi >> se;
		int p = lca(fi, se);
		if(ty == '#')
			cout << h[p] << '\n';
		else
			cout << (p == 0 ? "I'm a blackboard" : get_str(p)) << '\n';
	}
	return 0;
}
