//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double LD;
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

const int maxn = 200 + 10;
LD dp[maxn][maxn][maxn],
   pd[maxn][maxn],
   p[maxn];
int a[maxn];
int n, l, bag;
vector<int> vec[2];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> l >> bag;
	for(int i = 0; i < n; i++)
		cin >> p[i], p[i] /= 100.;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		vec[a[i] != -1].PB(i);
	}
	//calc_dp();
	dp[0][0][bag] = 1;
	for(int i = 0; i < sz(vec[0]); i++)
		for(int j = 0; j <= i; j++)
			for(int k = 0; k <= 200; k++){
				dp[i + 1][j][k] += dp[i][j][k] * (1 - p[vec[0][i]]);
				dp[i + 1][j + 1][min(200, k + a[vec[0][i]])] += dp[i][j][k] * p[vec[0][i]];
			}
	int n1 = sz(vec[0]);
	for(int j = n1; j >= 0; j--)
		for(int k = 200; k >= 0; k--)
			dp[n1][j][k] += dp[n1][j + 1][k] + dp[n1][j][k + 1] - dp[n1][j + 1][k + 1];
	//calc_pd();
	pd[0][0] = 1;
	for(int i = 0; i < sz(vec[1]); i++)
		for(int j = 0; j <= i; j++){
			pd[i + 1][j] += pd[i][j] * (1 - p[vec[1][i]]);
			pd[i + 1][j + 1] += pd[i][j] * p[vec[1][i]];
		}
	int n2 = sz(vec[1]);
	LD ans = 0;
	for(int j = 0; j <= n2; j++)
		ans += pd[n2][j] * dp[n1][max(0, l - j)][j];
	cout << ans << '\n';
	return 0;
}
