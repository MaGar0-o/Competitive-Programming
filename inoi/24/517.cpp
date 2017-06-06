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
   laz[maxn * 4],
   P[maxn];
pii a[maxn];
vector<int> vec[maxn];
int n, len;

void push(int);

void add(int idx, LL val, int l = 0, int r = len + 1, int id = 1){
	if(idx >= r or idx < l)
		return;
	if(r - l == 1){
		seg[id] = val;
		return;
	}
	if(laz[id] > 1) push(id);
	int mid = (l + r) >> 1;
	add(idx, val, l, mid, id * 2 + 0);
	add(idx, val, mid, r, id * 2 + 1);
	seg[id] = (seg[id * 2 + 0] + seg[id * 2 + 1]) % Mod;
	return;
}

void mul(LL val, int st, int en, int l = 0, int r = len + 1, int id = 1){
	if(st >= r or en <= l)
		return;
	if(st <= l and r <= en){
		seg[id] = (seg[id] * val) % Mod;
		laz[id] = (laz[id] * val) % Mod;
		return;
	}
	if(laz[id] > 1) push(id);
	int mid = (l + r) >> 1;
	mul(val, st, en, l, mid, id * 2 + 0);
	mul(val, st, en, mid, r, id * 2 + 1);
	seg[id] = (seg[id * 2 + 0] + seg[id * 2 + 1]) % Mod;
	return;
}

LL get(int st, int en, int l = 0, int r = len + 1, int id = 1){
	if(st >= r or en <= l)
		return 0;
	if(st <= l and r <= en)
		return seg[id];
	if(laz[id] > 1) push(id);
	int mid = (l + r) >> 1;
	return (get(st, en, l, mid, id * 2 + 0) + get(st, en, mid, r, id * 2 + 1)) % Mod;
}

void push(int id){
	mul(laz[id], 0, 1, 0, 1, id * 2 + 0);
	mul(laz[id], 0, 1, 0, 1, id * 2 + 1);
	laz[id] = 1;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	fill(laz, laz + maxn * 4, +1);
	P[0] = 1;
	for(int i = 1; i < maxn; i++)
		P[i] = (P[i - 1] * 2) % Mod;
	cin >> n >> len;
	add(len, 1);
	for(int i = 0; i < n; i++)
		cin >> a[i].L >> a[i].R;
	sort(a, a + n);
	for(int i = 0; i < n; i++)
		vec[a[i].L].PB(a[i].R);
	for(int i = len - 1; i >= 0; i--){
		LL val = 0;
		for(int j = sz(vec[i]) - 1; j >= 0; j--)
			val = (val + P[j] * get(i, vec[i][j] + 1)) % Mod;
		add(i, val);
		for(auto nd : vec[i])
			mul(2, nd + 1, len + 1);
	}
	cout << get(0, 1) << '\n';
	return 0;
}
