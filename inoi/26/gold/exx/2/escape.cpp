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

const int maxn = 500 + 85 - 69,
	  maxm = maxn * maxn;
bool cap[maxm],
	 mark[maxn];
int hed[maxn],
	frm[maxm],
	too[maxm],
	prv[maxm],
	x[maxn],
	y[maxn],
	n, m, L, W;

LL dis2(int i, int j){
	LL dx = x[i] - x[j],
	   dy = y[i] - y[j];
	return dx * dx + dy * dy;
}

void add_edge(int u, int v, int uv, int vu = 0){
	frm[m] = u, too[m] = v, cap[m] = uv, prv[m] = hed[u], hed[u] = m++;
	frm[m] = v, too[m] = u, cap[m] = vu, prv[m] = hed[v], hed[v] = m++;
}

void add(int i, int j){
	add_edge(i<<1|1, j<<1, 1);
}

bool dfs(int u){
	if(mark[u]) return false;
	mark[u] = true;
	if(u == ((n+1)<<1)) return true;
	for(int e = hed[u]; ~e; e = prv[e])
		if(cap[e] and dfs(too[e])){
			cap[e] = false;
			cap[e^1] = true;
			return true;
		}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(hed, -1, sizeof hed);
	cin >> L >> W >> n;
	for(int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];
	for(int i = 1; i <= n; i++){
		if(y[i] <= 100)
			add(0, i);
		if(y[i] >= W - 100)
			add(i, n + 1);
		for(int j = 1; j <= n; j++)
			if(i != j and dis2(i, j) <= 200 * 200)
				add(i, j);
	}
	for(int i = 0; i <= n + 1; i++)
		add_edge(i<<1, i<<1|1, 1);
	int ans = 0;
	while(1){
		memset(mark, false, sizeof mark);
		int val = dfs(1);
		if(!val) break;
		ans += val;
	}
	cout << ans << endl;
	return 0;
}
