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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cout << fixed << setprecision(4);
	while(cin >> n and n){
		long double p[n];
		int c[n], sum = 0;
		for(int i = 0; i < n; i++)
			cin >> p[i] >> c[i], sum += c[i];
		long double dp[n + 1][sum + 1];
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= sum; j++)
				dp[i][j] = 0;
		dp[0][0] = 1;
		for(int i = 0; i < n; i++){
			for(int j = 0; j <= sum; j++){
				dp[i + 1][j] += dp[i][j] * (1. - p[i]);
				if(j + c[i] <= sum)
					dp[i + 1][j + c[i]] += dp[i][j] * p[i];
			}
		}
		long double ans = 0;
		for(int i = sum / 2 + 1; i <= sum; i++)
			ans += dp[n][i];
		cout << ans << '\n';
	}
	return 0;
}
