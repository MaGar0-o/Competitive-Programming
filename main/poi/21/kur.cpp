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
#define count CNT
#define merge MRG

const int maxn = 500000 + 1;
pii seg[maxn * 4];
vector<int> vec[maxn];
int a[maxn];
int n, q;

pii merge(pii x, pii y){
	if(x.L == y.L){
		x.R += y.R;
		return x;
	}
	if(x.R < y.R)
		swap(x, y);
	x.R -= y.R;
	return x;
}

void build(int l = 0, int r = n, int id = 1){
	if(r - l == 1){
		seg[id] = MP(a[l], 1);
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, id * 2 + 0);
	build(mid, r, id * 2 + 1);
	seg[id] = merge(seg[id * 2 + 0], seg[id * 2 + 1]);
	return;
}

pii get(int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return MP(0, 0);
	if(st <= l and r <= en)
		return seg[id];
	int mid = (l + r) >> 1;
	return merge(get(st, en, l, mid, id * 2 + 0), get(st, en, mid, r, id * 2 + 1));
}

int count(int val, int l, int r){
	return lower_bound(all(vec[val]), r) - lower_bound(all(vec[val]), l);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 0; i < n; i++)
		cin >> a[i], vec[a[i]].PB(i);
	build();
	while(q--){
		int fi, se;
		cin >> fi >> se, fi--;
		pii ret = get(fi, se);
		if(ret.R and count(ret.L, fi, se) > (se - fi) / 2)
			cout << ret.L << '\n';
		else
			cout << 0 << '\n';
	}
	return 0;
}
