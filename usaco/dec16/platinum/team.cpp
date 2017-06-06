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

const int maxn = 1000 + 1,
	  maxk = 10 + 1;
const LL Mod = 1e9 + 9;
LL dp[maxk][maxn][maxn];
int a[maxn],
	b[maxn],
	n, m, K;

int main(){
	ifstream cin("team.in");
	ofstream cout("team.out");
	cin >> n >> m >> K;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < m; i++)
		cin >> b[i];
	sort(a, a + n);
	sort(b, b + m);
	dp[0][0][0] = 1;
	for(int i = 0; i <= K; i++)
		for(int j = 0; j <= n; j++)
			for(int k = 0; k <= m; k++){
				dp[i][j][k] %= Mod;
				if(j < n) dp[i][j + 1][k] += dp[i][j][k];
				if(k < m) dp[i][j][k + 1] += dp[i][j][k];
				if(j < n and k < m) dp[i][j + 1][k + 1] -= dp[i][j][k];
				if(i < K and j < n and k < m and a[j] > b[k])
					dp[i + 1][j + 1][k + 1] += dp[i][j][k];
			}
	dp[K][n][m] %= Mod;
	cout << (dp[K][n][m]+Mod) %Mod << '\n';
	return 0;
}
