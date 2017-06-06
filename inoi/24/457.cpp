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
set<pii> seg[maxn * 4];
int n, q;

void add(int tim, int col, int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return;
	if(st <= l and r <= en){
		seg[id].insert(MP(tim, col));
		return;
	}
	int mid = (l + r) >> 1;
	add(tim, col, st, en, l, mid, id * 2 + 0);
	add(tim, col, st, en, mid, r, id * 2 + 1);
	return;
}

pii get(int idx, int tim, int l = 0, int r = n, int id = 1){
	if(idx < l or idx >= r)
		return MP(0, 0);
	auto it = seg[id].lower_bound(MP(tim, -1));
	pii curans;
	if(it == seg[id].begin())
		curans = MP(0, 0);
	else{
		it--;
		curans = *it;
	}
	if(r - l == 1)
		return curans;
	int mid = (l + r) >> 1;
	return max(curans, max(get(idx, tim, l, mid, id * 2 + 0),
			get(idx, tim, mid, r, id * 2 + 1)));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 0; i < q; i++){
		char ty;
		cin >> ty;
		if(ty == '?'){
			int fi, se;
			cin >> fi >> se;
			cout << get(se - 1, fi).R << '\n';
		}
		else{
			int t, l, r, c;
			cin >> t >> l >> r >> c;
			add(t, c, l - 1, r);
		}
	}
	return 0;
}
