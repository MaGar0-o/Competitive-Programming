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

const int maxn = 50 + 50 + 10, maxm = 200 * 10;
int cap[maxm],
	too[maxm],
	prv[maxm],
	hed[maxn],
	pos[maxn],
	h[maxn],
	n, m, e, edg,
	sou, syn;
vector<int> q, vec;

void add_edge(int u, int v, int uv, int vu = 0){
	too[edg] = v, cap[edg] = uv, prv[edg] = hed[u], hed[u] = edg++;
	too[edg] = u, cap[edg] = vu, prv[edg] = hed[v], hed[v] = edg++;
}

int dfs(int u = sou, int flw = 1000000 * 1000){
	if(u == syn or !flw) return flw;
	int ret = 0;
	for(int &e = pos[u]; ~e; e = prv[e])
		if(h[too[e]] == h[u] + 1 and cap[e]){
			int tmp = dfs(too[e], min(flw, cap[e]));
			ret += tmp;
			flw -= tmp;
			cap[e] -= tmp;
			cap[e^1] += tmp;
			if(!flw) return ret;
		}
	return ret;
}

bool bfs(void){
	q.clear();
	memset(h, -1, sizeof h);
	q.PB(sou);
	h[sou] = 0;
	for(int i = 0; i < sz(q); i++){
		int u = q[i];
		for(int e = hed[u]; ~e; e = prv[e])
			if(cap[e] and !~h[too[e]])
				q.PB(too[e]), h[too[e]] = h[u] + 1;
	}
	return ~h[syn];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(hed, -1, sizeof hed);
	cin >> n >> m >> e;
	sou = n + m;
	syn = n + m + 1;
	for(int i = 0; i < n; i++)
		vec.PB(edg), add_edge(sou, i, 0);
	for(int i = 0; i < m; i++)
		add_edge(n + i, syn, 1);
	for(int i = 0; i < e; i++){
		int fi, se;
		cin >> fi >> se, fi--, se--;
		add_edge(fi, se + n, 1);
	}
	int sum = 0;
	for(int i = 1; i <= m; i++){
		for(int j = 0; j < n; j++)
			cap[vec[j]]++;
		while(bfs()){
			memcpy(pos, hed, sizeof hed);
			sum += dfs();
		}
		if(sum == m){
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}
