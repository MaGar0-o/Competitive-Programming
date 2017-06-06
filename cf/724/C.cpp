//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<pair<bool, int>, pair<bool, LL> > pbibl;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 2e5 + 85 - 69;
bool arr1[maxn * 2],
	 arr2[maxn * 2];
bool *mark[2] = {arr1 + maxn, arr2 + maxn};
vector<int> vecarr[2][maxn * 2];
vector<int>* vec[2] = {vecarr[0] + maxn, vecarr[1] + maxn};
int a[maxn],
	b[maxn];
LL ans[maxn];
int n, m, k;

int stof(bool ty, int u, bool dir){
	if(ty == 0){
		if(dir == 0)
			return max(u, 0);
		if(u >= n - m) return n;
		return m + u;
	}
	if(dir == 0)
		return max(0, u - m);
	return min(n, u);
}

LL func(bool ty, int u, bool dir, int id){
	return abs(stof(ty, u, dir) - a[id]);
}

int leng(bool ty, int u){
	if(ty == 0) return min(min(n, m), max(n, m) - abs(u));
	if(u <= min(n, m)) return u;
	if(u > max(n, m)) return min(n, m) - (u - max(n, m));
	return min(n, m);
}

bool ghotr(bool ty, int u, bool dir){
	if(ty)
		return (dir and u == m) or (!dir and u == n);
	return (dir and u == 0) or (!dir and u == n - m);
}

pbibl nxt(bool ty, int u, bool dir, LL tim){
	pbibl ret;
	if(ghotr(ty, u, dir)){
		ret.L.R = -1;
		return ret;
	}
	ret.L.L = !ty;
	ret.R.L = ((dir == 0 and stof(ty, u, !dir) == n) or (dir == 1 and stof(ty, u, !dir) == 0)) ? !dir : dir;
	int x = stof(ty, u, !dir),
		y;
	if(ty){
		y = u - x;
		ret.L.R = x - y;
	}
	else{
		y = x - u;
		ret.L.R = x + y;
	}
	ret.R.R = tim + leng(ty, u);
	return ret;
}

void dfs(bool ty, int u, bool dir, LL tim){
	mark[ty][u] = true;
	for(auto id : vec[ty][u])
		smin(ans[id], func(ty, u, dir, id) + tim);
	auto v = nxt(ty, u, dir, tim);
	if(v.L.R == -1) return;
	if(!mark[v.L.L][v.L.R]) dfs(v.L.L, v.L.R, v.R.L, v.R.R);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(ans, 63, sizeof ans);
	cin >> n >> m >> k;
	for(int i = 0; i < k; i++){
		cin >> a[i] >> b[i];
		vec[0][a[i] - b[i]].PB(i);
		vec[1][a[i] + b[i]].PB(i);
	}
	dfs(0, 0, 0, 0);
	for(int i = 0; i < k; i++)
		cout << (ans[i] == ans[maxn - 1] ? -1 : ans[i]) << '\n';
	return 0;
}
