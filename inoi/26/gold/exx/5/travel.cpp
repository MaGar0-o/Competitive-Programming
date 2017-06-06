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
#define cos coS

const int maxn = 1000 + 85 - 69,
	  maxm = 1e6 + 5e5;
const LL Inf = 1e18;
LL cap[maxm];
int too[maxm],
	prv[maxm],
	hed[maxn],
	pos[maxn],
	h[maxn],
	n, eg, sou, syn;
bool mark[maxn];
queue<int> q;
vector<int> ans;

void adde(int u, int v, int uv, int vu = 0){
	too[eg] = v, cap[eg] = uv, prv[eg] = hed[u], hed[u] = eg++;
	too[eg] = u, cap[eg] = vu, prv[eg] = hed[v], hed[v] = eg++;
}

bool bfs(void){
	memset(h, 63, sizeof h);
	q.push(sou);
	h[sou] = 0;
	while(sz(q)){
		int u = q.front();
		q.pop();
		for(int e = hed[u]; ~e; e = prv[e]) if(cap[e]){
			int v = too[e];
			if(h[u] + 1 >= h[v]) continue;
			h[v] = h[u] + 1;
			q.push(v);
		}
	}
	return h[syn] != h[maxn - 1];
}

LL dfs(int u = sou, LL flow = Inf){
	if(u == syn) return flow;
	mark[u] = true;
	LL ret = 0;
	for(int &e = pos[u]; ~e and flow; e = prv[e]){
		int v = too[e];
		if(cap[e] and h[v] == h[u] + 1){
			LL val = dfs(v, min(flow, cap[e]));
			ret += val;
			flow -= val;
			cap[e] -= val;
			cap[e^1] += val;
		}
		if(!flow) break;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(hed, -1, sizeof hed);
	/*cout << 0 << endl;
	return 0;*/
	cin >> n;
	sou = n, syn = n + 1;
	for(int i = 0; i < n; i++){
		LL cos, cnt;
		cin >> cos >> cnt;
		if(cos < 0)
			adde(i, syn, -cos);
		else
			adde(sou, i, cos);
		for(int j = 0; j < cnt; j++){
			int fi, se;
			cin >> fi >> se, fi--;
			adde(i, fi, se);
		}
	}
	while(bfs()){
		memcpy(pos, hed, sizeof hed);
		dfs();
	}
	memset(mark, false, sizeof mark);
	memcpy(pos, hed, sizeof hed);
	dfs();
	for(int i = 0; i < n; i++)
		if(mark[i])
			ans.PB(i + 1);
	cout << sz(ans) << '\n';
	for(auto val : ans)
		cout << val << ' ';
	cout << '\n';
	return 0;
}
