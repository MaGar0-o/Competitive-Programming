//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<LL, LL> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((LL)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const LL maxn = 1e6 + 10;
LL par[maxn];
LL x[maxn],
	xx[maxn],
	y[maxn],
	yy[maxn],
	n, m, q;

LL root(LL u){
	return par[u] < 0 ? u : par[u] = root(par[u]);
}

void merge(LL u, LL v){
	if((u = root(u)) == (v = root(v))) return;
	if(par[u] > par[v]) swap(u, v);
	par[u] += par[v];
	par[v] = u;
	return;
}

LL get(LL l1, LL r1, LL l2, LL r2){
	if(l1 > l2)
		swap(l1, l2), swap(r1, r2);
	if(l2-1 == r1) return 1;
	if(l2 > r1) return 0;
	return 2;
}

bool touch(LL i, LL j){
	LL stat1 = get(x[i], xx[i], x[j], xx[j]),
		stat2 = get(y[i], yy[i], y[j], yy[j]);
	return stat1 + stat2 > 2;
}

bool isin(LL i, LL j){
	return x[j] <= x[i] and xx[i] <= xx[j]
		and y[j] <= y[i] and yy[i] <= yy[j];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(par, -1, sizeof par);
	cin >> n >> m >> q;
	x[q] = xx[q] = y[q] = yy[q] = 1;
	x[q+1] = xx[q+1] = n, y[q+1] = yy[q+1] = m;
	LL as1 = -1, as2 = -1;
	for(LL i = 0; i < q; i++){
		cin >> x[i] >> y[i] >> xx[i] >> yy[i];
		if(isin(q, i)) as1 = i;
		if(isin(q + 1, i)) as2 = i;
		for(LL j = 0; j < i; j++)
			if(touch(i, j)) merge(i, j);
		if(~as1 and ~as2 and root(as1) == root(as2))
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}
