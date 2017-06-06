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

const int maxn = 2e5 + 85 - 69,
	  maxl = 20;
int a[maxn],
	pp[maxn],
	lcnt[maxn],
	ans[maxn],
	n, m;
pii spt[maxl][maxn];
string str;

pii MX(pii le, pii ri){
	if(a[le.L] == a[ri.R])
		return MP(le.L, ri.R);
	if(a[le.L] > a[ri.R])
		return le;
	return ri;
}

pii get(int l, int r){
	int f = pp[r - l + 1];
	return MX(spt[f][l], spt[f][r - (1 << f) + 1]);
}

void solveL(int r, int mx){
	if(r < 0)
		return;
	int le = get(0, r).L;
	ans[le] = min(mx, a[le] + m - lcnt[m]);
	for(int i = le; i <= r; ++i)
		if(a[i] + m >= ans[le])
			ans[i] = ans[le];
		else
			ans[i] = a[i] + m;
	solveL(le - 1, mx);
	return;
}

void solveR(int l, int mx){
	if(l >= n)
		return;
	int ri = get(l, n - 1).R;
	ans[ri] = min(mx, a[ri] + lcnt[m]);
	for(int i = ri; i >= l; --i)
		if(a[i] + m >= ans[ri])
			ans[i] = ans[ri];
		else
			ans[i] = a[i] + m;
	solveR(ri + 1, mx);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	pp[0] = -1;
	for(int i = 1; i < maxn; i++)
		pp[i] = pp[i>>1] + 1;

	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> a[i], spt[0][i] = MP(i, i);
	cin >> str;

	for(int i = 0; i < m; i++)
		lcnt[i + 1] = lcnt[i] + (str[i] == 'L');

	for(int i = 1; i < maxl; i++)
		for(int j = 0; j + (1 << i) <= n; j++)
			spt[i][j] = MX(spt[i - 1][j], spt[i - 1][j + (1 << (i - 1))]);

	pii mx = get(0, n - 1);
	solveL(mx.L - 1, a[mx.L]);
	solveR(mx.R + 1, a[mx.L]);

	for(int i = mx.L; i <= mx.R; i++)
		ans[i] = min(a[mx.L], a[i] + m);

	for(int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}
