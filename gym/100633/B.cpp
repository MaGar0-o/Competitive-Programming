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

const int maxn = 300 + 10,
	  D = 0,
	  Mod = 1e9 + 9;
int dp[2][maxn][maxn],
	n, d;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> d;
	dp[0][0][0] = 1;
	int cur = 1,
		nxt = 0;
	for(int i = 0; i <= n; i++){
		swap(cur, nxt);
		memset(dp[nxt], 0, sizeof dp[nxt]);
		for(int j = 0; j <= i; j++)
			for(int k = 0; k <= +i; k++){
				// (
				int &tmp1 = dp[nxt][max(j, k + 1)][k + 1] += dp[cur][j][k];
				tmp1 %= Mod;
				// 0
				int &tmp2 = dp[nxt][j][k] += dp[cur][j][k];
				tmp2 %= Mod;
				// )
				if(k){
					int &tmp3 = dp[nxt][j][k - 1] += dp[cur][j][k];
					tmp3 %= Mod;
				}
			}
	}
	cout << dp[cur][d][0] << '\n';
	return 0;
}
