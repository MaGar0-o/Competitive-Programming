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

const int maxn = 1e5 + 10,
	  sq = 320;
int t, n, q;
LL ans[maxn],
   mx[maxn],
   a[maxn],
   m;
vector<LL> psu[maxn],
	vec[maxn];

void recalc(int id){
	mx[id] = 0;
	ans[id] = 0;
	vec[id].clear();
	psu[id].clear();
	psu[id].PB(0);
	for(int i = id * sq; i < (id + 1) * sq; i++){
		smax(mx[id], a[i]);
		vec[id].PB(mx[id]);
		psu[id].PB(psu[id].back() + vec[id].back());
		ans[id] += m - mx[id];
	}
}

void get(void){
	LL ret = 0;
	LL cur = 0;
	for(int i = 0; i <= (n - 1) / sq; i++){
		int id = lower_bound(all(vec[i]), cur) - vec[i].begin();
		LL val = ans[i] - cur * id + psu[i][id];
		ret += val;
		/*cout << i << ": " << a[i] << ' ' << ans[i] << ' ' << val << ' ' << "#" << cur << ' ';
		cout << "@";
		for(auto v : vec[i])
			cout << v << ' ';
		cout << endl;*/
		smax(cur, mx[i]);
	}
	cout << ret << ' ';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> t >> n >> m;
	fill(a, a + maxn, m);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < maxn; i += sq)
		recalc(i / sq);
	int q;
	cin >> q;
	get();
	while(q--){
		int fi, se;
		cin >> fi >> se, fi--;
		a[fi] = se;
		recalc(fi / sq);
		get();
	}
	return 0;
}
