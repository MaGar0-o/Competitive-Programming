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
	  maxl=20;
vector<int> fen[2][maxn * 4];
int seg[2][maxl][maxn],
	ord[maxn],
	dp[maxn],
	x[maxn],
	y[maxn],
	n, r, w, h;
pii p[2][maxn];

void build(int ty, int l = 0, int r = n, int h = 0, int id = 1){
	fen[ty][id].resize(r - l + 1);
	if(r - l == 1){
		seg[ty][h][l] = p[ty][l].R;
		return;
	}
	int mid = (l + r) >> 1;
	build(ty, l, mid, h + 1, id<<1|0);
	build(ty, mid, r, h + 1, id<<1|1);
	merge(seg[ty][h + 1] + l, seg[ty][h + 1] + mid,
			seg[ty][h + 1] + mid, seg[ty][h + 1] + r,
			seg[ty][h] + l);
	return;
}

void fenmod(int ty, int id, int idx, int val){
	for(idx++; idx < sz(fen[ty][id]); idx += idx & -idx)
		smax(fen[ty][id][idx], val);
	return;
}

void modify(int ty, int val, int qx, int qy, int l = 0, int r = n, int h = 0, int id = 1){
	fenmod(ty, id, lower_bound(seg[ty][h] + l, seg[ty][h] + r, qy) - seg[ty][h] - l, val);
	if(r - l == 1)
		return;
	int mid = (l + r) >> 1;
	if(MP(qx, qy) <= p[ty][mid - 1])
		return modify(ty, val, qx, qy, l, mid, h + 1, id<<1|0);
	return modify(ty, val, qx, qy, mid, r, h + 1, id<<1|1);
}

int fenget(int ty, int id, int idx){
	int ret = 0;
	for(; idx; idx -= idx & -idx)
		smax(ret, fen[ty][id][idx]);
	return ret;
}

int get(int ty, int qx, int qy, int l = 0, int r = n, int h = 0, int id = 1){
	if(p[ty][l].L > qx) return 0;
	if(p[ty][r - 1].L <= qx){
		int val = fenget(ty, id, upper_bound(seg[ty][h] + l, seg[ty][h] + r, qy) - seg[ty][h] - l);
		return val;
	}
	int mid = (l + r) >> 1;
	return max(get(ty, qx, qy, l, mid, h + 1, id<<1|0),
			get(ty, qx, qy, mid, r, h + 1, id<<1|1));
}

bool cmp(int i, int j){
	return y[i] < y[j];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> r >> w >> h;
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
		y[i] = -y[i];
		p[0][i] = MP(-x[i], y[i] + x[i] * r);
		p[1][i] = MP(+x[i], y[i] - x[i] * r);
	}
	iota(ord, ord + n, 0);
	sort(ord, ord + n, cmp);
	for(int i = 0; i < 2; i++){
		sort(p[i], p[i] + n);
		build(i);
	}
	for(int i = 0; i < n; i++){
		int id = ord[i];
		dp[id] = 1 + max(get(0, -x[id], y[id] + x[id] * r), get(1, x[id], y[id] - x[id] * r));
		modify(0, dp[id], -x[id], y[id] + x[id] * r);
		modify(1, dp[id], +x[id], y[id] - x[id] * r);
	}
	cout << *max_element(dp, dp + n) << '\n';
	return 0;
}
