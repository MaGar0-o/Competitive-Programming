//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<pii, pii> piiii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()
#define Inf 1e9 + 10

const int maxn = 5e5 + 10,
	  maxl = 21;
//const LL Mod = 1e9 + 7;
int A, B, C;
int seg[maxl][maxn],
	fen[maxl][maxn];
piiii p[maxn],
	  q[maxn];
int ord[maxn],
	qord[maxn],
	hajm[maxn];
int n;

int gethaj(piiii &po){
	int ret = (po.L.L * po.L.R) ;//% Mod;
	ret = (ret * po.R.L) ;//% Mod;
	return ret;
}

int gethaj(piiii po1, piiii po2){
	po2.L.L -= po1.L.L;
	po2.L.R -= po1.L.R;
	po2.R.L -= po1.R.L;
	return gethaj(po2);
}

void build(int l = 0, int r = n, int h = 0){
	if(r - l == 1){
		seg[h][l] = p[l].L.R;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, h + 1);
	build(mid, r, h + 1);
	merge(seg[h+1] + l, seg[h+1] + mid,
			seg[h+1] + mid, seg[h+1] + r,
			seg[h] + l);
	int id = unique(seg[h] + l, seg[h] + r) - seg[h];
	fill(seg[h] + id, seg[h] + r, Inf);
	return;
}

void feninc(int h, int idx, int val){
	for(idx++; idx < maxn; idx += idx & -idx)
		fen[h][idx] = (fen[h][idx] + val) ;//% Mod;
}

void inc(int val, int idx, int l = 0, int r = n, int h = 0){
	if(idx < l or idx >= r) return;
	int id = lower_bound(seg[h] + l, seg[h] + r, p[idx].L.R) - seg[h];
	feninc(h, id, val);
	if(r - l == 1)
		return;
	int mid = (l + r) >> 1;
	inc(val, idx, l, mid, h + 1);
	inc(val, idx, mid, r, h + 1);
}

int fenget(int h, int idx){
	int ret = 0;
	for(; idx > 0; idx -= idx & -idx)
		ret = (ret + fen[h][idx]) ;//% Mod;
	return ret;
}

int fenget(int h, int l, int r){
	return (fenget(h, r) - fenget(h, l)) ;//% Mod + Mod) % Mod;
}

int get(int qid, int l = 0, int r = n, int h = 0){
	if(p[l].L.L >= q[qid].L.L) return 0;
	if(p[r - 1].L.L < q[qid].L.L){
		int id = lower_bound(seg[h] + l, seg[h] + r, q[qid].L.R) - seg[h];
		return fenget(h, l, id);
	}
	int mid = (l + r) >> 1;
	return (get(qid, l, mid, h + 1) + get(qid, mid, r, h + 1)) ;//% Mod;
}

bool cmp(int i, int j){
	return p[i].R.L < p[j].R.L;
}

bool qcmp(int i, int j){
	return q[i].R.L < q[j].R.L;
}

int main(){
	scanf("%d%d%d%d", &n, &A, &B, &C);
	for(int i = 0; i < n; i++){
		scanf("%d%d%d", &p[i].L.L, &p[i].L.R, &p[i].R.L);
		p[i].R.R = i;
		scanf("%d%d%d", &q[i].L.L, &q[i].L.R, &q[i].R.L);
		hajm[i] = gethaj(p[i], q[i]);
	}
	sort(p, p + n);
	build();
	iota(ord, ord + n, 0);
	iota(qord, qord + n, 0);
	sort(ord, ord + n, cmp);
	sort(qord, qord + n, qcmp);
	int ptr = 0,
		ans = 0;
	for(int i = 0; i < n; i++){
		int id = ord[i];
		while(ptr < n and q[qord[ptr]].R.L <= p[id].R.L){
			int qid = qord[ptr++];
			int haj = get(qid);
			if(haj == gethaj(q[qid]))
				ans++;
		}
		inc(hajm[p[id].R.R], id);
	}
	while(ptr < n){
		int qid = qord[ptr++];
		int haj = get(qid);
		if(haj == gethaj(q[qid]))
			ans++;
	}
	cout << ans << '\n';
	return 0;
}
