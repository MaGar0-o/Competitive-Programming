//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<LD, pll> pdll;
typedef pair<LD, LD> pdd;

#define PB emplace_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1000 + 10;
int par[maxn];
pdd P[maxn];
vector<pdll> E;
int n;

LD dist(int i, int j){
	LD dx = P[i].L - P[j].L,
	   dy = P[i].R - P[j].R;
	return dx * dx + dy * dy;
}

int root(int v){return par[v] < 0 ? v : par[v] = root(par[v]);}

bool merge(int v, int u){
	if((v = root(v)) == (u = root(u)))
		return false;
	if(par[v] > par[u])
		swap(v, u);
	par[v] += par[u];
	par[u] = v;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(par, -1, sizeof par);
	cin >> n, n++;
	for(int i = 1; i < n; i++)
		cin >> P[i].L >> P[i].R;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < i; j++)
			E.PB(MP(dist(i, j), MP(i, j)));
	sort(all(E));
	LD ans = 0;
	for(auto e : E){
		int v = e.R.L,
			u = e.R.R;
		if(merge(v, u))
			ans += sqrt(e.L);
	}
	cout.precision(2);
	cout << fixed << ans << endl;
	return 0;
}
