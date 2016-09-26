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

const int n = 2;
const int maxn = n + 1;
const LL Mod = 10859;
LL dp[maxn][2];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	dp[1][0] = 2, dp[1][1] = 3;
	for(int i = 2; i <= n; i++){
		dp[i][0] = (2 * (dp[i - 1][0] + dp[i - 1][1])) % Mod;
		dp[i][1] = (3 * (dp[i - 1][0] + dp[i - 1][1])) % Mod;
	}
	LL sum = 0;
	for(int i = 1; i <= n; i++)
		sum = (sum + dp[i][1]) % Mod;
	LL sum2 = 1;
	for(int i = 0; i < n; i++)
		sum2 = (sum2 * 2) % Mod;
	sum2 *= sum2 - 1;
	sum2 /= 2;
	sum2 %= Mod;
	cout << (sum * sum2) % Mod << endl;
	return 0;
}
