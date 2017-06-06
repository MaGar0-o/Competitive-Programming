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

#define int long long

const int maxn = 100 + 10,
	  maxm = 500 + 100;
const int Inf = 1e18;
bool mark[maxn];
int dis[maxn],
	cap[maxm],
	too[maxm],
	prv[maxm],
	hed[maxn],
	ghe[maxn],
	pos[maxn],
	tim[maxn],
	indeg[maxn],
	rem[maxn],
	h[maxn],
	n, edg, pool, sou, syn;
vector<int> adj[maxn];
queue<int> q;

void adde(int u, int v, int uv = Inf, int vu = 0){
	too[edg] = v, cap[edg] = uv, prv[edg] = hed[u], hed[u] = edg++;
	too[edg] = u, cap[edg] = vu, prv[edg] = hed[v], hed[v] = edg++;
}

void set_dis(int st){
	memset(dis, 0, sizeof dis);
	q.push(st);
	memcpy(rem, indeg, sizeof indeg);
	while(sz(q)){
		int u = q.front();
		q.pop();
		for(auto v : adj[u]){
			smax(dis[v], dis[u] + tim[v]);
			rem[v]--;
			if(!rem[v])
				q.push(v);
		}
	}
	return;
}

bool bfs(void){
	memset(mark, false, sizeof mark);
	q.push(sou);
	mark[sou] = true;
	while(sz(q)){
		int u = q.front();
		q.pop();
		for(int e = hed[u]; ~e; e = prv[e]){
			int v = too[e];
			if(!cap[e] or mark[v]) continue;
			mark[v] = true;
			h[v] = h[u] + 1;
			q.push(v);
		}
	}
	return mark[syn];
}

int dff(int u, int flow = Inf){
	if(u == syn) return flow;
	int ret = 0;
	for(int &e = pos[u]; ~e; e = prv[e]){
		int v = too[e];
		if(!cap[e] or h[v] != h[u] + 1) continue;
		LL tmp = dff(v, min(cap[e], flow));
		ret += tmp;
		flow -= tmp;
		cap[e^0] -= tmp;
		cap[e^1] += tmp;
		if(!flow) break;
	}
	return ret;
}

int maxflow(void){
	int ret = 0;
	while(bfs()){
		memcpy(pos, hed, sizeof hed);
		ret += dff(sou);
	}
	return ret;
}

void dfs(int u){
	mark[u] = true;
	for(int e = hed[u]; ~e; e = prv[e])
		if(cap[e] and !mark[too[e]])
			dfs(too[e]);
	return;
}

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			char c;
			cin >> c;
			if(c - '0')
				adj[j].PB(i), indeg[i]++;
		}
	}
	for(int i = 0; i < n; i++){
		if(!indeg[i])
			adj[n].PB(i), indeg[i]++;
		if(!sz(adj[i]))
			adj[i].PB(n + 1), indeg[n + 1]++;
	}
	for(int i = 0; i < n; i++)
		cin >> tim[i];
	for(int i = 0; i < n; i++)
		cin >> ghe[i];
	cin >> pool;
	sou = n<<1;
	syn = (n+1)<<1|1;
	ghe[n] = ghe[n + 1] = Inf;
	while(1)
	{
		set_dis(n);
		memset(hed, -1, sizeof hed);
		edg = 0;
		for(int i = 0; i <= n + 1; i++)
			adde(i<<1|0, i<<1|1, ghe[i]);
		for(int i = 0; i <= n + 1; i++)
			for(auto j : adj[i])
				if(dis[i] + tim[j] == dis[j])
					adde(i<<1|1, j<<1);
		int val = maxflow();
		if(val <= pool){
			//cout << val << ' ' << dis[n + 1] << endl;
			pool -= val;
			memset(mark, false, sizeof mark);
			dfs(sou);
			for(int i = 0; i <= n + 1; i++)
				if(mark[i << 1] and !mark[i << 1 | 1] and tim[i]){
					tim[i]--;//cout << i << ' ';
					if(!tim[i])
						ghe[i] = Inf;
				}
		}
		else break;
		if(dis[n + 1] == 0) break;
		//cout << endl << endl;
	}
	set_dis(n);
	cout << dis[n + 1] << '\n';
	return 0;
}
