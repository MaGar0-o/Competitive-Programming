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

const int maxn = 1000 + 10;
vector<int> adj[maxn],
	vec;
int n;

void dfs(int u){
	while(sz(adj[u])){
		int v = adj[u].back();
		adj[u].pop_back();
		dfs(v);
	}
	vec.PB(u);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int sum = 1;
	for(int i = 0; i < n - 1; i++){
		int cnt;
		cin >> cnt;
		while(cnt--){
			int fi;
			cin >> fi, fi--;
			adj[i].PB(fi);
		}
	}
	{
		int cnt;
		cin >> cnt;
	}
	dfs(0);
	if(sz(vec) == sum){
		for(int i = sz(vec) - 2; i >= 0; i--)
			cout << vec[i]+1 << ' ';
		cout << '\n';
	}
	else
		cout << "NIE\n";
	return 0;
}
