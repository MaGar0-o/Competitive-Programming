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

const int maxn = 15;
bool mark[maxn];
int ord[maxn],
	a[maxn],
	indeg[maxn],
	begin_time[maxn],
	end_time[maxn];
vector<int> adj[maxn];
vector<pii> quick,
	kciuq;
queue<int> q;
int n, m, f, h;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> f >> h;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++) {
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		indeg[se]++;
	}
	for (int i = 0; i < f; i++) {
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		quick.PB(MP(fi, se));
	}
	for (int i = 0; i < h; i++) {
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		kciuq.PB(MP(fi, se));
	}

	for (int i = 0; i < n; i++)
		if (!indeg[i]) {
			q.push(i);
			mark[i] = true;
		}
	while (sz(q)) {
		int u = q.front();
		q.pop();
		for (auto v : adj[u]) {
			indeg[v]--;
			if (!indeg[v]) {
				q.push(v);
				mark[v] = true;
			}
		}
	}
	if (count(mark, mark + n, false)) {
		cout << "varshekast shodin" << endl;
		return 0;
	}

	iota(ord, ord + n, 0);
	int ans = 1000000;
	do {
		bool failed = false;
		
		for (int i = 0; i < n; i++) {
			int id = ord[i];
			int prv = i ? end_time[ord[i - 1]] : 0;
			end_time[id] = prv + a[id];
		}
		
		for (int u = 0; u < n and not failed; u++)
			for (auto v : adj[u]) {
				if (end_time[u] > end_time[v]) {
					failed = true;
					break;
				}
			}
		if (failed) continue;
		
		int cost = 0;
		for (auto zood : quick) {
			int u = zood.L,
				v = zood.R;
			int d = abs(end_time[v] - end_time[u]);
			cost += d;
		}
		for (auto dooz : kciuq) {
			int u = dooz.L,
				v = dooz.R;
			int d = abs(end_time[v] - end_time[u]);
			cost += max(0, 15 - d);
		}
		
		smin(ans, cost);
	} while (next_permutation(ord, ord + n));
	
	cout << ans << endl;

	return 0;
}
