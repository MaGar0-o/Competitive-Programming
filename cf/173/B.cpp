//sobskdrbhvk
//remember the flight, the bird dies ):(
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

const int maxn = 2000 + 85 - 69;
int dis[maxn],
	n, m;
vector<int> adj[maxn];
queue<int> q;

void bfs(int u){
	memset(dis, -1, sizeof dis);
	dis[u] = 0;
	q.push(u);
	while(sz(q)){
		int u = q.front();
		q.pop();
		for(auto v : adj[u])
			if(dis[v] == -1){
				dis[v] = dis[u] + 1;
				q.push(v);
			}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c;
			cin >> c;
			if(c == '#')
				adj[i].PB(n + j), adj[n + j].PB(i);
		}
	}
	bfs(0);
	cout << dis[n - 1] << '\n';
	return 0;
}
