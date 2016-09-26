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

const int maxn = 1e5 + 85 - 69;
int a[maxn],
	las[maxn],
	par[maxn],
	ans[maxn],
	n;
map<int, int> mp;
vector<int> vec[maxn],
	vec2[maxn],
	pri;

bool isprime(int x){
	for(int i = 2; i * i <= x; i++)
		if(x % i == 0)
			return false;
	return true;
}

int root(int v){ return par[v] < 0 ? v : par[v] = root(par[v]);}

void merge(int v, int u){
	if((v = root(v)) == (u = root(u)))
		return;
	if(par[v] > par[u])
		swap(v, u);
	par[v] += par[u];
	par[u] = v;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(par, -1, sizeof par);
	memset(las, -1, sizeof las);
	for(int i = 2; i * i <= 100000 * 10000; i++)
		if(isprime(i))
			pri.PB(i);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		int x = a[i];
		for(int j = 0; j < sz(pri) and x > 1; j++)
			if(x % pri[j] == 0){
				while(x % pri[j] == 0) x /= pri[j];
				if(~las[j]) merge(i, las[j]);
				las[j] = i;
			}
		if(x > 1){
			if(mp[x]) merge(i, mp[x] - 1);
			mp[x] = i + 1;
		}
	}
	for(int i = 0; i < n; i++)
		vec[root(i)].PB(a[i]),
			vec2[root(i)].PB(i);
	for(int i = 0; i < n; i++){
		sort(all(vec[i]));
		for(int j = 0; j < sz(vec[i]); j++)
			ans[vec2[i][j]] = vec[i][j];
	}
	for(int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
} 
