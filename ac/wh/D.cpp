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

const int maxn = 2e5 + 85 - 69;
int frm[maxn],
	too[maxn],
	q1[maxn],
	q2[maxn],
	q3[maxn],
	par[maxn],
	lo[maxn],
	hi[maxn],
	n, m, q;
vector<int> vec[maxn];

int root(int v){return par[v] < 0 ? v : par[v] = root(par[v]);}

void merge(int v, int u){
	if((v = root(v)) == (u = root(u)))
		return;
	if(par[v] > par[u])
		swap(v, u);
	par[v] += par[u];
	par[u] = v;
	return;
}

void check(void){
	for(int i = 0; i < m; i++){
		merge(frm[i], too[i]);
		for(auto quer : vec[i]){
			int v = q1[quer],
				u = q2[quer],
				sz = q3[quer];
			v = root(v);
			u = root(u);
			if((v == u and -par[v] >= sz) or (v != u and -par[v] - par[u] >= sz))
				hi[quer] = i;
			else
				lo[quer] = i;
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		frm[i] = fi;
		too[i] = se;
	}
	cin >> q;
	for(int i = 0; i < q; i++)
		cin >> q1[i] >> q2[i] >> q3[i], q1[i]--, q2[i]--;
	for(int i = 0; i < q; i++)
		hi[i] = m - 1, lo[i] = -1;
	for(int x = 0; x < 20; x++){
		memset(par, -1, sizeof par);
		for(int i = 0; i < m; i++) vec[i].clear();
		for(int i = 0; i < q; i++)
			if(hi[i] - lo[i] > 1)
				vec[(lo[i] + hi[i]) >> 1].PB(i);
		check();
	}
	for(int i = 0; i < q; i++)
		cout << hi[i] + 1 << '\n';
	return 0;
}
