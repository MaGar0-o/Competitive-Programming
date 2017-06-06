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

const int maxn = 1e6 + 1000;
vector<int> adj[maxn],
	jda[maxn];
int com[maxn],
	stc[maxn],
	//dstc[maxn],
	n, m, comcnt, sz, dsz;
bool mark[maxn],
	 ans[maxn/2];

void adde(int u, int v){
	jda[u].PB(v);
	adj[v].PB(u);
}

void addor(int u, int v){
	adde(u^1, v);
	adde(v^1, u);
}

void dfs(int u){
	mark[u] = true;
	for(int i = 0; i < sz(adj[u]); i++){
		int v = adj[u][i];
		if(!mark[v])
			dfs(v);
	}
	stc[sz++] = u;
}

void sfd(int u){
	mark[u] = true;
	com[u] = comcnt;
	for(int i = 0; i < sz(jda[u]); i++){
		int v = jda[u][i];
		if(!mark[v])
			sfd(v);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	srand(time(0));
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		int fi1, se1, fi2, se2;
		cin >> fi1 >> se1 >> fi2 >> se2, fi1--, fi2--;
		int v1 = (fi1<<1)^se1^1,
			v2 = (fi2<<1)^se2^1;
		addor(v1, v2);
	}
	for(int i = 0; i < m + m; i++)
		random_shuffle(all(adj[i]));
	for(int i = 0; i < m+m; i++)
		if(!mark[i]){
			dfs(i);
			/*dstc[(dsz = 0)++] = i;
			mark[i] = true;
			while(dsz){
				int u = dstc[dsz - 1];
				if(sz(adj[u]) == 0){
					stc[sz++] = u;
					dsz--;
					continue;
				}
				int v = adj[u].back();
				adj[u].pop_back();
				if(!mark[v])
					dstc[dsz++] = v, mark[v] = true;
			}*/
		}
	//return 0;
	memset(mark, false, m<<1);
	for(int i = sz - 1; i >= 0; i--){
		int u = stc[i];
		if(mark[u]) continue;
		sfd(u);
		comcnt++;
	}
	for(int i = 0; i < m+m; i+=2)
		if(com[i] == com[i^1]){
			cout << "IMPOSSIBLE\n";
			return 0;
		}
		else
			ans[i>>1] = com[i] < com[i^1];
	for(int i = 0; i < m; i++)
		cout << ans[i] << '\n';
	return 0;
}
