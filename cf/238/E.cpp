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

const int maxn = 100 + 2;
queue<int> q;
vector<int> adj[maxn],
	jda[maxn];
int dis[maxn],
	sid[maxn];
bool mark[maxn],
	 mat[maxn][maxn];
int n, m, a, b;

void bfs(int st, int *d, vector<int> *ham){
	memset(d, 63, maxn * 4);
	memset(mark, false, sizeof mark);
	q.push(st);
	d[st] = 0;
	mark[st] = true;
	while(sz(q)){
		int u = q.front();
		q.pop();
		for(auto v : ham[u])
			if(!mark[v]){
				mark[v] = true;
				d[v] = d[u] + 1;
				q.push(v);
			}
	}
	return;
}

void dorostkon(int st, int en){
	bfs(st, dis, adj);
	if(!mark[en]) return;
	bfs(en, sid, jda);
	int ds = dis[en];
	vector<int> vec;
	for(int i = 0; i <= n; i++){
		int ver = -1;
		for(int j = 0; j < n; j++)
			if(dis[j] == i and sid[j] == ds - i){
				if(~ver) goto hell;
				ver = j;
			}
		if(~ver) vec.PB(ver);
hell:;
	}
	for(int i = 0; i < sz(vec); i++)
		for(int j = i + 1; j < sz(vec); j++)
			mat[vec[i]][vec[j]] = true;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> a >> b;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se, fi--, se--;
		adj[fi].PB(se);
		jda[se].PB(fi);
	}
	int compan;
	cin >> compan;
	for(int i = 0; i < compan; i++){
		int fi, se;
		cin >> fi >> se, fi--, se--;
		dorostkon(fi, se);
	}
	a--, b--;
	memset(dis, 63, sizeof dis);
	memset(mark, false, sizeof mark);
	dis[a] = 0;
	mark[a] = true;
	q.push(a);
	while(sz(q)){
		int u = q.front();
		q.pop();
		for(int v = 0; v < n; v++)
			if(mat[u][v] and !mark[v]){
				mark[v] = true;
				dis[v] = dis[u] + 1;
				q.push(v);
			}
	}
	cout << (!mark[b] ? -1 : dis[b]) << '\n';
	return 0;
}
