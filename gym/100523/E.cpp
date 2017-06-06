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

const int maxn = 5e5 + 85 - 69;
int pos[maxn],
	segmin[maxn * 4],
	segcnt[maxn * 4],
	laz[maxn * 4],
	n, m, d, l;

void build(int l = 0, int r = n, int id = 1){
	segcnt[id] = r - l;
	if(r - l == 1)
		return;
	int mid = (l + r) >> 1;
	build(l, mid, id<<1|0);
	build(mid, r, id<<1|1);
	return;
}

void inc(int val, int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return;
	if(st <= l and r <= en){
		laz[id] += val;
		segmin[id] += val;
		return;
	}
	int mid = (l + r) >> 1;
	inc(val, st, en, l, mid, id<<1|0);
	inc(val, st, en, mid, r, id<<1|1);
	segmin[id] = min(segmin[id<<1|0], segmin[id<<1|1]) + laz[id];
	segcnt[id] = 0;
	if(segmin[id<<1|0] <= segmin[id<<1|1]) segcnt[id] += segcnt[id<<1|0];
	if(segmin[id<<1|0] >= segmin[id<<1|1]) segcnt[id] += segcnt[id<<1|1];
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> d >> l;
	build();
	for(int i = 1; i < n; i++)
		cin >> pos[i];
	for(int i = 0; i < m; i++){
		int x;
		cin >> x;
		int idl = lower_bound(pos, pos + n, x - l) - pos,
			idr = upper_bound(pos, pos + n, x + l) - pos;
		inc(+1, idl, idr);
	}
	if(segmin[1] == 0)
		cout << n - segcnt[1] << '\n';
	else
		cout << n << '\n';
	while(d--){
		int fi, se;
		cin >> fi >> se;
		int idl = lower_bound(pos, pos + n, fi - l) - pos,
			idr = upper_bound(pos, pos + n, fi + l) - pos;
		inc(-1, idl, idr);
		idl = lower_bound(pos, pos + n, se - l) - pos,
			idr = upper_bound(pos, pos + n, se + l) - pos;
		inc(+1, idl, idr);
		if(segmin[1] == 0)
			cout << n - segcnt[1] << '\n';
		else
			cout << n << '\n';
	}
	return 0;
}
