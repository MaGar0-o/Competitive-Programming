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

const int maxn = 100,
	  maxm = 16,
	  maxmax = 1 << 16;
int dp[maxmax],
	a[maxn][maxn],
	sum[maxn][maxmax],
	d[maxn],
	n, m,
	func[maxmax];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> d[i];
		for(int j = 0; j < m; j++)
			cin >> a[i][j], sum[i][1 << j] = a[i][j];
		for(int mask = 0; mask < (1 << m); mask++)
			if(mask & (mask - 1))
				sum[i][mask] = sum[i][mask & -mask] + sum[i][mask - (mask & -mask)];
	}
	for(int mask = 0; mask < (1 << m); mask++)
		for(int i = 0; i < n; i++)
			if(d[i] + sum[i][mask] < d[func[mask]] + sum[func[mask]][mask])
				func[mask] = i;
	memset(dp, 63, sizeof dp);
	dp[0] = 0;
	for(int mask = 1; mask < (1 << m); mask++)
		for(int mask2 = mask; mask2; mask2 = mask & (mask2 - 1))
			smin(dp[mask], sum[func[mask2]][mask2] + dp[mask - mask2] + d[func[mask2]]);
	cout << dp[(1 << m) - 1] << endl;
	return 0;
}
