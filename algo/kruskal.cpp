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

const int maxn = 1e5 + 100;
int wei[maxn],		//weight
	frm[maxn],		//from
	too[maxn],		//to
	ord[maxn],
	par[maxn],
	n, m;

bool cmp(int i, int j){return wei[i] < wei[j];}

int root(int u){ return par[u] < 0 ? u : par[u] = root(par[u]);}

bool merge(int u, int v){
	if((u=root(u)) == (v=root(v)))
		return false;
	if(par[u] > par[v]) swap(u, v);
	par[u] += par[v];
	par[v] = u;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(par, -1, sizeof par);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> frm[i] >> too[i] >> wei[i];
		frm[i]--, too[i]--;		//0-base is the best :D
	}
	iota(ord, ord + m, 0);
	sort(ord, ord + m, cmp);
	LL sum = 0;
	vector<int> vec;
	for(int i = 0; i < m; i++){
		int id = ord[i];
		if(merge(frm[id], too[id])){
			sum += wei[id];
			vec.PB(id);
		}
	}
	cout << sum << '\n';
	for(auto e : vec)
		cout << e+1 << ' ';		//yaal haye 1-base
	cout << '\n';
	return 0;
}
