//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int seg[maxn * 4], n, q;

void inc(int idx, int val, int l = 0, int r = n, int id = 1){
	if(idx >= r or idx < l) return;
	if(r - l <= 1){
		seg[id] += val;
		return;
	}
	int mid = (l + r) >> 1;
	inc(idx, val, l, mid, id<<1|0);
	inc(idx, val, mid, r, id<<1|1);
	seg[id] = seg[id<<1|0] + seg[id<<1|1];
}

int get(int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l) return 0;
	if(st <= l and r <= en) return seg[id];
	int mid = (l + r) >> 1;
	return get(st, en, l, mid, id<<1|0)
		+ get(st, en, mid, r, id<<1|1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	while(q--){
		int ty, fi, se;
		cin >> ty >> fi >> se;
		if(ty == 1)	//adding se to a[fi] (fi is 1-base)
			inc(fi - 1, se);
		else
			cout << get(fi - 1, se) << '\n';
	}
	return 0;
}
