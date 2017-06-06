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

const int maxn = 1e5;
vector<int> adj[maxn];
int ord[maxn],
	par[maxn];
bool mark[maxn];
int n, m;

bool degcmp(int i, int j) {
	return sz(adj[i]) > sz(adj[j]);
}

int root(int u) { return par[u] < 0 ? u : par[u] = root(par[u]);}

bool merge(int u, int v) {
	if ((u = root(u)) == (v = root(v)))
		return false;
	if (par[u] > par[v])
		swap(u, v);
	par[u] += par[v];
	par[v] = u;
	return true;
}

void solve(void) {
	cin >> n >> m;
	memset(par, -1, n<<2);
	memset(mark, false, n);
	for (int i = 0; i < n; i++)
		adj[i].clear();
	for (int i = 0; i < m; i++) {
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	iota(ord, ord + n, 0);
	sort(ord, ord + n, degcmp);
	int ptr = 0,
		comp = n;
	vector<int> ans;
	for (int d = n - 1; d >= 0; d--) {
		while (ptr < n and sz(adj[ord[ptr]]) > d) {
			mark[ord[ptr]] = true;
			for (auto v : adj[ord[ptr]])
				if (mark[v])
					comp -= merge(ord[ptr], v);
			ptr++;
		}
		ans.PB(comp - 1);
	}
	reverse(all(ans));
	for (auto val : ans)
		cout << val << ' ';
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
