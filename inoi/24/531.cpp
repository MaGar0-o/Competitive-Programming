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

const int maxn = 5e5 + 85 - 69;
int a[maxn],
	seg[maxn * 4],
	laz[maxn * 4],
	q1[maxn],
	q2[maxn],
	n, q;
char type[maxn];
vector<int> all;

void seg_add(int val, int st, int en, int l = 0, int r = sz(all), int id = 1){
	if(st >= r or en <= l)
		return;
	if(st <= l and r <= en){
		seg[id] += val;
		laz[id] += val;
		return;
	}
	int mid = (l + r) >> 1;
	//push(id);
	seg_add(val, st, en, l, mid, id * 2 + 0);
	seg_add(val, st, en, mid, r, id * 2 + 1);
	seg[id] = max(seg[id * 2 + 0], seg[id * 2 + 1]) + laz[id];
	return;
}

int get(int st, int en, int l = 0, int r = sz(all), int id = 1){
	if(st >= r or en <= l) return -100000000;
	if(st <= l and r <= en) return seg[id];
	int mid = (l + r) >> 1;
	//push(id);
	return max(get(st, en, l, mid, id * 2 + 0),
			get(st, en, mid, r, id * 2 + 1)) + laz[id];
}

void add(int val, int mn, int mx){
	if(mx < mn) return;
	seg_add(val, mn, mx);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	all.PB(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i], all.PB(a[i]);
	cin >> q;
	for(int i = 0; i < q; i++){
		cin >> type[i] >> q1[i];
		if(type[i] == '!') cin >> q2[i], all.PB(q2[i]);
		else if(type[i] == '~') all.PB(q1[i]);
	}
	sort(all(all));
	all.resize(unique(all(all)) - all.begin());
	for(int i = 0; i <= n + 1; i++)
		a[i] = lower_bound(all(all), a[i]) - all.begin();
	n++;
	for(int i = 1; i <= n; i++)
		add(1, a[i - 1], a[i]);
	for(int i = 0; i < q; i++){
		char ty = type[i];
		int fi = q1[i], se = q2[i];
		if(ty == '!'){
			add(-1, a[fi-1], a[fi]);
			add(-1, a[fi], a[fi+1]);
			a[fi] = lower_bound(all(all), se) - all.begin();
			add(+1, a[fi-1], a[fi]);
			add(+1, a[fi], a[fi+1]);
			cout << seg[1] << '\n';
		}
		else if(ty == '~'){
			int id = upper_bound(all(all), fi) - all.begin() - 1;
			cout << get(id, id + 1) << '\n';
		}
		else{
			if(seg[1] < fi) cout << -1 << '\n';
			else{
				int lo = -1,
					hi = sz(all);
				while(hi - lo > 1){
					int mid = (lo + hi) >> 1;
					if(get(0, mid + 1) < fi)
						lo = mid;
					else
						hi = mid;
				}
				cout << all[hi] << '\n';
			}
		}
	}
	return 0;
}
