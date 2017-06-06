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

const int maxn = 2000,
	  maxm = 2000 * 2000 + 10;
int hed[maxn],
	pos[maxn],
	too[maxm],
	cap[maxm],
	prv[maxm],
	h[maxn],
	a[maxn],
	n, m, edg, sou, syn;
vector<int> q, vec;
map<int, pii> mp;

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
		//cout << u << endl;
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
	cin >> n >> m;
	int gam = 0;
	for(int i = 0; i < n; i++)
		cin >> a[i], gam += a[i];
	gam >>= 1;
	sou = n + gam + 0,
	syn = n + gam + 1;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		mp[i] = MP(fi, se);
		add_edge(i, gam + fi, 2);
		add_edge(i, gam + se, 2);
	}
	for(int i = m; i < gam; i++)
		for(int j = gam; j < gam + n; j++)
			add_edge(i, j, 2);
	for(int i = 0; i < gam; i++)
		add_edge(sou, i, 2);
	for(int i = 0; i < n; i++)
		add_edge(gam + i, syn, a[i]);
	int x = 0;
	while(bfs()){
		memcpy(pos, hed, sizeof hed);
		x += dfs();
	}
	/*for(auto id : vec)
		cout << cap[id] << ' ';
	cout << endl;*/
	cout << gam << '\n';
	for(int i = 0; i < gam; i++){
		bool fnd = false;
		int fi, se = -1, th;
		for(int e = hed[i]; ~e; e = prv[e]){
			if(too[e] >= gam and too[e] < gam + n and cap[e^1]){
				if(!fnd){
					fi = too[e] - gam;
					th = cap[e^1];
				}
				else
					se = too[e] - gam;
				fnd = true;
			}
		}
		
		if(~se)
			cout << fi + 1 << ' ' << se + 1 << ' ' << th << '\n';
		else if(i >= m)
			cout << fi + 1 << ' ' << (fi ? 1 : 2) << ' ' << th << '\n';
		else
			cout << fi + 1 << ' ' << (fi^mp[i].L^mp[i].R)+1 << ' ' << th << '\n';
	}
	return 0;
}
