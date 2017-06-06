//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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
LL s[maxn],
   a[maxn],
   b[maxn],
   f[maxn],
   t[maxn];
int stc[maxn],
	n, m, sz;

LD inters(int i, int j){
	return LD(b[i] - b[j]) / LD(a[j] - a[i]);
}

LD get(LD pos){
	int lo = 0, hi = sz;
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if(pos < inters(stc[mid - 1], stc[mid]))
			hi = mid;
		else
			lo = mid;
	}
	return a[stc[lo]] * pos + b[stc[lo]];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> t[i];
		s[i + 1] = t[i] + s[i];
	}
	for(int j = 0; j < m; j++)
		cin >> f[j];
	for(int i = 0; i < n; i++){
		a[i] = +s[i + 1];
		b[i] = -s[i];
		while(sz >= 2 and inters(stc[sz - 1], stc[sz - 2]) >= inters(stc[sz - 1], i))
			sz--;
		stc[sz++] = i;
	}
	LL dis = 0;
	for(int i = 1; i < m; i++){
		LD x = LD(f[i - 1]) / LD(f[i]);
		LD val = get(x);
		dis += (val * f[i]) + .5;
	}
	cout << dis + s[n] * f[m - 1] << '\n';
	return 0;
}
