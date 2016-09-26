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

const int maxn = 2000 + 85 - 69;
const LL Mod = 1e9 + 7;
LL P[maxn],
   c[maxn][maxn],
   dp[maxn];
int n;

LL Pow(LL x, LL y){
	LL an = x,
	   ret = 1;
	while(y){
		if(y&1) ret = (ret * an) % Mod;
		an = (an * an) % Mod;
		y>>=1;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	c[0][0] = 1;
	for(int i = 1; i < maxn; i++){
		c[i][0] = 1;
		for(int j = 1; j <= i; j++){
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			if(c[i][j] >= Mod) c[i][j] -= Mod;
		}
	}
	cin >> n;
	for(LL i = 0; i <= n; i++)
		P[i] = Pow(2, c[i][2]);
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < i; j++)
			dp[i] = (dp[i] - ((((c[i - 1][j - 1] * dp[j]) % Mod) * P[i-j]) % Mod)) % Mod;
		dp[i] = (dp[i] + P[i]) % Mod;
	}
	cout << (dp[n]+Mod) % Mod << endl;
	return 0;
}
