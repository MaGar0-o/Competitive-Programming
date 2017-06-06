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

const int maxn = 1000 + 10;
LL Mod = 1e9 + 7;
int dp[maxn][maxn],
	sum[maxn][maxn];
int a[maxn], n;
vector<int> all;

int idof(int val){
	int id = lower_bound(all(all), val) - all.begin();
	if(id == sz(all) or all[id] != val) return -1;
	return id;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i], all.PB(a[i]);
	sort(all(all));
	all.resize(unique(all(all)) - all.begin());
	for(int i = 0; i < n; i++)
		a[i] = lower_bound(all(all), a[i]) - all.begin();
	LL ans = 0;
	for(int i = n - 1; i >= 0; i--)
		for(int j = n - 1; j > i; j--){
			int val = (all[a[i]] + all[a[j]]) % Mod;
			int id = idof(val);
			dp[i][j] = 1;
			if(~id)
				dp[i][j] += sum[j][id];
			if(dp[i][j] >= Mod)
				dp[i][j] -= Mod;
			sum[i][a[j]] = (sum[i][a[j]] + dp[i][j]) % Mod;
			ans = (ans + dp[i][j]) % Mod;
		}
	ans -= n * (n - 1) / 2;
	ans = ans % Mod + Mod;
	ans %= Mod;
	cout << ans << endl;
	return 0;
}
