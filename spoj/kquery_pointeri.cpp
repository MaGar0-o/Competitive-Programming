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

const int maxn = 3e4 + 10;
vector<pair<pii, pii> > quer;
int ord[maxn],
	a[maxn],
	ans[maxn * 10],
	n, q, sz = 1;

struct node{
	int chL,
		chR,
		val;
	node(){
		chL = chR = -1;
		val = 0;
	}
	int l(void){
		return chL == -1 ? chL = sz++ : chL;
	}
	int r(void){
		return chR == -1 ? chR = sz++ : chR;
	}
} seg[maxn * 4];

void inc(int idx, int l = 0, int r = n, int id = 0){
	if(r - l == 1){
		seg[id].val++;
		return;
	}
	int mid = (l + r) >> 1;
	if(idx < mid) inc(idx, l, mid, seg[id].l());
	else inc(idx, mid, r, seg[id].r());
	seg[id].val++;
}

int get(int st, int en, int l = 0, int r = n, int id = 0){
	if(st >= r or en <= l or id == -1) return 0;
	if(st <= l and r <= en) return seg[id].val;
	int mid = (l + r) >> 1;
	return get(st, en, l, mid, seg[id].chL)
		+ get(st, en, mid, r, seg[id].chR);
}

bool cmp(int i, int j){
	return a[i] > a[j];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i], ord[i] = i;
	cin >> q;
	for(int i = 0; i < q; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		quer.PB(MP(MP(th, i), MP(fi - 1, se)));
	}
	sort(all(quer), greater<pair<pii, pii> >());
	sort(ord, ord + n, cmp);
	int ptr = 0;
	for(auto qu : quer){
		while(ptr < n and a[ord[ptr]] > qu.L.L){
			inc(ord[ptr]);
			ptr++;
		}
		ans[qu.L.R] = get(qu.R.L, qu.R.R);
	}
	for(int i = 0; i < q; i++)
		cout << ans[i] << '\n';
	return 0;
}
