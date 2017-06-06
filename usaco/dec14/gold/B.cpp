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

const int maxn = 1e5 + 85 - 69;
int seg1[maxn * 4],
	seg2[maxn * 4];
int x[maxn],
	y[maxn];
int n, q;

int dist(int i, int j){
	return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

void modify1(int idx, int val, int l = 0, int r = n, int id = 1){
	if(idx < l or idx >= r)
		return;
	if(r - l == 1){
		seg1[id] = val;
		return;
	}
	int mid = (l + r) >> 1;
	modify1(idx, val, l, mid, id * 2 + 0);
	modify1(idx, val, mid, r, id * 2 + 1);
	seg1[id] = seg1[id * 2 + 0] + seg1[id * 2 + 1];
	return;
}

void modify2(int idx, int val, int l = 0, int r = n, int id = 1){
	if(idx < l or idx >= r)
		return;
	if(r - l == 1){
		seg2[id] = val;
		return;
	}
	int mid = (l + r) >> 1;
	modify2(idx, val, l, mid, id * 2 + 0);
	modify2(idx, val, mid, r, id * 2 + 1);
	seg2[id] = max(seg2[id * 2 + 0], seg2[id * 2 + 1]);
	return;
}

int get1(int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return 0;
	if(st <= l and r <= en)
		return seg1[id];
	int mid = (l + r) >> 1;
	return get1(st, en, l, mid, id * 2 + 0)
		+ get1(st, en, mid, r, id * 2 + 1);
}

int get2(int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return 0;
	if(st <= l and r <= en)
		return seg2[id];
	int mid = (l + r) >> 1;
	return max(get2(st, en, l, mid, id * 2 + 0),
			get2(st, en, mid, r, id * 2 + 1));
}

int main(){
	ifstream cin("marathon.in");
	ofstream cout("marathon.out");
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
		if(i) modify1(i - 1, dist(i - 1, i));
	}
	for(int i = 1; i + 1 < n; i++)
		modify2(i, dist(i - 1, i) + dist(i, i + 1) - dist(i - 1, i + 1));
	for(int i = 0; i < q; i++){
		char ty;
		int fi, se, th;
		cin >> ty >> fi >> se;
		if(ty == 'Q')
			cout << get1(fi - 1, se - 1) - max(0, get2(fi, se - 1)) << '\n';
		else{
			cin >> th;
			fi--;
			x[fi] = se, y[fi] = th;
			if(fi) modify1(fi - 1, dist(fi - 1, fi));
			if(fi + 1 < n) modify1(fi, dist(fi, fi + 1));
			if(fi + 2 < n) modify2(fi + 1, dist(fi, fi + 1) + dist(fi + 1, fi + 2) - dist(fi, fi + 2));
			if(fi and fi + 1 < n) modify2(fi, dist(fi - 1, fi) + dist(fi, fi + 1) - dist(fi - 1, fi + 1));
			if(fi - 1 > 0) modify2(fi - 1, dist(fi - 2, fi - 1) + dist(fi - 1, fi) - dist(fi - 2, fi));
		}
	}
	return 0;
}
