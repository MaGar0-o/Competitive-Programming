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

const int XX = 1e5+85-69;
const int maxn = 1e5 + 85 - 69;

vector<int> adj[maxn];
int sec[XX], sz;
int n;

void dfs(int u, int p = -1){
	while(sz(adj[u])){
		int v = adj[u].back();
		adj[u].pop_back();
		dfs(v, u);
	}
	sec[sz++] = u;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j +1 < n; j++)
			adj[i].PB((i + j + 1) % n);
	cout << "1 1 0\n";
	dfs(0);
	for (int i = sz-1; i>1; i--)
		cout << sec[i-1]+1 << " " << sec[i-1] + 1 << " " << sec[i] + 1 << "\n";
	cout << "0 1 " << sec[1]+1 << "\n";
	return 0;
}
