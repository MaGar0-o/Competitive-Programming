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

const int maxn = 3e6 + 10;
int dn[maxn],
	n;
vector<int> adj[maxn];

bool can(int u, int sz, int p = -1){
	dn[u] = 1;
	for(auto v : adj[u])
		if(v != p){
			if(!can(v, sz, u))
				return false;
			dn[u] += dn[v];
		}
	if(dn[u] > sz)
		return false;
	dn[u] %= sz;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++){
		int x;
		cin >> x;
		adj[i].PB(x - 1);
		adj[x - 1].PB(i);
	}
	for(int i = n; i >= 1; i--)
		if(n % i == 0 and can(0, i) and dn[0] == 0)
			cout << n / i << " \n"[i == 1];
	return 0;
}
