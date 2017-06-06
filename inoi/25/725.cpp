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

const int maxn = 3e5 + 85 - 69;
int n, q;

struct node{
	LL sum;
	LL min1, max1;
	LL min2, max2;
	int len;
} SEG[2][maxn * 4];

node merge(node lef, node rig){
	node ret;
	ret.len = lef.len + rig.len;
	if(lef.len & 1){
		ret.sum = lef.sum - rig.sum;
		ret.min1 = min(lef.min1, lef.sum + rig.min2);
		ret.max1 = max(lef.max1, lef.sum + rig.max2);
		ret.min2 = min(lef.min2, -lef.sum + rig.min1);
		ret.max2 = max(lef.max2, -lef.sum + rig.max1);
	}
	else{
		ret.sum = lef.sum + rig.sum;
		ret.min1 = min(lef.min1, lef.sum + rig.min1);
		ret.max1 = max(lef.max1, lef.sum + rig.max1);
		ret.min2 = min(lef.min2, -lef.sum + rig.min2);
		ret.max2 = max(lef.max2, -lef.sum + rig.max2);
	}
	return ret;
}

void modify(int segid, int idx, LL val, int l = 0, int r = n, int id = 1){
	if(idx >= r or idx < l)
		return;
	auto seg = SEG[segid];
	if(r - l == 1){
		seg[id].sum = seg[id].min1 = seg[id].max1 = val+val;
		seg[id].len = 1;
		return;
	}
	int mid = (l + r) >> 1;
	modify(segid, idx, val, l, mid, id * 2 + 0);
	modify(segid, idx, val, mid, r, id * 2 + 1);
	seg[id] = merge(seg[id * 2 + 0], seg[id * 2 + 1]);
	return;
}

node get(int segid, int st, int en, int l = 0, int r = n, int id = 1){
	//cout << "LOG: " << l << ' ' << r << endl;
	auto seg = SEG[segid];
	if(st <= l and r <= en)
		return seg[id];
	int mid = (l + r) >> 1;
	if(en <= mid)
		return get(segid, st, en, l, mid, id * 2 + 0);
	if(st >= mid)
		return get(segid, st, en, mid, r, id * 2 + 1);
	return merge(get(segid, st, en, l, mid, id * 2 + 0),
			get(segid, st, en, mid, r, id * 2 + 1));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		modify(0, i, fi);
		modify(1, i, se);
	}
	cin >> q;
	while(q--){
		int ty;
		cin >> ty;
		if(ty == 1){
			LL idx, fi, se;
			cin >> idx >> fi >> se;
			idx--;
			modify(0, idx, fi);
			modify(1, idx, se);
		}
		else{
			LL x, y, fi, se;
			cin >> x >> y >> fi >> se, fi--;
			auto anx = get(0, fi, se),
				 any = get(1, fi, se);
			cout << min(anx.min1 - x, anx.min2 + x) << ' '
				<< min(any.min1 - y, any.min2 + y) << ' '
				<< max(anx.max1 - x, anx.max2 + x) << ' '
				<< max(any.max1 - y, any.max2 + y) << '\n';
		}
	}
	return 0;
}
