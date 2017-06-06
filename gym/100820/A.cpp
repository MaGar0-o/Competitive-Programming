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

const int maxn = 500 + 10;
vector<int> vec[maxn];
int dis[maxn][maxn],
	adj[maxn][maxn],
	match[maxn<<1],
	frm[maxn],
	too[maxn],
	tim[maxn],
	p[maxn],
	n, m;
bool mark[maxn<<1];

bool dfs(int u){
	if(mark[u]) return false;
	mark[u] = true;
	for(auto v : vec[u])
		if(match[v] == -1 or dfs(match[v])){
			match[u] = v;
			match[v] = u;
			return true;
		}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(match, -1, sizeof match);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> p[i];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> adj[i][j], adj[i][j] += (i != j) * p[j], dis[i][j] = adj[i][j];
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				smin(dis[i][j], dis[i][k] + dis[k][j]);
	for(int i = 0; i < m; i++)
		cin >> frm[i] >> too[i] >> tim[i], frm[i]--, too[i]--;
	for(int i = 0; i < m; i++)
		for(int j = 0; j < m; j++)
			if(i != j and tim[i] + adj[frm[i]][too[i]] + dis[too[i]][frm[j]] <= tim[j])
				vec[i].PB(m + j);//, cout << i << ' ' << j << endl;
	bool found = true;
	int ans = 0;
	while(found){
		found = false;
		memset(mark, false, sizeof mark);
		for(int i = 0; i < m; i++)
			if(!mark[i] and match[i] == -1 and dfs(i))
				ans++, found = true;
	}
	cout << m - ans << '\n';
	return 0;
}
