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

const int maxn = 1000 + 85 - 69;
LL a[maxn];
LL sum[maxn];
LL dp[maxn][maxn];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i], sum[i] = sum[i - 1] + a[i];
	LL each = sum[n] / n;
	dp[0][0] = 0;
	for(int i = 1; i <= n; i++){
		dp[i][0] = dp[i - 1][0] + abs(i * each - sum[i]);
		for(int j = 1; j < i; j++)
			dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + abs(i * each + j - sum[i]);
		dp[i][i] = dp[i - 1][i - 1] + abs(i * each + i - sum[i]);
	}
	cout << dp[n][sum[n] % n] << endl;
	return 0;
}
