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

const int maxn = 5e4 + 10;
vector<int> adj[maxn],
	jda[maxn];
int com[maxn],
	vcnt[maxn],
	ecnt[maxn],
	comcnt;
bool bad[maxn],
	 mark[maxn],
	 has[maxn];
vector<int> stc,
	vert[maxn];

void dfs(int u){
	mark[u] = true;
	for(int i = 0; i < sz(adj[u]); i++)
		if(!mark[adj[u][i]])
			dfs(adj[u][i]);
	stc.PB(u);
	return;
}

void sfd0(int u){
	mark[u] = true;
	vcnt[com[u] = comcnt]++;
	vert[com[u]].PB(u);
	for(int i = 0; i < sz(jda[u]); i++)
		if(!mark[jda[u][i]])
			sfd0(jda[u][i]);
	return;
}

void sfd1(int u){
	mark[u] = true;
	for(int i = 0; i < sz(jda[u]); i++)
		if(!mark[jda[u][i]])
			sfd1(jda[u][i]);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	while(cin >> n >> m and (n or m)){
		for(int i = 0; i< n; i++)
			adj[i].clear(), jda[i].clear();
		for(int i = 0; i < m; i++){
			int fi, se;
			cin >> fi >> se;
			fi--, se--;
			adj[fi].PB(se);
			jda[se].PB(fi);
		}
		memset(mark, false, n);
		for(int i = 0; i < n; i++)
			if(!mark[i])
				dfs(i);
		memset(mark, false, n);
		comcnt = 0;
		while(sz(stc)){
			int u = stc.back();
			stc.pop_back();
			if(!mark[u]){
				vcnt[comcnt] = 0;
				sfd0(u);
				comcnt++;
			}
		}
		memset(ecnt, 0, comcnt * 4);
		memset(bad, false, comcnt);
		memset(has, false, comcnt);
		for(int i = comcnt - 1; i >= 0; i--)
			for(int j = 0; j < sz(vert[i]); j++){
				int u = vert[i][j];
				for(int k = 0; k < sz(adj[u]); k++){
					int v = adj[u][k];
					if(com[v] > com[u] and (has[com[v]] or vcnt[com[v]] > 1))
						has[com[u]] = true;
				}
			}
		for(int i = 0; i < comcnt; i++)
			if(vcnt[i] > 1 and has[i])
				bad[i] = true;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < sz(adj[i]); j++)
				if(com[i] == com[adj[i][j]])
					ecnt[com[i]]++;
		for(int i = 0; i < comcnt; i++)
			if((ecnt[i]^vcnt[i]) and vcnt[i] > 1)
				bad[i] = true;
		/*for(int i = 0; i < comcnt; i++, cout << '\n'){
			cout << has[i]<<bad[i] << ' ' << ecnt[i] << ' ' << vcnt[i] <<  ": ";
			for(int j = 0; j < vcnt[i]; j++)
				cout << vert[i][j]+1 << ' ';
		}*/
		memset(mark, false, n);
		for(int i = 0; i < n; i++)
			if(bad[com[i]] and !mark[i])
				sfd1(i);
		int ans = 0;
		for(int i = 0; i < n; i++)
			ans += mark[i] or (has[com[i]] and vcnt[com[i]] > 1);
		cout << ans << '\n';
	}
	return 0;
}
