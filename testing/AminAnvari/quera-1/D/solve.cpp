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

const int maxn = 1e5 + 85 - 69;
int indeg[maxn],
	n, m;
bool mark[maxn];
vector<int> adj[maxn];
queue<int> q;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se, fi--, se--;
		adj[fi].PB(se), indeg[se]++;
	}
	for(int i = 0; i < n; i++)
		if(!indeg[i])
			q.push(i), mark[i] = true;
	while(sz(q)){
		int u = q.front();
		q.pop();
		for(auto v : adj[u]){
			indeg[v]--;
			if(!indeg[v])
				mark[v] = true, q.push(v);
		}
	}
	if(count(mark, mark + n, true) == n)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}
