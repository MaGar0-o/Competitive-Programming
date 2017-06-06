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

const int maxn = 1.6e4 + 85 - 69;
int too[maxn],
	cap[maxn],
	prv[maxn],
	hed[maxn],
	pos[maxn],
	hei[maxn],
	edg;
unordered_map<string, int> id;

void add_edge(int u, int v, int uv = 1, int vu = 0){
	too[edg] = v, cap[edg] = uv, prv[edg] = hed[u], hed[u] = edg++;
	too[edg] = u, cap[edg] = vu, prv[edg] = hed[v], hed[v] = edg++;
	return;
}

void add(int w, int s){
	if(s^0) add_edge(w<<1|1, s);
	if(s^1) add_edge(s, w<<1);
	return;
}

bool bfs(void){
	queue<int> q;
	hei[0] = 0;
	q.push(0);
	while(sz(q)){
		int u = q.front();
		q.pop();
		for(int e = hed[u]; ~e; e = prv[e]){
			int v = too[e];
			if(cap[e] == 0 or ~hei[v]) continue;
			hei[v] = hei[u] + 1;
			q.push(v);
		}
	}
	return ~hei[1];
}

int dfs(int u, int flow = 1000*1000){
	if(u == 1) return flow;
	int ret = 0;
	for(int &e = pos[u]; ~e; e = prv[e]){
		int v = too[e];
		if(cap[e] == 0 or hei[v] != hei[u] + 1) continue;
		int tmp = dfs(v, min(flow, cap[e]));
		cap[e^0] -= tmp;
		cap[e^1] += tmp;
		flow -= tmp;
		ret += tmp;
		if(!flow) break;
	}
	return ret;
}

int solve(void){
	memset(hed, -1, sizeof hed);
	memset(hei, -1, sizeof hei);
	id.clear();
	edg = 0;
	int n;
	cin >> n;
	int ID = n;
	string s;
	getline(cin, s);
	for(int i = 0; i < n; i++){
		stringstream ss;
		getline(cin, s);
		ss << s;
		while(ss >> s){
			if(!id[s]) id[s] = ID++;
			add(id[s], i);
		}
	}
	for(int i = n; i < ID; i++)
		add_edge(i<<1, i<<1|1);
	int ans = 0;
	while(bfs()){
		memcpy(pos, hed, sizeof hed);
		ans += dfs(0);
		memset(hei, -1, sizeof hei);
	}
	return ans;
}

int main(){
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++)
		printf("Case #%d: %d\n", i, solve());
	return 0;
}
