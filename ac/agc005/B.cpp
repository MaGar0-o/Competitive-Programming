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
int mst[maxl][maxn],
	stp[maxn],
	a[maxn],
	n;
LL ans;
queue<pii> q;

int merge(int i, int j){
	return min(MP(a[i], i), MP(a[j], j)).R;
}

int get(int l, int r){
	int f = stp[r - l + 1];
	return merge(mst[f][l], mst[f][r - (1 << f) + 1]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	iota(mst[0], mst[0] + n, 0);
	stp[0] = -1;
	for(int i = 1; i < maxn; i++)
		stp[i] = stp[i >> 1] + 1;
	for(int i = 1; i < maxl; i++)
		for(int j = 0; j + (1 << i) <= maxn; j++)
			mst[i][j] = merge(mst[i - 1][j], mst[i - 1][j + (1 << (i - 1))]);
	q.push({0, n - 1});
	while(sz(q)){
		pii seg = q.front();
		q.pop();
		if(seg.L > seg.R) continue;
		int id = get(seg.L, seg.R);
		ans += 1LL * (id - seg.L + 1) * (seg.R - id + 1) * a[id];
		q.push({seg.L, id - 1});
		q.push({id + 1, seg.R});
	}
	cout << ans << '\n';
	return 0;
}
