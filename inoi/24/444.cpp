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

const int maxn = 2e5 + 85 - 69;
const LL Mod = 1000 * 1000 * 1000 + 7;
LL seg[maxn * 4],
   laz1[maxn * 4],
   laz2[maxn * 4];
int n, q;

void push(int, int, int);
void add1(LL, int, int, int, int, int);
void add2(LL, int, int, int);

void add1(LL val, int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return;
	if(st <= l and r <= en){
		laz1[id] = (laz1[id] + val) % Mod;
		seg[id] = (seg[id] + (val * ((1LL * (r - l) * (r - l + 1) / 2) % Mod))) % Mod;
		add2(val * (l - st), l, r, id);
		return;
	}
	push(l, r, id);
	int mid = (l + r) >> 1;
	add1(val, st, en, l, mid, id * 2 + 0);
	add1(val, st, en, mid, r, id * 2 + 1);
	seg[id] = (seg[id * 2 + 0] + seg[id * 2 + 1]) % Mod;
	return;
}

void add2(LL val, int l = 0, int r = n, int id = 1){
	laz2[id] = (laz2[id] + val) % Mod;
	seg[id] = (seg[id] + val * (r - l)) % Mod;
	return;
}

LL get(int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return 0;
	if(st <= l and r <= en)
		return seg[id];
	push(l, r, id);
	int mid = (l + r) >> 1;
	return (get(st, en, l, mid, id * 2 + 0) + get(st, en, mid, r, id * 2 + 1)) % Mod;
}

void push(int l, int r, int id){
	int mid = (l + r) >> 1;
	add1(laz1[id], l, r, l, mid, id * 2 + 0);
	add1(laz1[id], l, r, mid, r, id * 2 + 1);
	add2(laz2[id], l, mid, id * 2 + 0);
	add2(laz2[id], mid, r, id * 2 + 1);
	laz1[id] = laz2[id] = 0;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		add1(x, i, i + 1);
	}
	for(int i = 0; i < q; i++){
		string ty;
		int fi, se;
		cin >> ty >> fi >> se, fi--;
		if(ty == "ask")
			cout << get(fi, se)  << '\n';
		else
			add1(1, fi, se);
	}
	return 0;
}
