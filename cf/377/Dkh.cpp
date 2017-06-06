//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

const int maxn = 1e5 + 10,
	  maxv = 300 * 1000;
int fen[2][maxv + 10];
ordered_set<pii> seg[maxv * 4];
int ord[maxn],
	le[maxn],
	mi[maxn],
	ri[maxn],
	n, sz = 0;

void osadd(int idx, int val, int l = 0, int r = maxv, int id = 1){
	if(idx < l or idx >= r) return;
	seg[id].insert(MP(val, sz++));
	if(r - l == 1) return;
	int mid = (l + r) >> 1;
	osadd(idx, val, l, mid, id<<1|0);
	osadd(idx, val, mid, r, id<<1|1);
}

int osget(int st, int en, int l = 0, int r = maxv, int id = 1){
	if(st >= r or en <= l) return 0;
	if(st <= l and r <= en)
		return sz(seg[id]) - seg[id].order_of_key(MP(en - 1, -1));
	int mid = (l + r) >> 1;
	return osget(st, en, l, mid, id<<1|0)
		+ osget(st, en, mid, r, id<<1|1);
}

void add(int fid, int idx){
	idx++;
	while(idx < maxv + 10){
		fen[fid][idx]++;
		idx += idx & -idx;
	}
}

int get(int fid, int idx){
	int ret = 0;
	for(;idx;idx-=idx&-idx)
		ret += fen[fid][idx];
	return ret;
}

int get(int fid, int st, int en){
	return get(fid, en) - get(fid, st);
}

bool cmp(int i, int j){
	return le[i] < le[j];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> le[i] >> mi[i] >> ri[i], le[i]--, mi[i]--, ri[i]--;
	iota(ord, ord + n, 0);
	sort(ord, ord + n, cmp);
	int	ptr = 0,
		ans = 0,
		lans = -1,
		rans = -1;
	for(int lpos = 0; lpos < maxv; lpos++){
		while(ptr < n and le[ord[ptr]] <= lpos){
			add(0, ri[ord[ptr]]);
			add(1, mi[ord[ptr]]);
			osadd(mi[ord[ptr]], ri[ord[ptr]]);
			ptr++;
		}
		int lo = lpos - 1,
			hi = maxv;
		while(hi - lo > 1){
			int mid = (lo + hi) >> 1;
			int val[] = {get(0, mid, maxv + 2), get(1, lpos, mid + 1)};
			if(val[0] >= val[1])
				lo = mid;
			else
				hi = mid;
		}
		int val = osget(lpos, hi);
		if(val > ans){
			ans = val;
			lans = lpos;
			rans = lo;
			//cout << lans+1 << ' ' << rans+1 << ' ' << get(0, hi, maxv + 2) << ' ' << get(1, lpos, hi + 1) << endl;
		}
	}
	cout << ans << '\n';
	for(int i = 0; i < n; i++)
		if(le[i] <= lans and ri[i] >= rans and mi[i] >= lans and mi[i] <= rans)
			cout << i + 1 << ' ';
	cout << '\n';
	return 0;
}
