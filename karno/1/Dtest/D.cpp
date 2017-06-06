//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define smin(x, y) ((x) = min((x), (y)))

const int maxn = 2e5 + 10;
const LL Inf = 1e18;
LL wei[maxn], x;
int ord[maxn],
	frm[maxn],
	too[maxn],
	par[maxn];
int n, m;

int root(int u){ return par[u] < 0 ? u : par[u] = root(par[u]);}

bool merge(int u, int v){
	if((u = root(u)) == (v = root(v)))
		return false;
	if(par[u] > par[v]) swap(u, v);
	par[u] += par[v];
	par[v] = u;
	return true;
}

bool cmp(int i, int j){
	return wei[i] < wei[j];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(par, -1, sizeof par);
	cin >> n >> m >> x;
	for(int i = 0; i < m; i++){
		cin >> frm[i] >> too[i] >> wei[i];
		frm[i]--, too[i]--;		//0-base is the best :D
	}
	iota(ord, ord + m, 0);
	sort(ord, ord + m, cmp);
	int cnt = 0;
	LL sum = 0;
	LL ans = Inf;
	for(int i = 0; i < m; i++){
		int id = ord[i];
		if(merge(frm[id], too[id])){
			cnt++;
			sum += wei[id];
			smin(ans, sum + (n - cnt) * x);
		}
	}
	if(cnt == n - 1)
		smin(ans, sum);
	cout << ans << '\n';
	return 0;
}
