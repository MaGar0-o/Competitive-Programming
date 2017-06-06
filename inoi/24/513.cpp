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

const int maxn = 5e5 + 85 - 69;
vector<LL> all[2];
LL seg[2][maxn * 4],
   pos[maxn];
char ty[maxn];
bool laz[2][maxn * 4];
LL q, w, h;

void push(int, int, int, int);

void flip(int segid, int st, int en, int l, int r, int id = 1){
	if(st >= r or en <= l)
		return;
	if(st <= l and r <= en){
		seg[segid][id] = all[segid][r] - all[segid][l] - seg[segid][id];
		laz[segid][id] = !laz[segid][id];
		return;
	}
	if(laz[segid][id]) push(segid, l, r, id);
	int mid = (l + r) >> 1;
	flip(segid, st, en, l, mid, id * 2 + 0);
	flip(segid, st, en, mid, r, id * 2 + 1);
	seg[segid][id] = seg[segid][id * 2 + 0] + seg[segid][id * 2 + 1];
	return;
}

void push(int segid, int l, int r, int id){
	int mid = (l + r) >> 1;
	flip(segid, l, mid, l, mid, id * 2 + 0);
	flip(segid, mid, r, mid, r, id * 2 + 1);
	laz[segid][id] = false;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> w >> h >> q;
	all[0].PB(0);
	all[0].PB(w);
	all[1].PB(0);
	all[1].PB(h);
	for(int i = 0; i < q; i++){
		cin >> ty[i] >> pos[i];
		all[ty[i] == 'H'].PB(pos[i]);
	}
	sort(all(all[0]));
	sort(all(all[1]));
	all[0].resize(unique(all(all[0])) - all[0].begin());
	all[1].resize(unique(all(all[1])) - all[1].begin());
	for(int i = 0; i < q; i++){
		pos[i] = lower_bound(all(all[ty[i] == 'H']), pos[i]) - all[ty[i] == 'H'].begin();
		flip((ty[i] == 'H' ? 1 : 0), pos[i], sz(all[ty[i] == 'H']) - 1, 0, sz(all[ty[i] == 'H']) - 1);
		LL h1 = seg[1][1],
		   h2 = h - seg[1][1],
		   w1 = seg[0][1],
		   w2 = w - seg[0][1];
		cout << max(h1 * w2 + h2 * w1, h1 * w1 + h2 * w2) << '\n';
	}
	return 0;
}
