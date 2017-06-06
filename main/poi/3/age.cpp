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
#define cos CoS

const int maxn = 3000 + 10;
vector<int> adj[maxn],
	jda[maxn];
int cos[maxn],
	com[maxn],
	incnt[maxn],
	comcos[maxn],
	stc[maxn], sz,
	comcnt,
	n, m, p;
bool mark[maxn];

void dfs(int u){
	if(mark[u]) return;
	mark[u] = true;
	for(int v = 0; v < sz(adj[u]); v++) dfs(adj[u][v]);
	stc[sz++] = u;
	return;
}

void sfd(int u){
	if(mark[u]) return;
	mark[u] = true;
	com[u] = comcnt;
	for(int v = 0; v < sz(jda[u]); v++) sfd(jda[u][v]);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(cos, 63, sizeof cos);
	memset(comcos, 63, sizeof comcos);
	cin >> n
		>> p;
	for(int i = 0; i < p; i++){
		int fi, se;
		cin >> fi >> se, fi--;
		smin(cos[fi], se);
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se, fi--, se--;
		adj[fi].PB(se);
		jda[se].PB(fi);
	}
	for(int i = 0; i < n; i++)
		dfs(i);
	memset(mark, false, sizeof mark);
	memset(com, -1, sizeof com);
	while(sz--){
		if(mark[stc[sz]]) continue;
		sfd(stc[sz]);
		comcnt++;
	}
	for(int u = 0; u < n; u++)
		smin(comcos[com[u]], cos[u]);
	for(int u = 0; u < n; u++)
		for(int v = 0; v < sz(adj[u]); v++)
			if(com[adj[u][v]] != com[u])
				incnt[com[adj[u][v]]]++;
	LL ans = 0;
	for(int i = 0; i < comcnt; i++)
		if(!incnt[i]){
			if(comcos[i] > 1e9){
				cout << "NIE\n";
				for(int j = n - 1; j >= 0; j--)
					if(com[j] == i){
						cout << j + 1 << '\n';
						break;
					}
				return 0;
			}
			ans += comcos[i];
		}
	cout << "TAK\n"
		<< ans << '\n';
	return 0;
}
