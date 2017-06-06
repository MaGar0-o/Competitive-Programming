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
#define prev prv

const int maxn = 15;
bool mark[maxn];
int a[maxn],
//	arr[maxn],
	ord[maxn],
	prev[maxn + 1],
	indeg[maxn],
	end_time[maxn],
	n, m, f, h,
	ans = 1000 * 1000 * 1000;
vector<int> adj[maxn],
	quick[maxn],
	kciuq[maxn];

void recurse(int pos = 0, int cost = 0, int time = 0){
	if (cost >= ans)
		return;
	if (pos == n) {
		/*
		if (cost < ans) {
			cerr << cost << ": ";
			for (int i = 0; i < n; i++)
				cerr << arr[i] << ' ';
			cerr << endl;
		}
		*/
		smin(ans, cost);
		return;
	}
	int nxt = n;
	for (int i = prev[n]; ~i; nxt = i, i = prev[i]) if (!indeg[ord[i]]) {
		int u = ord[i];
		end_time[u] = time + a[u];

		int plus = 0;
		for (auto v : kciuq[u])
			if (mark[v])
				plus += max(0, 15 - end_time[u] + end_time[v]);
		for (auto v : quick[u])
			if (mark[v])
				plus += end_time[u] - end_time[v];

		for (auto v : adj[u])
			indeg[v]--;
		mark[u] = true;
		prev[nxt] = prev[i];
		//arr[pos] = u;

		recurse(pos + 1, cost + plus, end_time[u]);

		prev[nxt] = i;
		mark[u] = false;
		for (auto v : adj[u])
			indeg[v]++;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	srand(time(0));

	cin >> n >> m >> f >> h;

	iota(prev, prev + n + 1, -1);
	iota(ord, ord + n, 0);
	random_shuffle(ord, ord + n);
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		indeg[se]++;
	}
	for (int i = 0; i < f; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		quick[fi].PB(se);
		quick[se].PB(fi);
	}
	for (int i = 0; i < h; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		kciuq[fi].PB(se);
		kciuq[se].PB(fi);
	}

	recurse();

	cout << (ans == 1000 * 1000 * 1000 ? "varshekast shodin" : to_string(ans)) << endl;
	return 0;
}
