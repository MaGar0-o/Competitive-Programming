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

const int maxn = 750 + 5,
	  maxnn = maxn * maxn;
const LL Mod = 1000 * 1000 * 1000 + 7;
vector<LL> fen[maxnn],
	vec[maxnn];
LL sum[maxn][maxn];
LL dp[maxn];
int a[maxn][maxn];
int n, m, k;

LL get(int id, int idx){
	idx = upper_bound(all(vec[id]), idx) - vec[id].begin() - 1;
	LL ret = 0;
	while(idx > 0){
		ret += fen[id][idx];
		idx -= idx & -idx;
	}
	return ret;
}

LL get(int id, int st, int en){
	return (get(id, en) - get(id, st - 1)) % Mod;
}

void add(int id, LL val, int idx){
	idx = lower_bound(all(vec[id]), idx) - vec[id].begin();
	while(idx < sz(fen[id])){
		fen[id][idx] = (fen[id][idx] + val) % Mod;
		idx += idx & -idx;
	}
	return;
}

int main(){
	ifstream cin("hopscotch.in");
	ofstream cout("hopscotch.out");
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			cin >> a[i][j], a[i][j]--;
			vec[a[i][j]].PB(j);
		}
	for(int i = 0; i < k; i++){
		vec[i].PB(-1);
		sort(all(vec[i]));
		vec[i].resize(unique(all(vec[i])) - vec[i].begin());
		fen[i].resize(sz(vec[i]) + 1);
	}
	for(int i = n - 1; i >= 0; i--){
		memset(dp, 0, sizeof dp);
		for(int j = 0; j < m; j++){
			dp[j] = sum[i + 1][j + 1];
			dp[j] -= get(a[i][j], j + 1, m - 1);
			dp[j] %= Mod;
			add(a[i][j], dp[j], j);
		}
		if(i == n - 1){
			dp[m - 1] = 1;
			add(a[n - 1][m - 1], 1, m - 1);
		}
		for(int j = m - 1; j >= 0; j--)
			sum[i][j] = (dp[j] + sum[i][j + 1] + sum[i + 1][j] - sum[i + 1][j + 1]) % Mod;
	}
	cout << (dp[0] + Mod) % Mod << endl;
	return 0;
}
