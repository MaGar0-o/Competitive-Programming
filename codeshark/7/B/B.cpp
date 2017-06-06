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

const int maxn = 1001;
const LL Mod = 14947;
LL dp[maxn][maxn],
   su[maxn][maxn];
int n = 1;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	su[0][0] = dp[0][0] = 1;
	for(int i = 0; i <= n; i++)
		for(int j = (i == 0); j <= n; j++){
			if(i) dp[i][j] += su[i - 1][j];
			if(j) dp[i][j] += su[i][j - 1];
			if(i and j) dp[i][j] -= su[i - 1][j - 1];
			dp[i][j] %= Mod;
			su[i][j] = dp[i][j];
			if(i) su[i][j] += su[i - 1][j];
			if(j) su[i][j] += su[i][j - 1];
			if(i and j) su[i][j] -= su[i - 1][j - 1];
			su[i][j] %= Mod;
		}
	cout << (dp[n][n]+Mod)%Mod << endl;
	return 0;
}
