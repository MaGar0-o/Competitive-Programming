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

const int maxn = 15,
	  steps = 100000;
bool mark[maxn];
int end_time[maxn],
	a[maxn],
	indeg[maxn],
	n, m, f, h;
vector<int> adj[maxn],
	arr;
vector<pii> quick,
	kciuq;
queue<int> q;

int get_cost(void) {
	auto &ord = arr;

	for (int i = 0; i < n; i++) {
		int id = ord[i];
		int prv = i ? end_time[ord[i - 1]] : 0;
		end_time[id] = prv + a[id];
	}

	for (int u = 0; u < n; u++)
		for (auto v : adj[u])
			if (end_time[u] > end_time[v])
				return 1000000 * 1000;

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
	return cost;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	srand(time(0));

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
		arr.PB(u);
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

	int ans = get_cost();
	for (int _ = 0; _ < steps; _++) {
		while (true) {
			int init_cost = ans;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < i; j++) {
					swap(arr[i], arr[j]);
					int cost = get_cost();
					if (cost < ans)
						ans = cost;
					else
						swap(arr[i], arr[j]);
				}
			if (ans == init_cost) break;
		}
		
		for (int i = n - 1; i >= 0; i--) {
			int pos = rand() % i;
			for (int j = 0; j < i; j++, pos = (pos + 1) % i) {
				swap(arr[i], arr[j]);
				if (get_cost() != 1000 * 1000 * 1000)
					break;
				else
					swap(arr[i], arr[j]);
			}
		}
	}

	cout << ans << endl;
	/*for (int i = 0; i < n; i++)
		cerr << arr[i] << ' ';
	cerr << endl;*/

	//4 1 2 0 6 5 3
	//arr = {4, 1, 2, 0, 6, 5, 3};
	//cerr << get_cost() << endl;

	return 0;
}
