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

const int maxn = 500 + 5,
	  maxnn = maxn * maxn;
bool mark[maxnn];
LL a[maxn][maxn],
	par[maxnn];
int n, m;
int dx[4] = {-1, -0, +0, +1};
int dy[4] = {-0, -1, +1, +0};
vector<pair<LL, pii>> all;
LL cnt, ans;

int root(int v){return par[v] < 0 ? v : par[v] = root(par[v]);}

void merge(int v, int u){
	if((v = root(v)) == (u = root(u)))
		return;
	if(par[v] > par[u]) swap(v, u);
	if(mark[v] or mark[u]) cnt += (!mark[v]) * par[v] + (!mark[u]) * par[u];
	mark[v] |= mark[u];
	par[v] += par[u];
	par[u] = v;
	return;
}

void add(pii cel){
	cnt++;
	int x = cel.L,
		y = cel.R;
	for(int i = 0; i < 4; i++){
		int xx = x + dx[i],
			yy = y + dy[i];
		if(a[xx][yy] < a[x][y] or (i < 2 and a[xx][yy] == a[x][y]))
			merge(x*m+y, xx*m+yy);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(par, -1, sizeof par);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
			all.PB(MP(a[i][j], MP(i, j)));
		}
	n+=2, m+=2;
	for(int i = 0; i < n; i++)
		mark[i * m] = mark[i * m + m - 1] = true;
	for(int j = 0; j < m; j++)
		mark[j] = mark[(n - 1) * m + j] = true;
	sort(all(all));
	for(int i = 0; i < sz(all);){
		int p = i;
		do{
			add(all[p++].R);
		}while(p < n and all[p].L == all[p-1].L);
		i = p;
		if(i == n) break;
		ans += cnt * (all[i].L - all[i - 1].L);
	}
	cout << ans << endl;
	return 0;
}
