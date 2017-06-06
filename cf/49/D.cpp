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

const int maxn = 10000;
int dp[maxn][2],
	n;
string s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n
		>> s;
	memset(dp, 63, sizeof dp);
	dp[0][0] = 0;
	for(int i = 1; i < n; i++){
		if(i & 1){
			smin(dp[i][0], dp[i - 1][0] + 1);
			smin(dp[i][1], min(dp[i - 1][0], dp[i - 1][1] + 1));
		}
		else{
			smin(dp[i][0], min(dp[i - 1][1], dp[i - 1][0] + 1));
			smin(dp[i][1], dp[i - 1][1] + 1);
		}
	}
	cout << dp[1][1] << endl;
	int ans = min(dp[n - 1][0], dp[n - 1][1]);
	cout << ans << endl;
	memset(dp, 63, sizeof dp);
	dp[0][1] = 0;
	for(int i = 1; i < n; i++){
		if(i & 1 ^ 1){
			smin(dp[i][0], dp[i - 1][0] + 1);
			smin(dp[i][1], min(dp[i - 1][0], dp[i - 1][1] + 1));
		}
		else{
			smin(dp[i][0], min(dp[i - 1][1], dp[i - 1][0] + 1));
			smin(dp[i][1], dp[i - 1][1] + 1);
		}
	}
	smin(ans, min(dp[n - 1][0], dp[n - 1][1]));
	cout << ans << endl;
	return 0;
}
