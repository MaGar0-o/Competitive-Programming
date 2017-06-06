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
 
const int maxn = 50000 + 10;
int match[2][maxn];
vector<int> adj[maxn];
bool mark[maxn];
int n, m, p;
 
bool dfs(int v){
	if(mark[v])
		return false;
	mark[v] = true;
	for(auto u : adj[v]){
		if(match[1][u] == -1){
			match[0][v] = u;
			match[1][u] = v;
			return true;
		}
		if(dfs(match[1][u])){
			match[0][v] = u;
			match[1][u] = v;
			return true;
		}
	}
	return false;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d%d", &n, &m, &p);
	memset(match, -1, sizeof match);
	bool sw = n > m;
	if(sw) swap(n, m);
	for(int i = 0; i < p; i++){
		int fi, se;
		scanf("%d%d", &fi, &se);
		fi--, se--;
		if(sw) swap(fi, se);
		adj[fi].PB(se);
	}
	bool found;
	int ans = 0;
	do{
		found = false;
		memset(mark, false, sizeof mark);
		for(int i = 0; i < n; i++) if(match[0][i] == -1){
			bool an = dfs(i);
			ans += an;
			found |= an;
		}
	}while(found);
	printf("%d", ans);
	return 0;
}
