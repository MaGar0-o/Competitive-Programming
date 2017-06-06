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

const int maxn = 19;
int mat[maxn][maxn];
LL dp[1 << maxn][maxn];
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		mat[fi][se] = mat[se][fi] = true;
	}
	for(int i = 0; i < n; i++)
		dp[1<<i][i] = 1;
	for(int mask = 1; mask < (1 << n); mask++) if(__builtin_popcount(mask))
		for(int i = 0, sou = __builtin_ctz(mask); i < n; i++) if(((mask >> i) & 1) and i != sou)
			for(int j = 0; j < n; j++) if(((mask >> j) & 1) and mat[i][j])
				dp[mask][i] += dp[mask ^ (1 << i)][j];
	LL ans = 0;
	for(int mask = 0; mask < (1 << n); mask++)
		if(__builtin_popcount(mask) > 2)
			for(int i = 0; i < n; i++){
				int sou = __builtin_ctz(mask);
				ans += mat[sou][i] * dp[mask][i];
			}
	ans >>= 1;
	cout << ans << '\n';
	return 0;
}
