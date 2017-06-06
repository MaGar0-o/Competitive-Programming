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

const int maxn = 1e5 + 1,
	  maxe = maxn * 2;
int seg[maxe * 4],
	laz[maxe * 4],
	x[maxn],
	xx[maxn],
	y[maxn],
	yy[maxn];
vector<int> xall, yall;
vector<pii> eve[2][maxn];
int w, h, xlen, ylen, n;

void inc(int val, int st, int en, int l = 0, int r = sz(yall) - 1, int id = 1) {
	if (st >= r or en <= l)
		return;
	if (st <= l and r <= en) {
		seg[id] += val;
		laz[id] += val;
		return;
	}
	int mid = (l + r) >> 1;
	inc(val, st, en, l, mid, id<<1|0);
	inc(val, st, en, mid, r, id<<1|1);
	seg[id] = min(seg[id<<1|0], seg[id<<1|1]) + laz[id];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> w >> h
		>> xlen >> ylen
		>> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> xx[i] >> yy[i];
		if (x[i] > xx[i])
			swap(x[i], xx[i]);
		if (y[i] > yy[i])
			swap(y[i], yy[i]);
		x[i] -= xlen - 1;
		smax(x[i], 0);
		y[i] -= ylen - 1;
		smax(y[i], 0);
		xall.PB(x[i]);
		xall.PB(xx[i]);
		yall.PB(y[i]);
		yall.PB(yy[i]);
	}
	xall.PB(0);
	xall.PB(w);
	yall.PB(0);
	yall.PB(h);
	sort(all(xall));
	sort(all(yall));
	xall.resize(unique(all(xall)) - xall.begin());
	yall.resize(unique(all(yall)) - yall.begin());
	for (int i = 0; i < n; i++) {
		int xid = lower_bound(all(xall), x[i]) - xall.begin();
		eve[0][xid].PB({y[i], yy[i]});
		xid = lower_bound(all(xall), xx[i]) - xall.begin();
		eve[1][xid].PB({y[i], yy[i]});
	}
	for (int i = 0; i < sz(xall) - 1; i++) {
		for (auto quer : eve[0][i]) {
			int yst = lower_bound(all(yall), quer.L) - yall.begin(),
				yen = lower_bound(all(yall), quer.R) - yall.begin();
			inc(+1, yst, yen);
		}
		for (auto quer : eve[1][i]) {
			int yst = lower_bound(all(yall), quer.L) - yall.begin(),
				yen = lower_bound(all(yall), quer.R) - yall.begin();
			inc(-1, yst, yen);
		}
		if (seg[1] == 0)
			return cout << "yes" << endl, 0;
	}
	cout << "no" << endl;
	return 0;
}
