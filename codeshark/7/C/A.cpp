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

const LL Mod = 14947;
LL dp[2][20000][2];

LL Pow(LL x, LL y){
	LL ret = 1, an = x;
	while(y){
		if(y & 1) ret = (ret * an) % Mod;
		an = (an * an) % Mod;
		y>>=1;
	}
	return ret;
}

LL Div(LL x, LL y){
	return (x * Pow(y, Mod - 2)) % Mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n = 12345;
	dp[0][0][0] = 1;
	for(int i = 1; i <= n; i++){
		int ip = i&1^1;
		for(int j = i; j >= 0; j--){
			dp[i&1][j][1] = ((j ? dp[ip][j - 1][1] : 0) + (j + 1) * dp[i&1][j + 1][1] + dp[ip][j][0]) % Mod;
			dp[i&1][j][0] = (2 * dp[i&1][j][1] + (j + 1) * dp[i&1][j + 1][0]) % Mod;
		}
	}
	cout << Div(dp[n&1][0][0], 2) << endl;
	return 0;
}
