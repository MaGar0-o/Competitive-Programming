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

const int maxn = 200;
LL dp[maxn][maxn];
LL a[maxn],
   sum[maxn];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> n;
	memset(dp, 63, sizeof dp);
	for(int i = 0; i < n; i++)
		cin >> a[i], sum[i + 1] = sum[i] + a[i], dp[i][i] = 0;
	for(int len = 2; len <= n; len++){
		for(int i = 0; i < n; i++){
			for(int j = i; j + 1 <= i + len - 1; j++)
				smin(dp[i][i + len - 1], dp[i][j] + dp[j + 1][i + len - 1]);
			dp[i][i + len - 1] += sum[i + len] - sum[i];
		}
	}
	cout << dp[0][n - 1] << endl;
	return 0;
}
