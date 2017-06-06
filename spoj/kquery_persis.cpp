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

const int maxn = 2e5 + 10,
	  maxl = 25;
int seg[maxn * maxl],
	L[maxn * maxl],
	R[maxn * maxl],
	root[maxn],
	n, q, sz = 1;
pii a[maxn];

int inc(int idx, int id, int l = 0, int r = n){
	if(idx < l or idx >= r) return id;
	int nid = sz++;
	seg[nid] = seg[id] + 1;
	if(r - l == 1)
		return nid;
	int mid = (l + r) >> 1;
	L[nid] = inc(idx, L[id], l, mid);
	R[nid] = inc(idx, R[id], mid, r);
	return nid;
}

int get(int st, int en, int id, int l = 0, int r = n){
	if(st >= r or en <= l) return 0;
	if(st <= l and r <= en) return seg[id];
	int mid = (l + r) >> 1;
	return get(st, en, L[id], l, mid)
		+ get(st, en, R[id], mid, r);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i].L;
		a[i].R = i;
	}
	sort(a, a + n);
	for(int i = n - 1; i >= 0; i--)
		root[i] = inc(a[i].R, root[i + 1]);
	cin >> q;
	while(q--){
		int fi, se, th;
		cin >> fi >> se >> th;
		int id = lower_bound(a, a + n, MP(th + 1, -1)) - a;
		//cout << id << ' ' << a[id].L << ' ' << a[id].R << ": ";
		cout << get(fi - 1, se, root[id]) << '\n';
	}
	return 0;
}
