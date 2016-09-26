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

const int maxn = 400 + 85 - 69,
	  maxk = maxn * 4 * 2,
	  db9 = 1e9;
vector<int> adjl[maxk],
	adjr[maxk],
	adjd[maxk],
	adju[maxk];
pii fm1[maxk];
bool blc[maxn][maxn];
int dis[maxk][maxk],
	Index[maxn][maxn],
	le[maxn][maxn],
	ri[maxn][maxn],
	up[maxn][maxn],
	dn[maxn][maxn],
	n, m, k, cnt1;
queue<pii> q;

bool is_valid_1(int i, int j){
	return (blc[i - 1][j] or blc[i + 1][j]
		or blc[i][j - 1] or blc[i][j + 1])
		and !blc[i][j];
}

void bfs(void){
	memset(dis, 63, sizeof dis);
	for(int i = 1; i <= cnt1; i++)
		dis[i][i] = 0, q.push({i, i});
	while(sz(q)){
		auto v = q.front();
		q.pop();
		for(int i = 0; i < sz(adjl[v.L]); i++)
			for(int j = 0; j < sz(adjl[v.R]); j++){
				pii u(adjl[v.L][i], adjl[v.R][j]);
				if(dis[u.L][u.R] < db9)
					continue;
				dis[u.L][u.R] = dis[v.L][v.R] + 1;
				q.push(u);
			}
		for(int i = 0; i < sz(adjr[v.L]); i++)
			for(int j = 0; j < sz(adjr[v.R]); j++){
				pii u(adjr[v.L][i], adjr[v.R][j]);
				if(dis[u.L][u.R] < db9)
					continue;
				dis[u.L][u.R] = dis[v.L][v.R] + 1;
				q.push(u);
			}
		for(int i = 0; i < sz(adju[v.L]); i++)
			for(int j = 0; j < sz(adju[v.R]); j++){
				pii u(adju[v.L][i], adju[v.R][j]);
				if(dis[u.L][u.R] < db9)
					continue;
				dis[u.L][u.R] = dis[v.L][v.R] + 1;
				q.push(u);
			}
		for(int i = 0; i < sz(adjd[v.L]); i++)
			for(int j = 0; j < sz(adjd[v.R]); j++){
				pii u(adjd[v.L][i], adjd[v.R][j]);
				if(dis[u.L][u.R] < db9)
					continue;
				dis[u.L][u.R] = dis[v.L][v.R] + 1;
				q.push(u);
			}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i < k; i++){
		int fi, se;
		cin >> fi >> se;
		blc[fi][se] = true;
	}
	n++, m++;
	for(int i = 0; i <= n; i++)
		blc[i][0] = blc[i][m] = true;
	for(int j = 0; j <= m; j++)
		blc[0][j] = blc[n][j] = true;
	for(int i = 1; i < n; i++)
		for(int j = 1; j < m; j++)
			if(is_valid_1(i, j))
				fm1[Index[i][j] = ++cnt1] = MP(i, j);
	for(int i = 1; i < n; i++)
		for(int j = 1; j < m; j++){
			up[i][j] = (blc[i - 1][j] ? i : up[i - 1][j]);
			if(Index[i][j]) adju[Index[up[i][j]][j]].PB(Index[i][j]);
		}
	for(int i = n - 1; i > 0; i--)
		for(int j = 1; j < m; j++){
			dn[i][j] = (blc[i + 1][j] ? i : dn[i + 1][j]);
			if(Index[i][j]) adjd[Index[dn[i][j]][j]].PB(Index[i][j]);
		}
	for(int i = 1; i < n; i++)
		for(int j = 1; j < m; j++){
			le[i][j] = (blc[i][j - 1] ? j : le[i][j - 1]);
			if(Index[i][j]) adjl[Index[i][le[i][j]]].PB(Index[i][j]);
		}
	for(int i = 1; i < n; i++)
		for(int j = m - 1; j > 0; j--){
			ri[i][j] = (blc[i][j + 1] ? j : ri[i][j + 1]);
			if(Index[i][j]) adjr[Index[i][ri[i][j]]].PB(Index[i][j]);
		}
	bfs();
	int q;
	cin >> q;
	while(q--){
		int fi1, fi2, se1, se2;
		cin >> fi1 >> fi2 >> se1 >> se2;
		int val;
		if(MP(fi1, fi2) == MP(se1, se2))
			val = 0;
		else if(Index[fi1][fi2] and Index[se1][se2])
			val = dis[Index[fi1][fi2]][Index[se1][se2]];
		else{
			int d1 = dis[Index[up[fi1][fi2]][fi2]][Index[up[se1][se2]][se2]],
				d2 = dis[Index[dn[fi1][fi2]][fi2]][Index[dn[se1][se2]][se2]],
				d3 = dis[Index[fi1][le[fi1][fi2]]][Index[se1][le[se1][se2]]],
				d4 = dis[Index[fi1][ri[fi1][fi2]]][Index[se1][ri[se1][se2]]];
			val = min(min(d1, d2), min(d3, d4)) + 1;
		}
		cout << (val > db9 ? -1 : val) << '\n';
	}
	return 0;
} 
